
// 2017212104TCPClientDlg.cpp: 实现文件
//

#include "2017212104TCPClientDlg.h"
#include "2017212104TCPClient.h"
#include "RC4.h"
#include "afxdialogex.h"
#include "stdafx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define DEFAULT_PORT 2000  //服务器监听端口，注意与服务器端保持一致
char* CSt2char(CString str) {
    //注意：以下n和len的值大小不同,n是按字符计算的，len是按字节计算的
    int n = str.GetLength();  // n = 14, len = 18
    //获取宽字节字符的大小，大小是按字节计算的
    int len = WideCharToMultiByte(CP_ACP, 0, str, str.GetLength(), NULL, 0,
                                  NULL, NULL);
    //为多字节字符数组申请空间，数组大小为按字节计算的宽字节字节大小
    char* buff = new char[len + 1];  //以字节为单位
    //宽字节编码转换成多字节编码
    WideCharToMultiByte(CP_ACP, 0, str, str.GetLength() + 1, buff, len + 1,
                        NULL, NULL);
    buff[len + 1] = '\0';  //多字节字符以'/0'结束
    return buff;
}
CString char2CSt(char* szBuf) {
    //计算char *数组大小，以字节为单位，一个汉字占两个字节
    int charLen = strlen(szBuf);
    //计算多字节字符的大小，按字符计算。
    int len = MultiByteToWideChar(CP_ACP, 0, szBuf, charLen, NULL, 0);
    //为宽字节字符数组申请空间，数组大小为按字节计算的多字节字符大小
    TCHAR* buf = new TCHAR[len + 1];
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

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx {
   public:
    CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUTBOX };
#endif

   protected:
    virtual void DoDataExchange(CDataExchange* pDX);  // DDX/DDV 支持

    // 实现
   protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) {}

void CAboutDlg::DoDataExchange(CDataExchange* pDX) {
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CMy2017212104TCPClientDlg 对话框

CMy2017212104TCPClientDlg::CMy2017212104TCPClientDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_MY2017212104TCPCLIENT_DIALOG, pParent),
      m_strSendMessage(_T("研究所呼叫勘探队！研究所呼叫勘探队！请回答..")),
      m_strRecvMessage(_T("")) {
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2017212104TCPClientDlg::DoDataExchange(CDataExchange* pDX) {
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_IPADDRESS_SERVER, ServerIP);
    DDX_Text(pDX, IDC_EDIT_MESSAGE, m_strSendMessage);
    DDX_Text(pDX, IDC_STATIC_RECV, m_strRecvMessage);
}

BEGIN_MESSAGE_MAP(CMy2017212104TCPClientDlg, CDialogEx)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDCANCEL, &CMy2017212104TCPClientDlg::OnBnClickedCancel)
ON_BN_CLICKED(IDC_BUTTON_SEND,
              &CMy2017212104TCPClientDlg::OnBnClickedButtonSend)
END_MESSAGE_MAP()

// CMy2017212104TCPClientDlg 消息处理程序

BOOL CMy2017212104TCPClientDlg::OnInitDialog() {
    CDialogEx::OnInitDialog();

    // 将“关于...”菜单项添加到系统菜单中。

    // IDM_ABOUTBOX 必须在系统命令范围内。
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
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
    WSADATA wsaData;  //结构被用来保存函数 WSAStartup 返回的 Windows Socket
                      //初始化信息
    if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0) {
        AfxMessageBox(_T("WSAStartup error！"));
        return FALSE;
    }

    ServerIP.SetAddress(192, 168, 32, 1);
    UpdateData(FALSE);

    return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy2017212104TCPClientDlg::OnSysCommand(UINT nID, LPARAM lParam) {
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

void CMy2017212104TCPClientDlg::OnPaint() {
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
HCURSOR CMy2017212104TCPClientDlg::OnQueryDragIcon() {
    return static_cast<HCURSOR>(m_hIcon);
}

void CMy2017212104TCPClientDlg::OnBnClickedCancel() {
    // TODO: 在此添加控件通知处理程序代码
    WSACleanup();  //释放资源
    CDialogEx::OnCancel();
}

void CMy2017212104TCPClientDlg::OnBnClickedButtonSend() {
    // TODO: 在此添加控件通知处理程序代码
    sockaddr_in local;
    local.sin_family =
        AF_INET;  //必须是AF_INET,表示该socket在Internet域中进行通信
    local.sin_port = htons(DEFAULT_PORT);  //端口号

    char IPAddress[MAX_PATH];
    BYTE add1, add2, add3, add4;
    ServerIP.GetAddress(add1, add2, add3, add4);
    sprintf_s(IPAddress, "%d.%d.%d.%d", add1, add2, add3, add4);
    local.sin_addr.S_un.S_addr = inet_addr(IPAddress);  //服务器的IP地址。

    SOCKET socketTmp =
        socket(AF_INET, SOCK_STREAM, 0);  ///初始化Socket，与服务器端保持一致
    if (connect(socketTmp, (LPSOCKADDR)&local, sizeof(local)) !=
        0)  //连接服务器
    {
        closesocket(socketTmp);
        AfxMessageBox(_T("连接服务器失败"));
        return;
    }

    char szText[MAX_PATH];  //数据缓冲区
    memset(szText, 0, MAX_PATH);
    // 启动界面消息可更改状态
    UpdateData(TRUE);

    // 获取发送框的消息，并进行发送

    // 获取明文并且加密
    char* tmp = RC4_solve(CSt2char(m_strSendMessage));

    // 把密文显示在客户端的下面框中
    m_strRecvMessage = char2CSt(tmp);
    //刷新界面
    UpdateData(FALSE);

    // 写入密文并且发送给服务器
    sprintf_s(szText, "%s", tmp);
    send(socketTmp, szText, sizeof szText, 0);  //发送消息

    memset(szText, 0, MAX_PATH);  //清空缓冲区

    // 不再读取服务器消息了
    // if (recv(socketTmp, szText, sizeof szText, 0) !=
    // SOCKET_ERROR)//读取服务器端返回的数据
    //{
    //	m_strRecvMessage = char2CSt(szText);
    //	UpdateData(FALSE);//刷新界面
    //}

    shutdown(socketTmp, 2);  //关闭读写通道
    closesocket(socketTmp);
}
