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
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n = -1;
        // if(!array.empty()) n = sizeof array;
        // if(!array.empty()) n = sizeof(array);
        if(!array.empty()) n = array.size();
        if(n<=0) return 0;

        int cur = 0, ans = INT_MIN;
        // int cur = 0, ans = 0x80000000;
        // int cur = 0, ans = -10000;

        // for(int i=0;i<n;i++) cout<< array[i] << " "; cout<<endl;

        for(int i=0; i<n; i++){
            if(cur <= 0) cur = array[i];
            else cur += array[i];

            if(cur>ans) ans = cur;
        }

        return ans;
    }
};

int main(){
    // [1,-2,3,10,-4,7,2,-5]
    int tmp[10] = {1,-2,3,10,-4,7,2,-5};
    vector<int> a(tmp,tmp+8);
    Solution sol;
    cout<<sol.FindGreatestSumOfSubArray(a)<<endl;

    return 0;
}