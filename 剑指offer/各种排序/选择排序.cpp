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

// case : {5,5,2} --- 第一次交换了 0,2 下标的元素，破坏了相等元素之间的相对位置，所以不稳定

// 不稳定,因为两个相同的值,后面的值排序后排到了前面去了
template<typename T> //整数或浮点数皆可使用，若要使用物件（class）时必须设定大于（>）的运算子功能
void selection_sort(std::vector<T>& arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		int min = i;
		for (int j = i + 1; j < arr.size(); j++)
			if (arr[j] < arr[min])
				min = j;
		std::swap(arr[i], arr[min]);
	}
}

int main(){


    return 0;
}