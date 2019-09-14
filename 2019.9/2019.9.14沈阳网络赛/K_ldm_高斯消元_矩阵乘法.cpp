/*

2019年9月14日15:01:58 队友在math上面这么牛逼了，自己可不能在字符串上面给队友掉链子！！！


lxc 14:36:12
K题题意又看懂的吗

ldm 14:36:27
高斯消元+矩阵快速幂吧

ldm 14:36:30
我在找板子

ldm 14:37:15
就是f(i)=p1*f(i-1)+..+pk*f(i-k)

lxc( ) 14:37:49
f前k项是不是就是a_i

ldm 14:38:03
i>2k

ldm 14:38:15
i>k的时候就是了

ldm 14:38:25
前k项固定的

lxc( ) 14:38:50
p_k是个啥

ldm 14:38:58
概率

ldm 14:39:09
高斯消元搞

lxc( ) 14:39:20
p_k咋求的

ldm 14:39:41
对k+1~2k列方程组啊

ldm 14:40:04
第k+1到2k项的f都知道了

ldm 14:41:08
样例2就是
5 = 6*p1+5*p2
5 = 5*p1+5*p2

ldm 14:41:18
所以后面全是5了

ldm 14:41:33
然后前8项的和就是5*7+6=41



*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const LL INF = 1e18;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 1e5 + 10;
const int maxn = 200;
LL qpow(LL x, LL y, LL MOD) {LL a=1; while(y){ if(y&1) a=a*x%MOD; x=x*x%MOD; y>>=1; } return a;}

LL a[maxn][maxn], x[maxn];
LL gcd(LL a,LL b)
{
    while(b)
    {
        int t = b;
        b = a%b;
        a = t;
    }
    return a;
}

LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}

LL inv(LL a,LL m)
{
    return qpow(a, mod-2, mod);
}

void Gauss(int equ,int var)
{
    int max_r,col,k;

    for(k = 0, col = 0; k < equ && col < var; ++k,++col)
    {
        max_r = k;
        for(int i = k+1; i < equ; ++i)
            if(abs(a[i][col]) > abs(a[max_r][col]))
                max_r = i;
        if(a[max_r][col] == 0)
        {
            --k;
            continue;
        }
        if(max_r != k)
            for(int j = col; j < var+1; ++j)
                swap(a[k][j],a[max_r][j]);
        for(int i = k+1; i < equ; ++i)
        {
            if(a[i][col] != 0)
            {
                LL LCM = lcm(abs(a[i][col]),abs(a[k][col]));
                LL ta = LCM/abs(a[i][col]);
                LL tb = LCM/abs(a[k][col]);
                if(a[i][col]*a[k][col] < 0) tb = -tb;
                for(int j = col; j < var+1; ++j)
                    a[i][j] = ((a[i][j]*ta-a[k][j]*tb)%mod+mod)%mod;
            }
        }
    }
    for(int i = var-1; i >= 0; --i)
    {
        LL temp = a[i][var];
        for(int j = i+1; j < var; ++j)
        {
            if(a[i][j] != 0)
            {
                temp -= a[i][j]*x[j];
                temp = (temp%mod+mod)%mod;
            }
        }
        x[i] = (temp*inv(a[i][i],mod))%mod;
    }
}

struct Matrix {
    int sz;
    LL a[75][75];
    void init() {
        memset(a, 0, sizeof(a));
    }
    Matrix(int SZ) {
        sz = SZ;
        this->init();
    }
    Matrix operator * (const Matrix& t) const {
        Matrix ans(sz);
        for(int k = 0; k < sz; k++)
            for(int i = 0; i < sz; i++) if(a[i][k])
                for(int j = 0; j < sz; j++)
                    ans.a[i][j] = (ans.a[i][j]+a[i][k]*t.a[k][j])%mod;
        return ans;
    }
    void print() {
        rep(i, 0, sz-1) {
            rep(j, 0, sz-1) {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
Matrix qpow(Matrix A, LL b) {
    Matrix res(A.sz); res.init();
    for(int i = 0; i < A.sz; i++) res.a[i][i] = 1;
    while(b) {
        if(b & 1) res = res*A;
        A = A*A;
        b >>= 1;
    }
    return res;
}


LL f[150], sum[150];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int k;
        LL n;
        scanf("%d%lld", &k, &n);
        rep(i, 0, 2*k-1) {
            scanf("%lld", &f[i]);
            if(i) sum[i] = (sum[i-1]+f[i])%mod;
            else sum[i] = f[i]%mod;
        }
        if(n <= 2*k) {
            printf("%lld\n", sum[n]);
            continue;
        }
        rep(i, 0, k-1) {
            rep(j, 0, k-1) {
                a[i][j] = f[i+k-j-1];
            }
            a[i][k] = f[i+k];
        }
        Gauss(k, k);
        Matrix A(k+1);
        rep(i, 0, k-2) A.a[i][i+1] = 1;
        rep(i, 0, k-1) A.a[k-1][i] = A.a[k][i] = x[k-1-i];
        A.a[k][k] = 1;
        //A.print();
        A = qpow(A, n-2*k);
        LL ans = 0;
        rep(i, 0, k-1) ans = (ans + 1LL*A.a[k][i]*f[k+i])%mod;
        ans = (ans + sum[2*k-1]) % mod;
        printf("%lld\n", ans);
    }

    return 0;
}