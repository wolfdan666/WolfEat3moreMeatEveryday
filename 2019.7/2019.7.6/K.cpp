// 找规律题目
/*
1. 整除N/K=cnt 轮数    N/K扔掉的 --- 所以只要N/K==奇数   女生多拿一轮,则可以YES

11位的长度，int只有9位
 */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k,N;

int main(){
    cin>>N>>k;
    if((N/k)&1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}