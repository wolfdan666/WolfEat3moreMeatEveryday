#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for (int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const ll mod = 1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

// 这是基数排序所利用的子排序算法--稳定的 计数排序
void countSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;

    // 按照基数来排名(其实就是按照次数叠加)
    for (i = 1; i < 10; i++) count[i] += count[i - 1];

    // 从后面向前面循环,也就是利用了之前的排序,让之前排序大的继续优先排序大(突然想到了马太效应)
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++) arr[i] = output[i];
}

void radixsort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10) countSort(arr, n, exp);
}

int main() {

    return 0;
}