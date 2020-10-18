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

void heapify(int arr[], int n, int i) {
    // 这里对arr[]中序列化的值按照类似满二叉树的逐层读取的规则来的
    int largest = i;    // 将最大元素设置为堆顶元素
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    // 如果 left 比 root 大的话
    if (l < n && arr[l] > arr[largest]) largest = l;

    // I如果 right 比 root 大的话
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        // 递归地定义子堆,当子堆的最大被上层取走之后,那么要更新子堆
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // 建立堆
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

    // 一个个从堆顶取出元素
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {


    return 0; 
}