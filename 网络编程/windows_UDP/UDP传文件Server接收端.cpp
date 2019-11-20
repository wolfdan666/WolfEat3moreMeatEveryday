// UDP-Server.cpp : 定义控制台应用程序的入口点。
// Author: 单林敏 2017212104

#include <Winsock2.h>
#include <stdio.h>
#include <iostream>
#include "stdafx.h"
#define MAX_FILENAME_LEN 1024
//#define BUF_SIZE 1000
#define BUF_SIZE 1024
using namespace std;

//可能需要配置：链接器-》输入-》附加依赖项-》写入 ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

int _tmain(int argc, _TCHAR *argv[]) {
    WORD wVersionRequested;

    WSADATA wsaData;

    wVersionRequested = MAKEWORD(2, 2);

    if (WSAStartup(wVersionRequested, &wsaData) !=
        0)  //初始化 ws2_32.dll 动态库
    {
        printf_s("WSAStartup() failed!\n");  // Winsock 初始化错误
        return 0;
    }

    if (wsaData.wVersion != wVersionRequested) {
        printf_s(
            "The version of Winsock is not suited!\n");  // Winsock 版本不匹配
        WSACleanup();  //结束对 ws2_32.dll 的调用
        return 0;
    }

    //说明 ws2_32.dll 正确加载
    printf_s("Load ws2_32.dll successfully!\n");

    //获取本机 IP 地址
    char PCname[100] = {""};
    char *IPaddress = NULL;
    gethostname(PCname, sizeof(PCname));
    printf_s("Local Hostname is %s.\n", PCname);

    struct hostent FAR *lpHostEnt = gethostbyname(PCname);
    if (lpHostEnt == NULL) {  //产生错误
        printf_s("gethostbyname failed!\n");
        return 0;
    }

    // 获取 IP 的具体值
    LPSTR lpAddr = lpHostEnt->h_addr_list[0];
    if (lpAddr) {
        struct in_addr inAddr;
        memmove(&inAddr, lpAddr, 4);

        //转换为标准格式
        IPaddress = inet_ntoa(inAddr);  //将一个 32 位数字表示的 IP
                                        //地址转换成点分十进制 IP 地址字符串
        if (sizeof(IPaddress) == 0)
            printf_s("get host IP failed!\n");
        else
            printf_s("Local HostIP is %s.\n", IPaddress);
    }

    //创建套接字
    SOCKET servsock;
    printf_s("Create Socket...\n");
    //数据报套接字 (unp 79页现学现用)
    servsock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    int servport = 5555;
    int iSockErr = 0;

    //定义服务器地址结构
    sockaddr_in udpaddr;  // cliaddr;
    memset(&udpaddr, 0, sizeof(udpaddr));
    // memset(&cliaddr, 0, sizeof(cliaddr));

    int udplen = sizeof(udpaddr);
    udpaddr.sin_family = AF_INET;
    udpaddr.sin_port = htons(servport);
    //将一个点分十进制 IP 地址字符串转换成 32 位数字表示的 IP 地址
    udpaddr.sin_addr.s_addr = inet_addr(IPaddress);  //"127.0.0.1"//INADDR_ANY

    //绑定套接字到服务器地址结构
    printf_s("Binding...\n");

    // 这个bind()卡了25mins,先跳过...2019年11月19日20:32:50 -->
    // sb用了中文逗号+确实有些地方不会
    // 这里没有指定ip，所以在套接字上有数据报的时候选择一个ip，这个ip来自客户端的SYN信号
    // 因为上面这个，傻逼了...... 其实Server已经分配了本机的ip...
    // 而不是那种用系统内核自动分配ip，客户端发送后，socket服务器自动确认ip的操作
    iSockErr = bind(servsock, (struct sockaddr *)&udpaddr, udplen);
    if (iSockErr == SOCKET_ERROR) {
        printf_s("Binding failed:%d\n",
                 WSAGetLastError());  //根据不同的错误类型进行不同 的处理
        return 0;
    }  //函数调用成功，进行其他处理

    // 发出去
    char buff[256] = "\0";
    // 收进来
    char buffer[BUF_SIZE] = "\0";

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        printf_s("waiting for message from others-------------\n");
        // recvfrom 的 倒数第二个参数是
        // 指向装有源地址的缓冲区(消息的源地址也就是另一端)
        if (recvfrom(servsock, buffer, sizeof buffer, 0,
                     (struct sockaddr *)&udpaddr, &udplen) != SOCKET_ERROR) {
            printf_s("Received datagram from UDP Client %s--%s\n",
                     inet_ntoa(udpaddr.sin_addr), buffer);

            // 接收到普通消息的处理
            if (strcmp(buffer, "发送文件") != 0) {
                memset(buff, 0, sizeof(buff));
                sprintf_s(buff, "Welcome you %s", inet_ntoa(udpaddr.sin_addr));
                ////给 cilent 发信息   , 这里的倒数第二个参数才是目的地
                sendto(servsock, buff, strlen(buff), 0,
                       (struct sockaddr *)&udpaddr, udplen);
            }

            // 发文件
            // 可以扩展出接收到原文件名...strcpy,以及判断前4个字符等
            else {
                // 请求保存的位置
                puts("请输入接收文件的路径和名称：");

                char filename[MAX_FILENAME_LEN];
                scanf("%s", filename);

                FILE *fp =
                    fopen(filename, "wb");  //以二进制方式打开（创建）文件
                if (fp == NULL) {
                    printf("Cannot open file, press any key to exit!\n");
                    system("pause");
                    exit(0);
                }

                // 先发送ok状态提醒那边准备传输，这边立马开始处于接收状态，这样就不会丢失数据了
                memset(buff, 0, sizeof(buff));
                sprintf_s(buff, "I'm ready!");
                sendto(servsock, buff, strlen(buff), 0,
                       (struct sockaddr *)&udpaddr, udplen);

                //循环接收数据，直到文件传输完毕
                char buffer[BUF_SIZE] = {0};  //文件缓冲区
                int nCount;
                bool ok = 1;
                int k = 0;
                while ((nCount = recvfrom(servsock, buffer, sizeof buffer, 0,
                                          (struct sockaddr *)&udpaddr,
                                          &udplen)) > 0) {
                    if (nCount == INVALID_SOCKET || nCount == 0) {
                        cout << "Receive Error" << endl;
                        return -1;
                    }

                    // 判断是否结束
                    if (strcmp(buffer, "finished") == 0) {
                        fclose(fp);
                        printf("接收文件成功\n");
                        break;
                    }

                    // 写入
                    int flag = fwrite(buffer, sizeof(char), nCount, fp);

                    if (flag < nCount) {
                        cout << filename << "Write Failed" << endl;
                        break;
                    }
                    printf("I get data the %d time(s)\n", ++k);
                    // 可能因为等待数据包多了再发送的问题,导致得不到纯净的这一串字符！
                    if (strcmp(buffer, "finished,please close") == 0) {
                        puts("File transfer success!");

                        fclose(fp);
                        break;
                    }

                    memset(buffer, 0, sizeof buffer);
                }
                puts("I get out");
            }

        } else {
            puts("recvfrom error");
        }
        Sleep(500);
    }

    //关闭连接
    shutdown(servsock, 2);
    closesocket(servsock);
    WSACleanup();

    return 0;
}