/*
作者：我要哒哒哒offer
链接：https://www.nowcoder.com/discuss/379137?type=2&order=0&pos=2&page=1
来源：牛客网
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

// 顺时针旋转
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n < 2)return;
    //1. 交换对角元素
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < i; ++j){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    //2. 每一行逆序
    for (int i = 0;i < n;++i){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    vector<vector<int> > a;
    vector<int> tmp;
    rep(i,0,3){
        rep(j,0,3){
            tmp.pb((4*i+1)+j);
        }
        a.pb(tmp);
        tmp.clear();
    }

    puts("source:");
    for(auto i:a){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    rotate(a);

    puts("dest:");
    for(auto i:a){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    return 0;
}
