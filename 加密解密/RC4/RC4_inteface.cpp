#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
typedef unsigned longULONG;
/*初始化函数*/
void rc4_init(unsigned char *s, unsigned char *key, unsigned long Len){
    int i = 0, j = 0;
    char k[256] = {0};
    unsigned char tmp = 0;
    for (i = 0; i < 256; i++){
        s[i] = i;
        k[i] = key[i % Len];
    }
    /*用于打乱S盒，其中i循环用于保证S盒每位都保证得到混淆*/
    /*Key中每个字节的引入是为了增加随机因子*/
    for (i = 0; i < 256; i++){
        j = (j + s[i] + k[i]) % 256;
        tmp = s[i];
        //交换s[i]和s[j]
        s[i] = s[j];
        s[j] = tmp;
    }
}

/*加解密*/
void rc4_crypt(unsigned char *s, unsigned char *Data, unsigned long Len){
    int i = 0, j = 0, t = 0;
    unsigned long k = 0;
    unsigned char tmp;
    for (k = 0; k < Len; k++){
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        tmp = s[i];
        //交换s[x]和s[y]
        s[i] = s[j];
        s[j] = tmp;
        t = (s[i] + s[j]) % 256;
        Data[k] ^= s[t];
    }
}

char * RC4_solve(char *pData){
    unsigned char s[256] = {0}, s2[256] = {0};
    char key[256] = {"justfortest"};

    unsigned long len = strlen(pData);
    int i;
    rc4_init(s, (unsigned char *)key, strlen(key));

    //用s2[i]暂时保留经过初始化的s[i]，很重要的！！！
    for (i = 0; i < 256; i++){
        s2[i] = s[i];
    }

    //加密
    rc4_crypt(s, (unsigned char *)pData, len);
    printf("pData=%s\n\n", pData);
    printf("已经加密，现在解密:\n\n");

    return pData;
}

int RC4_dissolve(char *pData){
    unsigned char s[256] = {0}, s2[256] = {0};
    char key[256] = {"justfortest"};

    unsigned long len = strlen(pData);
    int i;
    rc4_init(s, (unsigned char *)key, strlen(key));

    //用s2[i]暂时保留经过初始化的s[i]，很重要的！！！
    for (i = 0; i < 256; i++){
        s2[i] = s[i];
    }

    //解密
    rc4_crypt(s2, (unsigned char *)pData, len);
    printf("pData=%s\n\n", pData);

    return 0;
}


int main(int argc, char const *argv[]){
    char * tmp;
    char str[512] = "这是一个用来加密的数据Data";
    tmp = RC4_solve(str);
    RC4_dissolve(tmp);

    return 0;
}