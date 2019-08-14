#include<bits/stdc++.h>
using namespace std;
#define NUM 50
int MAXN,n,mod;

//矩阵的类
struct Matrix{
    int a[NUM][NUM];
    //将其初始化为单位矩阵
    void init(){
        memset(a,0,sizeof(a));
        for(int i=0;i<MAXN;i++)
            a[i][i]=1;
    }
} A;

//(a*b)%mod  矩阵乘法
Matrix mul(Matrix a,Matrix b){
    Matrix ans;
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++){
            ans.a[i][j]=0;
            for(int k=0;k<MAXN;k++)
                ans.a[i][j]+=a.a[i][k]*b.a[k][j];
            ans.a[i][j]%=mod;
        }
    return ans;
}

//(a+b)%mod  //矩阵加法
Matrix add(Matrix a,Matrix b){
    int i,j,k;
    Matrix ans;
    for(i=0;i<MAXN;i++)
        for(j=0;j<MAXN;j++){
            ans.a[i][j]=a.a[i][j]+b.a[i][j];
            ans.a[i][j]%=mod;
        }
    return ans;
}

//(a^n)%mod  //矩阵快速幂
Matrix pow(Matrix a,int n) {
    Matrix ans;
    ans.init();
    while(n){
        if(n&1)
            ans=mul(ans,a);
        n/=2;
        a=mul(a,a);
    }
    return ans;
}

//(a+a^2+a^3....+a^n)%mod// 矩阵的幂和
Matrix sum(Matrix a,int n){
    int m;
    Matrix ans,pre;
    if(n==1)
        return a;
    m=n/2;
    //[1,n/2]
    pre=sum(a,m);
    //ans=[1,n/2]+a^(n/2)*[1,n/2]
    ans=add(pre,mul(pre,pow(a,m)));
    if(n&1)
        //ans=ans+a^n
        ans=add(ans,pow(a,n));
    return ans;
}

//输出矩阵
void output(Matrix a){
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
            printf("%d%c",a.a[i][j],j==MAXN-1?'\n':' ');
}

int main(){
    freopen("in.txt","r",stdin);
    Matrix ans;
    scanf("%d%d%d",&MAXN,&n,&mod);
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++){
            scanf("%d",&A.a[i][j]);
            A.a[i][j]%=mod;
        }
    ans=sum(A,n);
    output(ans);
    return 0;
}
