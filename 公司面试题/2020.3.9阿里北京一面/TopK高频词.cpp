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
    struct cmp {
        bool operator () (pair<int, string> &a, pair<int, string> &b) {
            if (a.first < b.first) return true;
            if (a.first > b.first) return false;
            return (a.second.compare(b.second))>0;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> count;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> great_heap;
        for (auto word : words) count[word]++;
        for (auto it = count.begin(); it != count.end(); it++) great_heap.push({ it->second,it->first });
        int n = (int)great_heap.size();
        for (int i = 0; i < (min(n, k)); i++) {
            res.push_back(great_heap.top().second);
            great_heap.pop();
        }
        return res;
    }
};

int main(){


    return 0;
}