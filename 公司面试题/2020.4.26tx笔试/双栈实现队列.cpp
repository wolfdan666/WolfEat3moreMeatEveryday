/*
2020年4月26日20:36:04 这个做过,冲
但是为啥这里的输入输出不做限制？
难道人工判题？？？

2020年4月26日20:49:23 AC
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
int N;
string S;
int val;

class que
{
public:
    void add(int node) {
        stack1.push(node);
    }

    int poll() {
        if(stack2.size()<=0){
            while(stack1.size()>0){
                int data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }

        }

        // stk2.sz == 0 异常处理

        int ans = stack2.top();
        stack2.pop();
        return ans;
    }

    int peek(){
        if(stack2.size()<=0){
            while(stack1.size()>0){
                int data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }

        }

        // stk2.sz == 0 异常处理

        int ans = stack2.top();
        // stack2.pop();
        return ans;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
    N = rd();
    que q;
    while(N--){
        cin>>S;
        if("add" == S){
            val = rd();
            q.add(val);
        } else if("peek" == S){
            cout<< q.peek() << endl;
        } else {
            q.poll();
        }
    }

    return 0;
}