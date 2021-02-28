/*
2021年02月28日19:01:20 开始看题

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

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int sz = A.size();
        if (sz <= 1) {
            return true;
        }
        bool rise = false;
        int i = 0;
        while (i + 1 < sz && A[i] == A[i + 1]) {
            i++;
        }
        if (i == sz - 1) {
            return true;
        } else {
            rise = A[i] < A[i + 1];
        }

        // 注意下面要sz - 1,防止 i + 1 越界
        for (; i < sz - 1; i++) {
            if (rise) {
                if (A[i] > A[i + 1]) {
                    return false;
                }
            } else {
                if (A[i] < A[i + 1]) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main(){
    
    
    return 0;
}