// 2019年5月30日21:48:45 开始看题
// 借助李煜东的算法书看懂题意2019年5月30日22:02:58
// 不能抄写！至少默写，好的
// 2019年5月30日22:37:12数据处理遇到点问题，看大佬怎么写
// 发现自己又手生了，然后一个细节出错...
// poj上的g++给我CE...然后说我abs  ambiguous.sqrt未定义,   --> 平方不用abs  + math.h
// 2019年5月30日22:52:32竟然wa了！
// Output Limit Exceeded...(改了输出之后，结果。。)
// %.0f 是输出 float 型或 double 型数据，按定点格式，小数点以下占0位  ,但是会四舍五入
// 现在又出了tle的幺蛾子...


#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>

#define ll long long
using namespace std;

#define mp make_pair
#define f first
#define s second
typedef pair<ll,ll> P;

P calc(int n,ll m){
    if(n==0) return mp(0,0);
    ll len = 1<<(n-1),cnt = 1<<(2*n - 2);
    // ll len = 1<<(n-1),cnt = 1<<(2*2 - 2);
    P pos = calc(n-1,m%cnt);
    ll x = pos.f,y = pos.s;
    ll z = m/cnt;
    if(z==0) return mp(y,x);
    if(z==1) return mp(x,y+len);
    if(z==2) return mp(x+len,y+len);
    if(z==3) return mp(2*len-y-1,len-x-1);
}

int main(int argc, char const *argv[])
{
    double ans;
    int T;
    cin>>T;
    int a;ll b,c;
    while(T--) {
        // cin>>a>>b>>c;
        scanf("%d%lld%lld",&a,&b,&c);
        c--;b--;
        P tema=calc(a,b),temb=calc(a,c);


        long double dis = pow(tema.f-temb.f,2)+pow(tema.s-temb.s,2);
        // cout<<tema.f<<" "<<tema.s<<" "<<temb.f<<" "<<temb.s<<"dis"<<dis<<endl;
        // long double dis = pow(abs(tema.f-temb.f),2)+pow(abs(tema.s-temb.s),2);
        ans = sqrt(dis*100);
        // cout<<ans<<endl;
        // printf("%lld\n",dis-(int)dis<0.5?(int)dis:(int)dis+1);
        printf("%.0f\n",ans);

    }
    return 0;
}