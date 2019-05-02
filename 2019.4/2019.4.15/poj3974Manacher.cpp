// 2019年4月15日16:02:09开始看题
// 经典的Manacher算法，马拉车算法,争取10mins完成
// 2019年4月15日16:25:36 只会默写Init，Manacher借鉴了一下，所以还是要多熟悉，Manacher就是维护并且推动中心值
// 2019年4月15日16:36:16提交多次，都是RE...
// 2019年4月15日16:46:56 很无奈，一直RE，发现网上大家用c++，scanf读入char *，读string会出错...然后poj又不知道是什么鬼(可能不是linux下的编译器...)，所以还是直接使用别人的code，不想改了


// #include<bits/stdc++.h>  // poj 应该不支持
// #include<iostream>
// #include<string>
// #include<string.h>
// #include<algorithm>
// #define ll long long
// using namespace std;
// string source;
// string t;
// long long p[1000010];

// ll Init(string s){
//     ll n = 1ll*s.length();
//     t.resize(n*2+2,'#'); // $和空对应,所以就不用最后t[j]='\0'
//     t[0]='$';t[1]='#';
//     ll j = 2;
//     for(ll i=0;i<n;i++){
//         t[j++]=s[i];
//         // t[j++]='#';
//         j++;
//     }
//     return j;
// }

// ll Manacher(string s){
//     ll len = Init(s);
//     long long max_len=-1;
//     ll id = 0;
//     ll mx = 0;
//     for(int i=1;i<len;i++){
//         if(i<mx){
//             p[i] = min(p[2*id-i],mx-i);
//         }
//         else p[i] = 1;
//         while(t[i-p[i]]==t[i+p[i]]) {
//             p[i]++;
//         }
//         if(mx<i+p[i]){
//             mx = i+p[i];
//             id = i;
//         }
//         max_len = max(max_len,p[i]-1);
//     }
//     return max_len;
// }

// int main(int argc, char const *argv[])
// {
//     // ios::sync_with_stdio(false);
//     int Case = 0;
//     while(cin>>source) {
//         if(source=="END") return 0;
//         Case++;
//         cout<<"Case "<<Case<<": "<<Manacher(source)<<endl;
//     }
//     return 0;
// }

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char str[1111111];
char nwstr[2333333];
int p[2333333];

int Manacher()
{
    int len = strlen(str);
    nwstr[0] = '@';
    int i;
    for(i = 0; i <= len; ++i)
    {
        nwstr[i*2+1] = '#';
        nwstr[i*2+2] = str[i];
    }

    int Maxid = 0,id,ans = 0;
    len = len*2+2;

    for(i = 1; i <= len; ++i)
    {
        p[i] = (Maxid > i)? min(p[id*2-i],Maxid-i): 1;
        while(nwstr[i+p[i]] == nwstr[i-p[i]]) ++p[i];
        if(Maxid < i+p[i])
        {
            Maxid = i+p[i];
            id = i;
        }
        ans = max(ans,p[i]-1);
    }
    return ans;
}

int main()
{
    int z = 0;
    while(~scanf("%s",str) && str[0] != 'E')
    {
        printf("Case %d: %d\n",++z,Manacher());
    }
    return 0;
}