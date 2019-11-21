
// 2017212104TCPServerDlg.cpp: 实现文件
//

#include "2017212104TCPServerDlg.h"
#include "2017212104TCPServer.h"
#include "RC4.h"
#include "afxdialogex.h"
#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define DEFAULT_PORT 2000  //服务器监听端口
SOCKET m_Listening;        //监听socket
HANDLE m_hListenThread;    //线程句柄

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx {
   public:
    CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUTBOX };
#endif

   protected:
    virtual void DoDataExchange(CDataExchange *pDX);  // DDX/DDV 支持

    // 实现
   protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) {}

void CAboutDlg::DoDataExchange(CDataExchange *pDX) {
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CMy2017212104TCPServerDlg 对话框
CMy2017212104TCPServerDlg::CMy2017212104TCPServerDlg(CWnd *pParent /*=nullptr*/)
    : CDialogEx(IDD_MY2017212104TCPSERVER_DIALOG, pParent) {
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2017212104TCPServerDlg::DoDataExchange(CDataExchange *pDX) {
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_IPADDRESS_HOST, HostIP);
    DDX_Control(pDX, IDC_BUTTON_START, m_btnStart);
    DDX_Control(pDX, IDC_BUTTON_STOP, m_btnStop);
    DDX_Control(pDX, IDC_EDIT_MESSAGE, m_edtMessage);
    DDX_Control(pDX, IDC_LIST_SHOW, m_list);
}

BEGIN_MESSAGE_MAP(CMy2017212104TCPServerDlg, CDialogEx)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDCANCEL, &CMy2017212104TCPServerDlg::OnBnClickedCancel)
ON_BN_CLICKED(IDC_BUTTON_START,
              &CMy2017212104TCPServerDlg::OnBnClickedButtonStart)
ON_BN_CLICKED(IDC_BUTTON_STOP,
              &CMy2017212104TCPServerDlg::OnBnClickedButtonStop)
END_MESSAGE_MAP()

// ------------ 自己的全局函数 -------------
char *CSt2char(CString str) {
    //注意：以下n和len的值大小不同,n是按字符计算的，len是按字节计算的
    int n = str.GetLength();  // n = 14, len = 18
    //获取宽字节字符的大小，大小是按字节计算的
    int len = WideCharToMultiByte(CP_ACP, 0, str, str.GetLength(), NULL, 0,
                                  NULL, NULL);
    //为多字节字符数组申请空间，数组大小为按字节计算的宽字节字节大小
    char *buff = new char[len + 1];  //以字节为单位
    //宽字节编码转换成多字节编码
    WideCharToMultiByte(CP_ACP, 0, str, str.GetLength() + 1, buff, len + 1,
                        NULL, NULL);
    buff[len + 1] = '\0';  //多字节字符以'/0'结束
    return buff;
}
CString char2CSt(char *szBuf) {
    //计算char *数组大小，以字节为单位，一个汉字占两个字节
    int charLen = strlen(szBuf);
    //计算多字节字符的大小，按字符计算。
    int len = MultiByteToWideChar(CP_ACP, 0, szBuf, charLen, NULL, 0);
    //为宽字节字符数组申请空间，数组大小为按字节计算的多字节字符大小
    TCHAR *buf = new TCHAR[len + 1];
    //多字节编码转换成宽字节编码
    MultiByteToWideChar(CP_ACP, 0, szBuf, charLen, buf, len);
    buf[len] = '\0';  //添加字符串结尾，注意不是len+1
    //将TCHAR数组转换为CString
    CString pWideChar;
    pWideChar.Append(buf);
    //删除缓冲区
    delete[] buf;
    return pWideChar;
}

CString GetCurTime() {
    SYSTEMTIME sysTime;
    ZeroMemory(&sysTime, sizeof(sysTime));
    GetLocalTime(&sysTime);  //获取当前系统时间

    CString str;
    str.Format(_T("%d年%d月%d日%d时%d分%d秒"), sysTime.wYear, sysTime.wMonth,
               sysTime.wDay, sysTime.wHour, sysTime.wMinute,
               sysTime.wSecond);  //转换为字符串形式

    Sleep(1000);

    return str;
}

