/*
在高铁上没有写完
2019年10月22日19:34:07 继续开始写

tag: math , geometry , 1500
我觉得应该加个贪心的标签...
竟然1500分的题目只有1381人过，div3看来确实简单很多

2019年10月22日19:47:48 GG,自己疑惑不解之间,发现wa on 10
应该是没有考虑有两个都是先大于右上角的情况

写了右上角情况又wa on 10,然后看错误样例去了

2019年10月22日20:57:41 debug发现心绪问题也是编码瓶颈！
还记得自己曾经震惊于那个软件博士学长一边工作一边开着qq，这就是
平和心，在喧闹下也能编码的强者

2019年10月22日21:04:30 wa on test 41...什么鬼啊

看到别人写的精简思路，自己都觉得自己傻哭了

别人是判断宽高，不断取得非正矩形

我是模拟对角，还难写的一批...

然后再仔细检查，傻逼没写min...

再不过我吃屎.....然后过了...
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
int c[3][5],x1,x2,y1,y2;
bool ans;

int main(){
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    rep(i,1,2) rep(j,1,4) c[i][j] = rd();
    rep(i,1,2){
        // 下高铁的时候心绪波动就写了一个bug，所以喧闹下编码是一种强大的能力！
        // if(c[i][1]<=x1 && c[i][2]<=y2){
        if(c[i][1]<=x1 && c[i][2]<=y1){
            if(c[i][3]>=x2 && c[i][4]>=y2){
                ans = 1;

        // cout<<"___begin____"<<endl;
        // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        // cout<<c[i][1]<<" "<<c[i][2]<<" "<<c[i][3]<<" "<<c[i][4]<<endl;
        // cout<<"___end____"<<endl;

            } else if(c[i][3]>=x2){
                y1 = max(y1,c[i][4]);
            } else if(c[i][4]>=y2){
                x1 = max(x1,c[i][3]);
            }
        } else if(c[i][3]>=x2 && c[i][4]>=y2){
            // 然后复制粘贴又出锅...2019年10月22日20:57:17
            if(c[i][1]<=x1 && c[i][2]<=y1){
                ans = 1;

        // cout<<"___begin____"<<endl;
        // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        // cout<<c[i][1]<<" "<<c[i][2]<<" "<<c[i][3]<<" "<<c[i][4]<<endl;
        // cout<<"___end____"<<endl;

            } else if(c[i][1]<=x1){
                y2 = min(y2,c[i][2]);
                // 细节题真心GG
            // } else if(c[i][2]<=y2){
            } else if(c[i][2]<=y1){
                // 一开始这里没有取min,傻逼...,然后就wa了
                x2 = min(x2,c[i][1]);
            }
        }
        // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    }
    printf("%s\n", ans?"NO":"YES");

    return 0;
}