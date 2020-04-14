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
union A { int x; int y[4]; };
struct B { A a; };
union C { B b; int k; };
int f() {
  C c;               // 不开始任何联合体成员的生存期
  c.b.a.y[3] = 4;    // OK："c.b.a.y[3]" 指名联合体成员 c.b 与 c.b.a.y;
                     // 这创建对象以保有联合体成员 c.b 和 c.b.a.y
  return c.b.a.y[3]; // OK：c.b.a.y 指代新创建的对象
}

struct X { const int a; int b; };
union Y { X x; int k; };
void g() {
  Y y = { { 1, 2 } }; // OK，y.x 为活跃联合体成员 (9.2)
  int n = y.x.a;
  cout<< "y.x.a: " << y.x.a << " y.x.b: " << y.x.b << endl;

  y.k = 4;   // OK：结束 y.x 的生存期，y.k 是联合体的活跃成员
  y.x.b = n; // 未定义行为：y.x.b 在其生存期外被修改，
             // "y.x.b" 指名 y.x，但 X 的默认构造函数被弃置，
             // 故联合体成员 y.x 的生存期不会隐式开始
  cout<< "y.x.b: " << y.x.b << endl;

}


void g_myTest(){
  Y y = { { 1, 2 } }; // OK，y.x 为活跃联合体成员 (9.2)
  int n = y.x.a;
  cout<< "y.x.a: " << y.x.a << " y.x.b: " << y.x.b << endl;
  y.k = 4;   // OK：结束 y.x 的生存期，y.k 是联合体的活跃成员
  // y.x = {n,n}; // 未定义行为：y.x.b 在其生存期外被修改，
             // "y.x.b" 指名 y.x，但 X 的默认构造函数被弃置，
             // 故联合体成员 y.x 的生存期不会隐式开始
  // cout<< "y.x.b: " << y.x.b << endl;
}

int main(){
    cout<<"f(): "<< f() <<endl;
    g();
    g_myTest();

    return 0;
}

/*
f(): 4
y.x.a: 1 y.x.b: 2
y.x.b: 1
y.x.a: 1 y.x.b: 2

*/