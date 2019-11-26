// typedef long long ll;
// inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}

class Solution {
public:
    int jumpFloorII(int number) {
        // return qpow(2,number-1);
        return pow(2,number-1);
    }
};