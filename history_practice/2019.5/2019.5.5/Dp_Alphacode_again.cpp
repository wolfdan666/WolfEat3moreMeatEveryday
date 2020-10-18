// 2019年5月3日20:37:21开始看题
// 思路：从头扩散出去，然后看满足条件的地方(下标到了n-1就成为了叶子),最后数叶子数
// 2019年5月5日19:46:09 来补
// 2019年5月5日20:04:06 POJ不然万能头文件，然后第一发居然TLE了...递归转递推去吧
// 所有地方的return都是为了走到末端 顺便 发现下一个位的位置，所以递推应该就是每个位置直接ans++,或者ans+=2
// 但是感觉自己还是理不清这个关系，耗时太久，看大神怎么写
// 发现大神巧妙地用两个数组处理掉了联系，牛逼


/*
// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long
string s;
ll ans;
int n;

ll solve(int i){
    if(i>=n-1) return 1;
    else if(s[i]=='0') return 0;
    else{
        if(s[i]<'3'){  // 这里不会为0
            if(s[i]=='1'){
                return solve(i+1) + solve(i+2);
            }
            if(s[i]=='2'){
                if(s[i+1]<='6'){
                    return solve(i+1) + solve(i+2);
                }
                else{
                    return solve(i+1);
                }
            }
        }
        else{
            return solve(i+1);
        }
    }
    return 0;
}

int main(int argc, char const *argv[]){
    while(cin>>s&&s[0]!='0'){
        ans = 0;
        n = int(s.length());
        ans+=solve(0);
        cout<<ans<<endl;
    }
    return 0;
}

*/
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
const int mMax=10000;

int main()
{
    char m[mMax];
    __int64 sin[mMax],dou[mMax];              // sin[]存尾数为1位的情况，dou[]存尾数为2位的情况。
    int i,len;
    while(cin>>m+1 && m[1]!='0')
    {
        sin[1]=1;
        dou[1]=0;
        len=strlen(m+1);  //必须为m+1
        for(i=2;i<=len;i++)
        {
            if(m[i]=='0')
            {
                sin[i]=0;
                dou[i]=sin[i-1];
            }
            else      // 最后为零，则尾数为1位=0，尾数为2位=上一个尾数为1位
                if(m[i-1]=='1' || m[i-1]=='2' && m[i]<='6')    //最后两位可以凑
                {
                    sin[i]=sin[i-1]+dou[i-1];
                    dou[i]=sin[i-1];
                }
                else  //最后两位不可凑
                {
                    sin[i]=sin[i-1]+dou[i-1];
                    dou[i]=0;
                }
        }
        printf("%I64d\n",sin[len]+dou[len]);
    }
    return 0;
}
