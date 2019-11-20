// UDP-Client.cpp : 定义控制台应用程序的入口点。
// Author: 单林敏 2017212104
// 2019年11月20日20:52:23 发现Google的代码风格+VScode的代码粘贴自带样式 ---> 搞到word上真好棒极了！

#include "stdafx.h"

#include <Winsock2.h>
#include <stdio.h>
#include <iostream>
#define MAX_FILENAME_LEN 1024
#define BUF_SIZE 1024
//#define BUF_SIZE 65535
using namespace std;
// 发现我确实要用链接器
//可能需要配置：链接器-》输入-》附加依赖项-》写入 ws2_32.lib
#pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll

int _tmain(int argc, _TCHAR* argv[]) {
    WORD wVersionRequested;

    WSADATA wsaData;

    wVersionRequested = MAKEWORD(2, 2);

    if (WSAStartup(wVersionRequested, &wsaData) !=
        0)  //初始化 ws2_32.dll 动态库
    {
        printf("WSAStartup() failed!\n");  // Winsock 初始化错误
        return 0;
    }

    if (wsaData.wVersion != wVersionRequested) {
        printf("The version of Winsock is not suited!\n");  // Winsock
                                                            // 版本不匹配
        WSACleanup();  //结束对 ws2_32.dll 的调用
        return 0;
    }

    //说明 ws2_32.dll 正确加载
    printf("Load ws2_32.dll successfully!\n");

    //创建套接字
    SOCKET servsock;
    printf("Create Socket...\n");
    servsock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);  //数据报套接字

    int servport = 5555;
    int iSockErr = 0;

    //定义服务器地址结构
    sockaddr_in udpaddr;
    int len = sizeof(udpaddr);
    memset(&udpaddr, 0, sizeof(udpaddr));
    udpaddr.sin_family = AF_INET;
    udpaddr.sin_port = htons(servport);
    //将一个点分十进制 IP 地址字符串转换成 32 位数字表示的 IP 地址
    // udpaddr.sin_addr.s_addr = inet_addr("192.168.3.15");////INADDR_ANY
    udpaddr.sin_addr.s_addr = inet_addr("192.168.32.1");  ////INADDR_ANY

    char buffer[BUF_SIZE] = "\0";
    int nLen = sizeof sockaddr;

    bool test = 1;
    while (1) {
        memset(buffer, 0, sizeof(buffer));

        // test如果不睡眠，那么很有可能出现服务器还没有建立的尴尬处境
        Sleep(1000);
        if (test) {
            sprintf(buffer, "just a test");
            // buffer[strlen(buffer)] = '\0';
            printf("%s\n", buffer);
            printf("buffer 长为 %d\n", sizeof buffer);

            int ret = sendto(servsock, buffer, strlen(buffer), 0,
                             (struct sockaddr*)&udpaddr, len);
            // int ret = sendto(servsock, buffer, sizeof buffer, 0, (struct
            // sockaddr*)&udpaddr, len);
            printf("测试长度：%d\n", ret);

            test = 0;
            goto END;
        }

        printf("input message(q -退出，File -传送文件)\n");
        scanf_s("%s", buffer, 1024);

        // quit
        if (strcmp(buffer, "q") == 0) break;

        // File
        else if (strcmp(buffer, "File") == 0) {
            printf("请输入文件路径以及文件名：\n");
            char filename[MAX_FILENAME_LEN];

        READ_FILE_NAME:
            scanf("%s", filename);
            FILE* fp = fopen(filename, "rb");

            if (fp == NULL) {
                printf(
                    "无法打开文件，请检查文件路径是否正确，是否是双反斜杠，按q"
                    "退出，按其他键再次尝试\n");
                char tp;
                scanf("%c", &tp);
                if (tp == 'q') {
                    system("pause");
                    exit(0);
                } else {
                    goto READ_FILE_NAME;
                }
            }

            //这里的buffer是局部变量
            char buffer[BUF_SIZE] = "发送文件";  //缓冲区

            // 发送提醒
            if (sendto(servsock, buffer, strlen(buffer), 0,
                       (struct sockaddr*)&udpaddr, len) != SOCKET_ERROR) {
                memset(buffer, 0, sizeof(buffer));

                // 等待客户端准备好
                if (recvfrom(servsock, buffer, sizeof buffer, 0,
                             (struct sockaddr*)&udpaddr,
                             &nLen) != SOCKET_ERROR) {
                    // 客户端准备好了
                    if (strcmp(buffer, "I'm ready!") == 0) {
                        //循环发送数据，直到文件结尾
                        int nCount;
                        bool ok = 1;

                        while ((nCount = fread(buffer, 1, BUF_SIZE, fp)) > 0) {
                            if (ok) {
                                ok = 0;
                                puts("Oh,I send some imformation!");
                            }

                            int flag =
                                sendto(servsock, buffer, sizeof(buffer), 0,
                                       (struct sockaddr*)&udpaddr, len);

                            if (flag == SOCKET_ERROR || flag == 0) {
                                puts("Wrong");
                                return -1;
                            }

                            memset(buffer, 0, sizeof buffer);
                            Sleep(1);
                        }

                        // 传送结束数据包
                        sprintf(buffer, "finished");
                        buffer[strlen(buffer)] = '\0';
                        int ret = sendto(servsock, buffer, strlen(buffer), 0,
                                         (struct sockaddr*)&udpaddr, len);
                        printf("测试长度2：%d", ret);

                        if (ret == SOCKET_ERROR) {
                            cout << "wrong" << endl;
                            return -1;
                        } else {
                            cout << "send successful!" << endl;
                        }
                        fclose(fp);
                    }

                    // 客户端没有准备好
                    else
                        puts("异常：客户端未准备好");
                }

                continue;
            }

        }

        // 直接传输的字节码
        else if (sendto(servsock, buffer, strlen(buffer), 0,
                        (struct sockaddr*)&udpaddr, len) != SOCKET_ERROR) {
        END:
            puts("first test come?YES");
            memset(buffer, 0, sizeof(buffer));
            if (recvfrom(servsock, buffer, sizeof buffer, 0,
                         (struct sockaddr*)&udpaddr, &nLen) != SOCKET_ERROR)
                printf("Received datagram from UDP server:%s\n", buffer);
            else {
                puts("first send is too fast,so error and connitue");
            }
        }
    }

    //关闭连接
    shutdown(servsock, 2);
    closesocket(servsock);
    WSACleanup();

    return 0;
}
