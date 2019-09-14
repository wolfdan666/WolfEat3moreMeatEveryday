// 2019年3月13日15:46:52 开始睡觉，休息一会，然后再看题
// 2019年3月13日16:27:01看完题,感觉模拟必定超时,必须要想一个优化办法
// 发现2<=n<=100 000,所以一定是在Multiplication的时候就优化
// 2019年3月13日17:04:05借鉴思路后发现还是不太会写的样子，于是又借鉴了代码，不过发现copy的code是顺着写的，和tutorial思路不同
// 没想到copy的code直接模拟也牛逼了!!!
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100100
string p[MAX];
int n,l[MAX];ll ans;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>p[i],l[i]=p[i].length();
    for(char c='a';c<='z';++c)
    {
        ll mx=0;
        for(int i=1;i<=n;++i)
        {
            ll L=0,R=0;ll mxl=0,s=0;
            for(int j=0;j<l[i];++j)
                if(p[i][j]==c)mxl=max(mxl,++s);
                else s=0;
            if(!mxl&&!mx)continue;
            for(int j=0;j<l[i];++j)
                if(p[i][j]==c)++L;
                else break;
            for(int j=l[i]-1;~j;--j)  // j为 -1 的时候退出
                if(p[i][j]==c)++R;
                else break;
            ll nw=mxl;
            if(L==l[i]){mx=1ll*L*(mx+1)+mx;continue;} // mx是上面积累下来的  mx刀就有(mx+1)段木头,所以加上自身mx就得到新的mx   continue
            if(mx)nw=max(nw,L+1+R); // 如果没有上面的情况，那就是最长串，或者左右加上1个(+1是因为被分隔)
            mx=nw;
        }
        ans=max(ans,mx);
    }
    cout<<ans<<endl;
    return 0;
}