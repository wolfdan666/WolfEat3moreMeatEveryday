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

// http://www.cplusplus.com/reference/algorithm/unique/?kw=unique
template <class ForwardIterator>
  ForwardIterator unique (ForwardIterator first, ForwardIterator last)
{
  if (first==last) return last;

  ForwardIterator result = first;
  while (++first != last)
  {
    if (!(*result == *first))  // or: if (!pred(*result,*first)) for version (2)
      *(++result)=*first;
  }
  return ++result;
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return std::unique(nums.begin(), nums.end()) - nums.begin();
    }
};


int main(){
    vector<int> nums;
    nums.pb(1);
    nums.pb(1);
    nums.pb(2);
    Solution sol;
    int len = sol.removeDuplicates(nums);
    for (auto x : nums)
        cout << x << endl;
    for (int i = 0; i < len; i++) {
        cout << nums[i] << endl;
    }


    return 0;
}