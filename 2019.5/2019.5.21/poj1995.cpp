// 2019年5月21日22:20:32开始读题
// 2019年5月21日22:26:33 翻译了一下看懂，然后写，因为先看了李煜东的书，所以有思路
// 2019年5月21日23:02:57 才写完...真龟速！

// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long

int power(int a,int b,int p){
    int ans = 1 % p;
    for(;b;b>>=1){
        if(b&1) ans = (ll) ans*a%p;
        a = (ll)a*a%p;   // a  a^2   a^4 ……
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    int kase;
    cin>>kase;
    while(kase--){
        int mod;
        cin>>mod;
        int players,a,b;
        cin>>players;
        ll ans = 0;
        while(players--) {
            cin>>a>>b;
            // ans += power(a,b,mod)%mod;  // 这会出错!!!可能导致ans超过mod！
            ans = (ans + power(a,b,mod)  )%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}