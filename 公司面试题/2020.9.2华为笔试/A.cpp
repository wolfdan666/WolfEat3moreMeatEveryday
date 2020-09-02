/*
2020年9月2日19:02:07 看题
2020年9月2日19:06:16 看完思考

2020年9月2日19:09:52 想到了一个颜色和最大三元组
2020年9月2日19:16:29 感觉两个优先队列直接搞定
借鉴一下以前priority_queue<ll,vector<ll>,less<ll>> que;

2020年9月2日19:25:13 测试发现默认从大到小

2020年9月2日19:27:56 改成greater就好了

2020年9月2日19:46:43 只过了40%...
才发现还有null！

return puts("null"); 返回值非0也判错

2020年9月2日19:53:37 PE..
2020年9月2日19:54:58 80%...醉了
2020年9月2日20:00:28 （糖果数从小到大对应的位置编号）----自己还取消了这个操作，sb了

2020年9月2日20:01:34 AC..
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
#define pii pair<int,int>
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}


priority_queue< pii, vector< pii >, greater<pii> > qA,qB;
int N;

int main(){
    // qA.push({2,7});
    // qA.push({3,6});
    // qA.push({1,8});
    // rep(i,1,3){
    //     cout << qA.top().fi << " " << qA.top().se << endl;
    //     qA.pop();
    // }
    N = rd();
    int a,b;
    rep(i,1,N) {
        a = rd(); b = rd();
        if ( b == 1 ) {
            if ( qA.size() < 3 ) qA.push({a,i});
            else {
                if ( a > qA.top().fi ) {
                    qA.push({a,i});
                    qA.pop();
                }
            }
        } else {
            if ( qB.size() < 3 ) qB.push({a,i});
            else {
                if ( a > qB.top().fi ) {
                    qB.push({a,i});
                    qB.pop();
                }
            }
        }
    }
    int sumA = 0, sumB = 0;
    int idxA[4], idxB[4];
    int szA = qA.size(), szB = qB.size();

    if ( szA < 3 && szB < 3 ) {
        puts("null");
        return 0;
    }

    rep(i,1,szA) {
        sumA += qA.top().fi;
        idxA[i] = qA.top().se;
        qA.pop();
    }
    rep(i,1,szB) {
        sumB += qB.top().fi;
        idxB[i] = qB.top().se;
        qB.pop();
    }
    if ( sumA > sumB ) {
        if ( szA < 3 ) {
            puts("null");
            return 0;
        }
        // sort(idxA + 1, idxA + 1 + szA);
        rep(i,1,szA) printf("%d%c", idxA[i], " \n"[bool(i==3)]);
        puts("1");
        printf("%d\n", sumA);
    } else {
        if ( szB < 3 ) {
            puts("null");
            return 0;
        }
        // sort(idxB + 1, idxB + 1 + szB);
        rep(i,1,szB) printf("%d%c", idxB[i], " \n"[bool(i==3)]);
        puts("2");
        printf("%d\n", sumB);
    }

    return 0;
}