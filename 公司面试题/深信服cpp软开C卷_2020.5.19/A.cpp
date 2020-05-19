/*
2020年5月19日20:10:28 开始看题

2020年5月19日20:14:01 的想法是：
遍历pattern,如果遇到`*`则去递归match

2020年5月19日20:32:00 测试了一下char子串的操作,开始正式写本题

2020年5月19日20:41:17 发现自己的递归就是for循环了...

2020年5月19日20:48:02 AC...
38mins,龟速
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <algorithm>
using namespace std;

int match(const char *str, const char *pattern)
{
    //TODO:
    int ptnLen = strlen(pattern);
    int strLen = strlen(str);
    if(ptnLen==0 && strLen == 0) return 0;
    if(ptnLen==0 || strLen == 0) return -1;
    int ans = -1;

    // for(int i=0;i<ptnLen;i++){
        if(pattern[0] == '*'){
            // * 匹配一个或者strlen个字符
            for(int j=0;j<strLen;j++){
                ans = max(ans, match(str+j+1, pattern +1) );
            }
        }
        else if(pattern[0] == '?'){
            ans = max(ans, match(str+1,pattern+1) );
        }
        else{
            if(str[0] == pattern[0])
                ans = max(ans, match(str+1,pattern+1) );
            else return -1;
        }
    // }
    return ans;
}

int input(char **src, char **ptn)
{
    char buf[10240];

    *src = NULL;
    *ptn = NULL;
    if (fgets(buf, sizeof(buf), stdin) == 0)
        goto failed_;
    *src = strdup(buf);
    if (fgets(buf, sizeof(buf), stdin) == 0)
        goto failed_;
    *ptn = strdup(buf);
    return 0;
failed_:
    if (*src)
        free(*src);
    if (*ptn)
        free(*ptn);
    *src = NULL;
    *ptn = NULL;
    return -1;
}

int main(int argc, char *argv[])
{
    char *src = NULL;
    char *ptn = NULL;

    if (input(&src, &ptn) < 0) {
        fprintf(stderr, "error\n");
        return 0;
    }

    if (match(src, ptn) == 0) {
        printf("match\n");
    } else {
        printf("unmatch\n");
    }
    return 0;
}