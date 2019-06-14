// 算法太朴素导致超时了！所以应该还是要用素数的？试试从大数开始递减取值--->果然还是不会过

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
    ll aa,bb,cc,dd;
    cin>>aa>>bb>>cc>>dd;
    ll x1=aa,y1=bb,x2=cc,y2=dd;
    // 和
    ll mu = y1*y2; x1*=y2,x2*=y1; ll zi = x1+x2;
    ll tem = min(zi,mu);
    for(int i=tem;i>=2;i--){
        if(zi%i==0 && mu%i==0){
            zi/=i,mu/=i;
            i++;
        }
    }
    // for(int i=2;i<=tem;i++){
    //     if(zi%i==0 && mu%i==0){
    //         zi/=i,mu/=i;
    //         i--;
    //     }
    // }
    if(zi==0) cout<<"0 0"<<endl;
    else cout<<zi<<" "<<mu<<endl;

    // 差
    x1=aa,y1=bb,x2=cc,y2=dd;// 每次都要刷洗一下数据
    mu = y1*y2; x1*=y2,x2*=y1;zi = x1-x2;// 负数也可以直接下面那样除
    tem = min(zi,mu);
    for(int i=tem;i>=2;i--){
        if(zi%i==0 && mu%i==0){
            zi/=i,mu/=i;
            i++;
        }
    }
    // for(int i=2;i<=tem;i++){
    //     if(zi%i==0 && mu%i==0){
    //         zi/=i,mu/=i;
    //         i--;
    //     }
    // }
    if(zi==0) cout<<"0 0"<<endl;
    else cout<<zi<<" "<<mu<<endl;

    // 积
    x1=aa,y1=bb,x2=cc,y2=dd; // 每次都要刷洗一下数据
    mu = y1*y2;zi = x1*x2;
    tem = min(zi,mu);
    for(int i=tem;i>=2;i--){
        if(zi%i==0 && mu%i==0){
            zi/=i,mu/=i;
            i++;
        }
    }
    // for(int i=2;i<=tem;i++){
    //     if(zi%i==0 && mu%i==0){
    //         zi/=i,mu/=i;
    //         i--;
    //     }
    // }
    if(zi==0) cout<<"0 0"<<endl;
    else cout<<zi<<" "<<mu<<endl;

    // 商
    x1=aa,y1=bb,x2=cc,y2=dd; // 每次都要刷洗一下数据
    mu = y1*x2;zi = x1*y2;
    tem = min(zi,mu);
    for(int i=tem;i>=2;i--){
        if(zi%i==0 && mu%i==0){
            zi/=i,mu/=i;
            i++;
        }
    }
    // for(int i=2;i<=tem;i++){
    //     if(zi%i==0 && mu%i==0){
    //         zi/=i,mu/=i;
    //         i--;
    //     }
    // }
    if(zi==0) cout<<"0 0"<<endl;
    else cout<<zi<<" "<<mu<<endl;

    return 0;
}