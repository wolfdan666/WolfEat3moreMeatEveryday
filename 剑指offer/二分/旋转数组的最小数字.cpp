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

// 其实我一直觉得class public中不用把引用的函数声明在前面很神奇
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int sz = rotateArray.size();
        if(sz <= 0) return 0;

        int i1 = 0;
        int i2 = sz - 1;
        // 为了判断原来就有序
        int mid = i1;
        while(rotateArray[i1] >= rotateArray[i2]){
            if(i2 - i1 == 1){ mid = i2 ; break; }

            mid = (i1+i2)>>1;

            if(rotateArray[i1] == rotateArray[i2] && rotateArray[i1] == rotateArray[mid])
                return minInOrder(rotateArray,i1,i2);

            if(rotateArray[mid] >= rotateArray[i1]) i1 = mid;
            if(rotateArray[mid] <= rotateArray[i2]) i2 = mid;
        }

        return rotateArray[mid];
    }

    int minInOrder(vector<int> numbers,int x,int y){
        int ans = numbers[x];
        for(int i=x;i<=y;i++){
            if(ans>numbers[i]) ans = numbers[i];
        }

        return ans;
    }
};

int main(){


    return 0;
}