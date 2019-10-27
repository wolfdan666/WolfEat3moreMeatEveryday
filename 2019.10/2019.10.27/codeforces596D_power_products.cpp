/*
2019年10月27日21:14:35 还是好难啊...

2019年10月27日21:24:42还是没有看懂tutorial,就先找一个大佬的代码来看看先

Suppose that x⋅y is a k-th power. The sufficient and necessary condition for that is: for any prime p,
the total number of times it divides x and y must be divisible by k.

假设x⋅y是第k次幂。 充分必要的条件是：对于任何质数p，除以x和y的总次数必须被k除。

x,y是被除数!!! p是除数,去除以x,y!(小学遗留下来的概念模糊,真是迟早要还)


轮番轰炸tutorial和这个代码,渐渐懂了一点了,就是有点像那个简单的面试题 "两数之后",只不过这里的 和 是 x^k,而两数是两个  由pair组成的 数组
*/

// By luogu_bot4, contest: Technocup 2020 - Elimination Round 2, problem: (D) Power Products, Accepted, #
// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// #include <map>
// #include <vector>
// using namespace std;
// map<vector< pair<int,int> > , int > mp;
// vector<pair<int,int>> x,x1;
// int n,k,a[300005];
// long long ans=0;
// int main() {
//     scanf("%d%d",&n,&k);
//     for (int i=1;i<=n;++i) {
//         scanf("%d",&a[i]);
//         x.clear();x1.clear();
//         int aa=a[i];
//         for (int j=2;j*j<=a[i];++j) {
//             int tot=0;
//             while(aa%j==0) {
//                 ++tot;
//                 aa/=j;
//                 tot%=k;
//             }
//             if(!tot) continue;
//             x.push_back({j,tot});
//             x1.push_back({j,k-tot});
//         }
//         if(aa!=1) {
//             x.push_back({aa,1});
//             x1.push_back({aa,k-1});
//         }
//         ans=ans+mp[x1];
//         ++mp[x];
//     }
//     printf("%lld\n",ans);
// }


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
map<vector< pair<int,int> > , int > mp;
vector<pair<int,int>> x,x1;
int n,k,a[300005];
long long ans=0;
int main() {
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        x.clear();x1.clear();
        int aa=a[i];
        for (int j=2;j*j<=a[i];++j) {
            int tot=0;
            while(aa%j==0) {
                ++tot;
                aa/=j;
                tot%=k;
            }
            if(!tot) continue;
            x.push_back({j,tot});
            x1.push_back({j,k-tot});
        }
        if(aa!=1) {
            x.push_back({aa,1});
            x1.push_back({aa,k-1});
        }
        ans=ans+mp[x1];
        ++mp[x];
    }
    printf("%lld\n",ans);

    return 0;
}