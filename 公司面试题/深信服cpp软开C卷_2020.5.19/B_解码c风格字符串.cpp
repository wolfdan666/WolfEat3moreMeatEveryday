/*
2020年5月19日20:50:52 看完了题目了，还是有点点细节不太确定，先试试

好像就是简单的去斜杠操作？？
2020年5月19日20:59:33 休息5分钟再写吧
2020年5月19日21:04:07 决定去看看转义符到底需要转哪些先

发现只有 ' " ? \


"\"hello world\\n\\\"too\""

2020年5月19日21:25:29 晕死..原来还有合并操作
您的代码已保存
答案错误:您提交的程序没有通过所有的测试用例
case通过率为12.50%

用例:
"hello world\nabc"

对应输出应该为:

hello world
abc

你的输出为:

hello world\nabc


2020年5月19日21:42:54 自闭了....为啥赋了一个 \n 之后就截断了啊

2020年5月19日22:04:44 暂时不做了....有点不懂到底怎么输出

下次试试暴力修改main中的输出

2020年5月19日22:15:45 发现居然能看到过了的大佬的代码设计！！！
然后发现了大部分大佬们都是用的string.c_str() ...


2020年5月19日22:44:11
答案错误:您提交的程序没有通过所有的测试用例
case通过率为62.50%

用例:
"hello world\n\"too

对应输出应该为:

error

你的输出为:

hello world
"to

太尴尬了...所以还是去操作main吧，或者参考别的大佬的代码


2020年5月19日22:47:54 AC,我目前写bug能力太强，写算法能力太差，哭了
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

int unescape_c_quoted(char *buf, const char *str)
{
    //TODO:
    const int LEN = strlen(str);

    if(*str == NULL || *str != '\"' || str[LEN-1] != '\"')
        return -1;

    bool del[LEN];
    short change[LEN];
    const char * need = "\\\?\'\"";
    const char * component = "abfnrtv";
    const char * component_B = "\a\b\f\n\r\t\v";
    memset(del,false,sizeof del);
    memset(change,0,sizeof change);

    // for(int i=0;i<LEN;i++){
    for(int i=1;i<LEN-1;i++){
        if(str[i] == '\\'){
            // if(LEN-1 == i) return -1;
            if(LEN-2 == i) return -1;
            else{
                bool flag = 0;
                for(int j=0;j<4;j++)
                    if(need[j] == str[i+1]) del[i++]=true,flag=1;
                //  一开始以为这两个for不会有影响 这里例子"\"hello world\\n\\\"too\""出错
                // 2020年5月19日22:39:24发现前面i++会影响这里的i !!!
                // 2020年5月19日22:41:25 加个flag
                if(!flag) for(int j=0;j<7;j++)
                    if(component[j] == str[i+1]) del[i++]=true,change[i]=j;
            }

        }
    }

    int cnt = 0;

    // printf("%s\n", component_B);

    // for(int i=0;i<LEN;i++){
    for(int i=1;i<LEN-1;i++){
        // if(!del[i]) buf[cnt]=str[i];
        // if(change[i]){
        //     buf[cnt]=component_B[change[i]];
        //     printf("其实是自己的代码写丑了(愚蠢的过优化),component[change[i]]其实会出问题：%c\n", component_B[change[i]]);
        // }
        // // 2020年5月19日22:26:55 发现原来是自己这里傻逼了，一开始buf[cnt++]
        // // 因为多加了change[i]判断，改成现在cnt++放外面，但是其实如果del[] == true的时候正好跳过一个，所以就多了一个\0...
        // // 傻逼了，改回去
        // cnt++;

        if(!del[i]){
            buf[cnt]=str[i];
            if(change[i]){
                buf[cnt]=component_B[change[i]];
                // printf("其实是自己的代码写丑了(愚蠢的过优化),component[change[i]]其实会出问题：%c\n", component_B[change[i]]);
            }
            cnt++;
        }
        // 这样也阻止不了在\n之后就不输出了...它直接把\n当做\0了
        // buf[cnt]='\0';
        // printf("%s\n", buf);

        // puts(buf);

        // for(int j=0;j<cnt;j++) printf("%c",buf[j] );
        // printf("\n");
    }
    return 0;
}

int main()
{
    char str[10000];
    char buf[10000];
    int len;

    if (fgets(str, sizeof(str), stdin) == NULL) {
        fprintf(stderr, "input error\n");
        return 0;
    }
    // 取消空格操作有点东西
    len = strlen(str);
    while (len > 0 && isspace(str[len - 1])) {
        str[len - 1] = '\0';
        --len;
    }


    if(unescape_c_quoted(buf, str) < 0)
        printf("error\n");
    else
        printf("%s\n", buf);

    fprintf(stderr, "input:%s\noutput:%s\n", str, buf);
    return 0;
}