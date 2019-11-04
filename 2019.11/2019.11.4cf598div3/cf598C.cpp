/*
2019年11月04日22:02:35 看发现D过得比C多,所以先D

2019年11月04日22:16:05 归来

感觉应该就是贪心向前,然后只要注意不能挤爆右边就完事了
// 2019年11月04日22:47:41一开始没有细想,所以写得太乱,所以规划一下先
2019年11月04日23:15:23 自闭,没有写完...代码实现能力还是太差了
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
int n,m,d,c[1010],sum[1010],presum[1010],a[1010];

int main(){
    scanf("%d%d%d",&n,&m,&d);
    rep(i,1,m) c[i] = rd();
    // per(i,m,1) sum[i]+=c[i];
    per(i,m,1) sum[i]+=sum[i+1]+c[i];
    // rep(i,1,m) presum[i]+=c[i];
    rep(i,1,m) presum[i]+=presum[i-1]+c[i];
    // n 个 坎, sum[1] 处 梯子, 所以n - sum[1]处坎
    // 然后有 m + 2个停靠, 即可以跳m+1次
    // 每次可以跳过d-1的坎距离
        // int tp = n+1-(sum[1]-m);
    int tp = n-sum[1];
    // cout<<sum[1]<<" "<<tp<<" "<<(m+1)*(d-1)<<endl;

    if(tp > (m+1)*(d-1)) return printf("%s\n", "NO")*0;
    int pre,prer;
    rep(i,1,m){
        int right = 1+i*d+presum[i-1]-i;
        int rs = sum[i+1];
        // 必定只会发生一次堵塞吧
        if(n - right >= rs){
            int tmp = n - right - rs;
            rep(k,right-tmp-c[i]+1,right) a[k]=i;
            // per(j,right-d,pre+1){
            //     if(j+d)
            // }
        } else {
            rep(k,right-c[i]+1,right) a[k]=i;
        }
    }
    printf("%s\n","YES");
    rep(i,1,n) printf("%d ",a[i]);

    return 0;
}