// 服务器的监听线程，也就是一直在这里开始处理客户端的所有请求
DWORD WINAPI ListenThread(LPVOID lpparam) {
    CMy2017212104TCPServerDlg *pDlg = (CMy2017212104TCPServerDlg *)lpparam;
    if (pDlg == NULL) return 0;  //获取当前主对话框的指针
    SOCKET ConnectSocket;        //记录捕捉到的连接
    sockaddr_in ClientAddr;      //记录数据包的IP地址
    int nLen = sizeof(sockaddr);

    //开始监听是否有客户端连接。
    if (listen(m_Listening, 40) == SOCKET_ERROR) {
        return 0;
    }

    char szBuf[MAX_PATH];        //数据缓冲区
    memset(szBuf, 0, MAX_PATH);  //初始化缓冲区

    while (1) {
        ConnectSocket =
            accept(m_Listening, (sockaddr *)&ClientAddr,
                   &nLen);  //阻塞直到有客户端连接，不然多浪费CPU资源
        char *pAddrname = inet_ntoa(ClientAddr.sin_addr);  //得到客户端的IP地址
        memset(szBuf, 0, MAX_PATH);  //每次接收数据前清空缓冲区
        if (recv(ConnectSocket, szBuf, sizeof szBuf, 0) != SOCKET_ERROR) {
            // 解密消息并且显示
            char *tmp = RC4_dissolve(szBuf);
            pDlg->m_edtMessage.SetWindowTextW(char2CSt(tmp));

            // 将消息插入数据库并更新展示
            // if
            // (!CMy2017212104TCPServerDlg::InsertData(CSt2char(GetCurTime()),
            // pAddrname, tmp)） {

            /*CString str;
            str.Format(_T("time:%s"), GetCurTime());
            AfxMessageBox(str);*/

            pDlg->InsertData(CSt2char(GetCurTime()), pAddrname, tmp);

            /*char buff[MAX_PATH] = "我是勘探队，我是勘探队，收到请回答！(";
            strcat_s(buff, pAddrname);
            strcat_s(buff, "）");*/

            // 服务器不用再传输消息给客户端了
            // send(ConnectSocket, buff, strlen(buff)+1, 0);
        }
    }

    return 0;
}
// ------------ 自己的全局函数结束 ---------------

// CMy2017212104TCPServerDlg 消息处理程序

