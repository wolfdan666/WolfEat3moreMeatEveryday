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

void insertion_sort(int arr[], int length){
    int i,j;
    // 从无序区选择数据插入到前面的有序区
    for (i = 1; i < length; i++) {
        int tmp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > tmp; j--){
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}

int shellSort(int arr[], int n){
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i += 1){
            int temp = arr[i];
            int j;
            // 注意这里的j>=gap的时候还是会重复比较
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

int main(){

    return 0;
}