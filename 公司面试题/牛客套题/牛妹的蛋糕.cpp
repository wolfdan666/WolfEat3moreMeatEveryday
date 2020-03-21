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
    /**
     *
     * @param n int整型 只剩下一只蛋糕的时候是在第n天发生的．
     * @return int整型
     1
     (1+1) / (2/3) = 3
     (3+1) / (2/3) = 6
     (6+1) / 2 * 3 = 10.5 -- > 10 ---> 6
     突然想到一个开挂的做法，就是10.5--> for 8->12 : 反复确认
     */
    int cakeNumber(int n) {
        // write code here
        // int ans = 1;
        double ans = 1;
        int pre = 1;
        for(int i=1; i < n; i++){
            ans = (ans + 1) / 2 * 3;
            for(int j = floor(ans); j <= ceil(ans); j++){
                if( j - int(floor(j/3)) - 1 == pre){
                    ans = pre = j;
                    // printf("第%d天判断是%d个\n", i+1,pre);
                }
            }
        }
        int lastAns = ans;
        return lastAns;
    }
};

int main(){
    Solution a;
    cout<< a.cakeNumber(5)<<endl;

    return 0;
}