BOOL CMy2017212104TCPServerDlg::OnInitDialog() {
    CDialogEx::OnInitDialog();

    // 将“关于...”菜单项添加到系统菜单中。

    // IDM_ABOUTBOX 必须在系统命令范围内。
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu *pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != nullptr) {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
        ASSERT(bNameValid);
        if (!strAboutMenu.IsEmpty()) {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
    //  执行此操作
    SetIcon(m_hIcon, TRUE);   // 设置大图标
    SetIcon(m_hIcon, FALSE);  // 设置小图标

    // TODO: 在此添加额外的初始化代码
    // 结构被用来保存函数WSAStartup返回的Windows Socket 初始化信息
    WSADATA wsaData;
    /*当一个应用程序调用WSAStartup函数时，
    操作系统根据请求的Socket版本来搜索相应的Socket
    库，然后绑定找到的Socket库到该应用程序中
    表示要使用1.1版本的Socket */
    if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0) {
        AfxMessageBox(_T("WSAStartup error！"));
        return FALSE;
    }

    GetLocalIP();

    // list的初始化
    m_list.InsertColumn(0, _T("时间"), LVCFMT_LEFT, 200);
    m_list.InsertColumn(1, _T("IP地址"), LVCFMT_LEFT, 100);
    m_list.InsertColumn(2, _T("消息"), LVCFMT_LEFT, 180);
    // 选择节点的时 候选中整行
    m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    //初始化MYSQL对象
    mysql_init(&m_mysql);
    mysql_options(&m_mysql, MYSQL_SET_CHARSET_NAME,
                  "gb2312");  //设置客户端支持中文 字符集
    // 连接MYSQL后台数据库
    if (!mysql_real_connect(&m_mysql, "localhost", "root", "root",
                            "tcp_client_information", 3306, NULL, 0)) {
        MessageBoxW(_T("数据库连接失败!"));
        return FALSE;
    }
    // 后面其实可以去掉的，没有什么大用
    // else MessageBoxW(_T("数据库连接成功!"));

    return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy2017212104TCPServerDlg::OnSysCommand(UINT nID, LPARAM lParam) {
    if ((nID & 0xFFF0) == IDM_ABOUTBOX) {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    } else {
        CDialogEx::OnSysCommand(nID, lParam);
    }
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy2017212104TCPServerDlg::OnPaint() {
    if (IsIconic()) {
        CPaintDC dc(this);  // 用于绘制的设备上下文

        SendMessage(WM_ICONERASEBKGND,
                    reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // 使图标在工作区矩形中居中
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // 绘制图标
        dc.DrawIcon(x, y, m_hIcon);
    } else {
        CDialogEx::OnPaint();
    }
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy2017212104TCPServerDlg::OnQueryDragIcon() {
    return static_cast<HCURSOR>(m_hIcon);
}

void CMy2017212104TCPServerDlg::OnBnClickedCancel() {
    // TODO: 在此添加控件通知处理程序代码
    WSACleanup();  //释放资源
    CDialogEx::OnCancel();
}

void CMy2017212104TCPServerDlg::GetLocalIP() {
    // TODO: 在此处添加实现代码.
    char HostName[128];                   //记录主机名
    char *IPAddress;                      //记录IP地址
    if (gethostname(HostName, 128) == 0)  //获取主机名成功
    {
        struct hostent *pHost;
        pHost = gethostbyname(HostName);  //用域名或主机名获取IP地址
        IPAddress = pHost->h_addr_list[0];  //取第一个地址
        HostIP.SetAddress(*IPAddress, *(IPAddress + 1), *(IPAddress + 2),
                          *(IPAddress + 3));  //设置IP地址
        UpdateData(FALSE);                    //刷新界面
    }
}

// 启动服务后的程序
void CMy2017212104TCPServerDlg::OnBnClickedButtonStart() {
    // TODO: 在此添加控件通知处理程序代码
    sockaddr_in local;  //使用sockaddr_in结构指定IP地址和端口信息
    local.sin_family = AF_INET;
    //设置的端口为DEFAULT_PORT。将整型变量从主机字节顺序转变成网络字节顺序
    local.sin_port = htons(DEFAULT_PORT);
    char IPAddress[MAX_PATH];  //记录IP地址
    BYTE add1, add2, add3, add4;
    HostIP.GetAddress(add1, add2, add3, add4);
    sprintf_s(IPAddress, "%d.%d.%d.%d", add1, add2, add3, add4);
    local.sin_addr.S_un.S_addr =
        inet_addr(IPAddress);  //将一个点分十进制的IP转换成一个长整数型数(u_long类型),
                               //返回的整数形式是网络字节序
    m_Listening = socket(AF_INET, SOCK_STREAM,
                         0);  //初始化Socket，采用TCP方式-SOCK_STREAM
    if (m_Listening == INVALID_SOCKET)  //创建失败
    {
        AfxMessageBox(_T("初始化socket失败！"));
        return;
    }
    if (bind(m_Listening, (LPSOCKADDR)&local, sizeof(local)) ==
        SOCKET_ERROR)  //将IP地址和端口绑定到所创建的套接字上
    {
        AfxMessageBox(_T("绑定失败！"));
        closesocket(m_Listening);
        return;
    }

    //创建监听线程
    DWORD dwThreadID = 0;
    m_hListenThread = ::CreateThread(
        NULL, 0, ListenThread, this, 0,
        &dwThreadID);  // ListenThread为线程函数，this为当前主对话框的指针

    m_btnStart.EnableWindow(FALSE);
    m_btnStop.EnableWindow(TRUE);
}

void CMy2017212104TCPServerDlg::OnBnClickedButtonStop() {
    // TODO: 在此添加控件通知处理程序代码
    TerminateThread(m_hListenThread, 0);  //关闭线程
    CloseHandle(m_hListenThread);         //释放资源
    shutdown(m_Listening, 2);             //关闭读写通道
    closesocket(m_Listening);             //释放socket
}

// 展示数据
void CMy2017212104TCPServerDlg::ShowData() {
    // TODO: 在此处添加实现代码.
    m_list.DeleteAllItems();  //清空原有数据
    char sql[100];
    sprintf_s(sql, "select * from information");  //设计sql语言
    if (mysql_real_query(&m_mysql, sql,
                         (unsigned long)strlen(sql)))  //执行sql语言
    {
        MessageBoxW(_T("读取表格失败"));
        return;
    }

    MYSQL_RES *result;
    MYSQL_ROW row;

    if (!(result = mysql_use_result(&m_mysql)))  //获取数据
    {
        MessageBoxW(_T("读取数据集失败"));
        return;
    }

    int i = 0;
    while (
        row = mysql_fetch_row(result)) {  //第一步是取数据，第二步是判断是否为空
        m_list.InsertItem(i, char2CSt(row[0]));

        if (row[1] == NULL)
            m_list.SetItemText(i, 1, _T("NULL"));
        else
            // 上面是插入Insert，下面是Set
            m_list.SetItemText(i, 1, char2CSt(row[1]));

        if (row[2] == NULL)
            m_list.SetItemText(i, 2, _T("NULL"));
        else
            m_list.SetItemText(i, 2, char2CSt(row[2]));

        i++;
    }
    mysql_free_result(result);  //释放资源
}

// 插入数据
bool CMy2017212104TCPServerDlg::InsertData(char *time, char *ip, char *info) {
    // TODO: 在此处添加实现代码.
    char sql[1024];
    sprintf_s(sql, "insert into information values('%s','%s','%s')", time, ip,
              info);  //设计sql语言

    // 用下面这个测试了一下，发现错误就在Format不是正规的 char2CSt ...
    // 所以导致了大量的乱码...
    // CString str;
    // str.Format(_T("%s"), sql);
    // AfxMessageBox(str);

    if (mysql_real_query(&m_mysql, sql,
                         (unsigned long)strlen(sql)))  //执行sql语言
    {
        MessageBoxW(_T("添加数据失败"));
        return false;
    } else {
        ShowData();
    }
    return true;
}
