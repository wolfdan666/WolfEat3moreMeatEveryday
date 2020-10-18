/* 忘了开long long */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
ll len[505];
string ans;
int T,n;ll k;

char f(int x,ll k){
    if(x==1) return "COFFEE"[k];
    if(x==2) return "CHICKEN"[k];
    if(k>=len[x-2]) return f(x-1,k-len[x-2]);
    else return f(x-2,k);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    len[1] = 6,len[2] = 7;
    ll mx = 1e13;
    /*这里最好不要break,否则会造成数组的部分是0值，除非先赋值为mx
    (当然也可以使用C++AC代码二的特殊提前处理去使用break)
    但是可以通过min控制数值大小，以免引发数据溢出错误
    可以使用min的原因是，k不会到很大的数据范围
    然后递归的时候是一样的,最终也是递归到x==1,x==2
    是按照题中斐波那契递归回去的，所以不会出错*/
    for(int i=3;i<=500;i++){
        len[i] = min(len[i-2]+len[i-1],mx);
    }
    for(cin>>T;T--;){
        cin>>n>>k;
        k-=1;
        ans.clear();
        ll tn = min(k+10,len[n]);
        for(ll i=k;i<tn;i++){
            ans += f(n,i);
        }
        cout<<ans<<endl;
    }

    return 0;
}