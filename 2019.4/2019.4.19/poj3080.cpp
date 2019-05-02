// 2019年4月19日21:02:48开始看题
// 2019年4月19日21:08:15 ： 与此类似的题目一般都是滑块枚举，这不会也是这样吧，感觉这题好像不是，如果是这样没啥好做的，所以先看看大佬怎么写
// 果然是这样，大佬这样写，其实可以优化成为 长度 先从60开始的,这样局部可能快一点，数据没有卡住，所以这题就这样吧
// http://www.voidcn.com/article/p-dlcbqfnc-gt.html
/*
题意：求最长公共子串（字典序最小的）
思路：开始以为有什么简单的方法，但是至多60位，至多十串，就不纠结了
具体见代码
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char str[15][65],temp[65],result[65];
int main()
{
    int n,m;
    cin >> n;
    while(n--)
    {
        scanf("%d",&m);
        for(int i = 1;i <= m;i++)
            scanf("%s",str[i]);

        memset(result,'\0',sizeof(result));
        //只把第一个字符串的子串当作模式串
        //枚举子串的长度
        for(int i = 1;i <= 60;i++)
        {
            int flag1 = 0;
            for(int j = 0; j <= 60-i;j++)//枚举子串的起点
            {
                int num = 0,flag2 = 1;
                for(int k = j;;k++)
                {
                    temp[num++] = str[1][k];
                    if(num == i)
                        break;
                }
                temp[num] = '\0';
                //枚举后面m-1个字符串
                for(int k = 2;k <= m;k++)
                {
                    if(!strstr(str[k],temp))//不是公共串
                    {
                        flag2 = 0;
                        break;
                    }
                }
                if(flag2)//找到公共串
                {
                    flag1 = 1;
                    //更新最大公共子串
                    if(strlen(result) < strlen(temp) || strcmp(result,temp) > 0)
                        strcpy(result,temp);
                }
            }
            if(flag1 == 0)//如果长度小的没有公共串，更长的就不用再找了
                break;
        }


        if(strlen(result) < 3)
            printf("no significant commonalities\n");
        else
            printf("%s\n",result);
    }
    return 0;
}