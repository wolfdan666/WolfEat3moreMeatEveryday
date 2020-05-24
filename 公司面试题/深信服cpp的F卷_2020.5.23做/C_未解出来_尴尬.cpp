/*
2020年5月23日17:32:07 发现C题没有人做对过？？所以赶紧看一下

每一列取 k 个值
每一行取 0 or 1个 (表示此人是否被录用)

m*k<=n 条件给了

感觉是一个二维矩阵上的dp，现在2020年5月23日17:42:38 要搞清楚怎么状态转移

2020年5月23日18:18:45
1. 想到了抢占函数，对每一列sort，然后抢占...感觉可能循环...
2. 还想到了k元组状态，感觉不太好
3. 又想到了01枚举，感觉也不太好
4. 又想到从0到m-1列，各列开始，不准抢占，感觉还是不太对

2020年5月23日18:22:06 决定还是看答案吧...

2020年5月23日19:41:39 发现没有答案...尴尬
感觉只能用方法4混点分数 O(T*m*m*n*log(n)) -- 1e6.还行
(1<=n<=50，1<=m<=10，1<=k<=10，m*k<=n)
T(T<=100)

2020年5月23日19:49:34 决定先混点分数，开始写___因为面试中确实可能出现你不会的题

2020年5月23日20:23:31 只能过样例，错误的解法，混分数失败，0%...GG
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
int T;
int A[55][12];
int n,m,k;
pair<int,int> tmp[55];
set<int> used;

bool cmp(const pair<int,int>& a,const pair<int,int>& b){
    return a.fi > b.fi;
}

int main(){
    T = rd();
    while(T--){
        n=rd();m=rd();k=rd();
        rep(i,1,n) rep(j,1,m) A[i][j] = rd();
        int ans = 0;

        // m次最优列
        rep(i,1,m){
            int cnt = m;
            // 每次最优列后的遍历
            int tp_ans = 0;
            used.clear();
            for(int j=i;cnt-->0;j=j%m+1){
                rep(p,1,n){
                    tmp[p] = {A[p][j],p};
                }
                sort(tmp+1,tmp+n+1,cmp);
                int tp_k = k;
                rep(p,1,tp_k){
                    if(used.find(tmp[p].se) != used.end()){
                        tp_k++; continue;
                    }
                    else{
                        tp_ans += tmp[p].fi;
                        used.insert(tmp[p].se);
                    }
                }
            }

            ans = max(ans,tp_ans);
        }
        printf("%d\n", ans);
    }

    return 0;
}