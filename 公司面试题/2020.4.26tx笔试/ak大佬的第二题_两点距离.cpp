/*作者：qin_peng
链接：https://www.nowcoder.com/discuss/417957?type=post&order=time&pos=&page=0&channel=
来源：牛客网


平面上有2*n个点，n个点属于A集合，n个点属于B集合，
各从俩集合中选择一个数，求最近点对。

平面最近点对，只要记录在哪个集合就ok。


2020年4月26日22:50:51 看了大佬的排序找答案，太惭愧了，自己竟然不会...
*/

#include<bits/stdc++.h>
using namespace std;
#define me(a,x) memset(a,x,sizeof(a))
#define sc scanf
#define pr printf
#define IN freopen("in.txt","r",stdin);
#define OUT freopen("out.txt","w",stdout);
typedef long long ll;
typedef unsigned long long ull;
const int N=1e6+6;
const int mod=1e9+7;
int O(){putchar('\n');return 0;}template<typename T,typename... Ty>
int O(const T& a,const Ty&... b){cout<<a<<' ';return O(b...);}
void I(){}template<typename T,typename... Ty>void I(T& a,Ty&... b){cin>>a;I(b...);}
template<typename T>void db(T *bg,T *ed){while(bg!=ed)cout<<*bg++<<' ';pr("\n");}
inline ll mul_64(ll x,ll y,ll c){return (x*y-(ll)((long double)x/c*y)*c+c)%c;}
inline ll ksm(ll a,ll b,ll c){ll ans=1;for(;b;b>>=1,a=a*a%c)if(b&1)ans=ans*a%c;return ans;}

const ll INF=1e11;
int n;
int flag[N];
int z[N];
struct Po{
    double x,y;
    int id;
}AB[N];
bool cmp(Po a,Po b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
bool cmps(const int &a,const int &b){
    return AB[a].y<AB[b].y;
}
double dis(int i,int j){
    double x=(AB[i].x-AB[j].x)*(AB[i].x-AB[j].x);
    double y=(AB[i].y-AB[j].y)*(AB[i].y-AB[j].y);
    return sqrt(x+y);
}
double merge(int l,int r){
    double d=INF;
    if(l==r)return d;
    if(l+1==r){
        if(AB[l].id==AB[r].id)return d;
        return dis(l,r);
    }
    int mid=l+r>>1;
    double d1=merge(l,mid);
    double d2=merge(mid+1,r);
    d=min(d1,d2);
    int i,j,k=0;
    for(i=l;i<=r;i++){
        if(fabs(AB[mid].x-AB[i].x)<=d){
            flag[i]=AB[i].id;
            z[k++]=i;
        }
    }
    sort(z,z+k,cmps);
    for(i=0;i<k;i++){
        for(j=i+1;j<k&&AB[z[j]].y-AB[z[i]].y<d;j++){
            if(flag[z[i]]!=flag[z[j]]){
                double d3=dis(z[i],z[j]);
                if(d>d3)d=d3;
            }
        }
    }
    return d;
}
void solve(){
    sc("%d",&n);
    for(int i=0;i<n;i++){
        sc("%lf%lf",&AB[i].x,&AB[i].y);
        AB[i].id=1;
    }
    for(int i=n;i<2*n;i++){
        sc("%lf%lf",&AB[i].x,&AB[i].y);
        AB[i].id=2;
    }
    n<<=1;
    sort(AB,AB+n,cmp);
    pr("%.3f\n",merge(0,n-1));
}


int main(){
    int t;I(t); while(t--)solve();
}