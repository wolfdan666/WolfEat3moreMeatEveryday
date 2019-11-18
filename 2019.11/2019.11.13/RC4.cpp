#include<bits/stdc++.h>
// #include <iostream>
// #include <string>
// #include <string.h>
// #include <set>
// #include <assert.h>
typedef unsigned long ULONG;
using namespace std;
set<int> S;


void rc4_init(unsigned char* s, unsigned char* key, unsigned long Len) {
    int i = 0, j = 0;
    char k[256] = {0};
    unsigned char tmp = 0;
    for (i = 0; i < 256; i++) {
        s[i] = i;
        k[i] = key[i % Len];
    }
    /*用于打乱S盒，其中i循环用于保证S盒 每位都保证得到混淆*/ /*Key中每个字节的引入是为了增加随机因子*/
    for (i = 0; i < 256; i++) {
        j = (j + s[i] + k[i]) % 256;
        tmp = s[i];
        //交换s[i]和s[j]
        s[i] = s[j];
        s[j] = tmp;
    }
    for(int i = 0;i < 256;i++){
        assert(S.find(s[i])==S.end());
        S.insert(s[i]);
    }
}

void rc4_crypt(unsigned char* s, unsigned char* Data, unsigned long Len) {
    int i = 0, j = 0, t = 0;
    unsigned long k = 0;
    unsigned char tmp;
    for (k = 0; k < Len; k++) {
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        tmp = s[i];
        s[i] = s[j];
        //交换s[x]和s[y]
        s[j] = tmp;
        t = (s[i] + s[j]) % 256;
        Data[k] ^= s[t];
    }
}

// int _tmain(int argc, _TCHAR* argv[]) {
int main(int argc, char* argv[]) {
    unsigned char s[256] = {0}, s2[256] = {0};
    // S-box
    char key[256] = {"justfortest"};
    char pData[512] = "这是一个用来加密的数据 Data";
    unsigned long len = strlen(pData);
    int i;

    printf("pData=%s\n", pData);
    printf("key=%s,length=%d\n\n", key, (int)strlen(key));
    rc4_init(s, (unsigned char*)key, strlen(key));
    //已经完成了初始化
    printf("完成对S[i]的初始化，如下：\n\n");
    for (i = 0; i < 256; i++) {
        printf("%02X", s[i]);
        //%02X表示输出的16进制使用两个位置，如果只有一位的前面添0，比如15就输出0F
        if (i && (i + 1) % 16 == 0) putchar('\n');
    }
    printf("\n\n");
    for (i = 0; i < 256; i++)
    //用s2[i]暂时保留经过初始化的s[i]，很重要的！！！
    {
        s2[i] = s[i];
    }
    printf("已经初始化，现在加密:\n\n");
    rc4_crypt(s, (unsigned char*)pData, len);
    //加密
    printf("pData=%s\n\n", pData);
    printf("已经加密，现在解密:\n\n");
    // rc4_init(s,(unsignedchar*)key,strlen(key));//初始化密钥
    rc4_crypt(s2, (unsigned char*)pData, len);
    //解密
    printf("pData=%s\n\n", pData);

    system("pause");

    return 0;
}