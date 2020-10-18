/* 
2019年10月02日20:27:35 看题
2019年10月02日20:30:48 感觉这题和CF589_C有点像,果然是同一个作者出的题目

感觉答案是跳动的正反对角线 ---> 数量应该是可以用一个和n有关的式子表达出来(sum) ---> 从而保证min1的操作
然后 就是其他的受min1影响的 n^2 - n 个格子都有k种选择,也就是 tp = (n*(n-1))^k
但是还差一个去重n2个!!!这是最麻烦的地方!   ans= sum*tp-n2 (%mod)

去重应该还跳动的正反对角线结合起来?

2019年10月02日20:40:09 决定还是看tutorial,快速见识一下世面

https://codeforces.com/blog/entry/70162

看晕了,自闭,看不懂,,,不看了......金牌题2300分...但是还是看一下吧,因为我要冲金牌

nlog(n) 的做法完全看不懂,n^3的做法能看懂一点点.但是最终答案不应该是f[n][0]吗?
 */
// Standard libraries
#include <stdio.h>
#include <vector>
 
// Typedef
typedef long long int lld;
const lld mod = 1000 * 1000 * 1000 + 7;
 
// Clean
lld clean(lld x){
    x %= mod;
    if(x<0) x += mod;
    return x;
}
 
// x^n
lld power(lld x, lld n){
    if(n==0) return 1;
    x = clean(x);
    lld half = power(x, n/2);
    if(n%2 == 0) return half*half%mod;
    else return half*half%mod*x%mod;
}
 
int main(int argc, char **argv){
 
#ifdef __McDic__ // Local testing I/O
    freopen("VScode/IO/input.txt", "r", stdin);
    freopen("VScode/IO/output.txt", "w", stdout);
#endif
 
    // Get input
    lld n, k; scanf("%lld %lld", &n, &k);
    std::vector<std::vector<lld>> f(n+1, std::vector<lld>(n+1, -1)); // Answer
    if(k==1){printf("1\n"); return 0;} // edge case
 
    // nCr combination
    std::vector<std::vector<lld>> nCr(n+1, std::vector<lld>(n+1, -1));
    for(int front=0; front<=n; front++){
        nCr[front][0] = 1, nCr[front][front] = 1;
        for(int back=1; back<front; back++) nCr[front][back] = (nCr[front-1][back-1] + nCr[front-1][back]) % mod;
    }
 
    std::vector<lld> kpower = {1}, k1power = {1};
    for(int i=1; i<=n; i++){
        kpower.push_back(kpower.back() * k % mod);
        k1power.push_back(k1power.back() * (k-1) % mod);
    }
 
    // f(r, 0) = (k^n - (k-1)^n)^r
    for(int r=1; r<=n; r++) f[r][0] = clean(power(power(k, n) - power(k-1, n), r));
    // f(1, c) = k^(n-c) (c>=1)
    for(int c=1; c<=n; c++) f[1][c] = power(k, n-c);
 
    // f(r, c) = (k^(n-c) - (k-1)^(n-c)) f(r-1, c) + for_{c0} k^(n-c) [c]C[c0] f(r-1, c-c0)
    for(int r=2; r<=n; r++) for(int c=1; c<=n; c++){
        //if(c==n) f[r][c] = 0;
        //else f[r][c] = clean(power(k, n-c) - power(k-1, n-c)) * power(k-1, c) % mod * f[r-1][c] % mod;
        f[r][c] = clean(kpower[n-c] - k1power[n-c]) * k1power[c] % mod * f[r-1][c] % mod;
        for(int c0=1; c0<=c; c0++){
            //f[r][c] += power(k-1, c-c0) * power(k, n-c) % mod * nCr[c][c0] % mod * f[r-1][c-c0] % mod;
            f[r][c] += k1power[c-c0] * kpower[n-c] % mod * nCr[c][c0] % mod * f[r-1][c-c0] % mod;
            f[r][c] %= mod;
        }
    }
    printf("%lld\n", f[n][n]);
    // printf("%lld   %lld\n",f[n][0], f[n][n]);
    return 0;
}