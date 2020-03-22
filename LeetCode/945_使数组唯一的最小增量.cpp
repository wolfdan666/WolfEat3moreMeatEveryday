/*
2020年3月22日13:30:36 开始看题
2020年3月22日13:38:12 想到一个比较简单的做法
就是记录min,max,size => n
for count[min] => count[max + n]:
    for i in count:
        ans += ...
        count[...] += ...

感觉复杂度均摊之后应该还是O(n)

2020年3月22日13:46:25 写吧

2020年3月22日14:01:53 被空样例WA一发..
2020年3月22日14:04:35 AC得有点慢了
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
    int minIncrementForUnique(vector<int>& A) {
        int n = A.size();
        if(n <= 1) return 0;
        memset(count,0,sizeof(count));
        int mi = A[0],ma = mi;
        count[A[0]]++;
        for(int i=1;i<n;i++){
            if(A[i] > ma) ma = A[i];
            if(A[i] < mi) mi = A[i];
            count[A[i]]++;
        }

        int ans = 0;
        int N = n + ma;
        for(int i = mi; i < N; i++){
            if(count[i] > 1){
                for(int j = 1; j < count[i]; j++){
                    ans += j;
                    count[i+j]++;
                }
            }
        }

        return ans;
    }
private:
    int count[80010];
};

int main(){
    // int array[6] = {3,2,1,2,1,7};
    int array[3] = {0,0,0};
    vector<int> test(array,array+sizeof(array)/sizeof(int));

    for(auto i:test) cout<< i << " " ;  cout<<endl;

    vector<int> test1;
    vector<int> test2;
    test2.pb(1);
    Solution t;
    cout<< t.minIncrementForUnique(test) <<endl;
    cout<< t.minIncrementForUnique(test1) <<endl;
    cout<< t.minIncrementForUnique(test2) <<endl;


    return 0;
}