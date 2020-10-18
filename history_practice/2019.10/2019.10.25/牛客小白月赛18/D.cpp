/*
2019年10月25日20:03:54 开始看题

傻逼模拟题...

然后傻逼的是自己不会,然后Google了一下...2019年10月25日20:23:13
https://blog.csdn.net/qq_29567701/article/details/79676736

2019年10月25日20:37:28 竟然wa了

2019年10月25日21:20:49 全改成整数操作还是wa
2019年10月25日21:21:56 发现没有改全,而且有多重定义...

2019年10月25日21:28:50 测试发现我wa在了a数组被sort掉了!

2019年10月25日21:43:09 DEBUG了那个blog主的代码,然后AC了
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

int b[5] = {0,1,-1,0,0};
int c[5] = {0,0,0,1,-1};
ll s1, s2, s3, s4;

struct point{
    // double x, y;
    int x, y;
} a[4],d[4];

bool cmp(point a, point b){
    if (a.x != b.x)
        return a.x < b.x; //如果，横坐标不相等，所有点按横坐标升序排列
    return a.y < b.y;//如果横坐标相等，所有点按纵坐标升序排列
}

ll TwoPointDiatance(point a, point b){
    // return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

bool IsRightAngle(point a, point b, point c){
    // double x;
    ll x;
    x = (a.x - b.x)* (a.x - c.x) + (a.y - b.y)*(a.y - c.y);
    // if (x < 0.000001)
    if (x == 0) return 1;
    else return 0;
}

bool chk(){
    //确定点，排序，给点确定标号
    memcpy(d,a,sizeof d);
    sort(d, d + 4, cmp);

    //确定边
    s1 = TwoPointDiatance(d[0], d[2]);
    s2 = TwoPointDiatance(d[0], d[1]);
    s3 = TwoPointDiatance(d[3], d[1]);
    s4 = TwoPointDiatance(d[2], d[3]);

    //分析是否为正方形
    //三个条件同时满足（1：四条边相等，2：边不为0，3：有一个直角）
    // 发现这里sb有两个s1==s2
    if (s1==s2 && s2==s3 && s3==s4 && s1!=0 && IsRightAngle(d[0], d[1], d[2]))
        return true;
    else
        return false;
}

int main(){
    for (int i = 0; i < 4; i++) cin >> a[i].x >> a[i].y;
    if(chk()){cout<<"wen"<<endl;return 0;}
    else{
        rep(i,0,3){
            rep(j,1,4){
                // cout<<"1 a[i].x: "<<a[i].x<<" a[i].y: "<<a[i].y<<endl;
                a[i].x+=b[j],a[i].y+=c[j];
                // cout<<"2 a[i].x: "<<a[i].x<<" a[i].y: "<<a[i].y<<endl;
                if(chk()){
                    cout<<"hai xing"<<endl;
                    return 0;
                }
                a[i].x-=b[j],a[i].y-=c[j];
                // cout<<"3 a[i].x: "<<a[i].x<<" a[i].y: "<<a[i].y<<endl;
            }
        }
    }
    cout<<"wo jue de bu xing"<<endl;
    return 0;
}