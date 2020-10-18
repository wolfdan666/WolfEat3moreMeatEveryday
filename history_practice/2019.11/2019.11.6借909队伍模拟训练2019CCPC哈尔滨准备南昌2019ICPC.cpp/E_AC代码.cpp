#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define LL long long
using namespace std;
const int N=1e6+5;
vector<int>E[N];
LL v[N];//代表第i段序列被使用次数
int n,op[N][3];
inline void read(int &x){
    x=0;
    char ch;
    while((ch=getchar())<'0'||ch>'9');
    x=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        x=(x<<3)+(x<<1)+ch-'0';
}
inline void red(){  //读入数据
    read(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&op[i][0]);
        E[i].clear();v[i]=0;  //初始化
        if(op[i][0]==1){
            int len;read(len);
            while(len--){
                int x;read(x);
                E[i].push_back(x);
            }
        }else{
            read(op[i][1]);read(op[i][2]);
        }
    }
}
inline void slove1(){ //计算每个序列会使用多少次
    v[n]=1;
    for(int i=n;i>=1;i--)
        if(op[i][0]==2){
            v[op[i][1]]+=v[i];
            v[op[i][2]]+=v[i];
        }
}
inline void slove2(){
    LL x=0,tol=0,all=0;
    for(int i=1;i<=n;i++)   //这一步是为了计算出现次数>=(all+1)/2的数,找错就代表不存在
        if(op[i][0]==1 && v[i]!=0)
            for(auto u:E[i]){
                if(x==0)x=u,tol+=v[i];
                else if(x==u)tol+=v[i];
                else {
                    tol-=v[i];
                    if(tol<0)
                        x=u,tol=-tol;
                }
                all+=v[i];
            }
    tol=0;//统计这个数出现了多少次
    for(int i=1;i<=n;i++)
        if(op[i][0]==1 && v[i]!=0)
            for(auto u:E[i])
                if(u==x)
                    tol+=v[i];
    if(tol>all-tol)
        printf("%lld\n",(all-tol)*2);
    else
        printf("%lld\n",all);
}

int main(){
    int t;read(t);
    while(t--){
        red();
        slove1();
        slove2();
    }
    return 0;
}