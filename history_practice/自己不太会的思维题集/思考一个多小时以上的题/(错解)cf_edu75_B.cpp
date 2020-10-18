/*
2019年10月24日23:22:53 开始看题

读懂了题意:
让0,1重新排列,保留各个串的串长,然后看最多有多少个回文串

2019年10月24日23:28:51 继续思考

1. 由于0,1的等价性,所以根本就不会有串之间偶数个字符的交换!所以一定是换奇数个相同的字符
2. 然后如果串len是奇数,那么一定是可以回文的
3. 如果是偶数就要和其他字串借用较少的那种字符
    3.1 最好的借法就是和奇数长的串来借(可以直接丢入0,1池)
    3.2 次好的方法是和其他的偶数长的串直接加入一个0,1池,然后优先分给len小的串

对,应该就是这样模拟实现

2019年10月25日00:18:18 感觉一半一半的策略也是可以的啊!和直接全选是一样的
但是要从大到小一半一半,这样不会用掉的部分就可以最小化,甚至还可以被后面的利用上


2019年10月25日00:46:15 wa on test2...

突然感觉不用大于base,因为base无用啊..肯定会留给后面的,但是还是wa on 2

2019年10月25日01:00:06 发现自己想错了,不用必须一半1,一半0,只要偶数个1或者0就行!
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
int Q,n,zs,os,ans,base;
string t;
struct str{
    // string t;
    int len,z,o;
} s[55];
multiset<int> tmp;

int main(){
    // ios::sync_with_stdio(false);
    // 好像混用了getchar()和cout,然后cf上运行错误了
    Q = rd();
    while(Q--){
        n = rd();
        zs = 0,os = 0;base = 0;ans = 0;
        tmp.clear(); // 傻逼了.卡了7mins
        rep(i,1,n){
            cin>>t;
            s[i].len = t.length();
            // rep(i,0,s[i].len-1){

            // 傻逼卡了好久...10mins
            s[i].z=s[i].o=0;

            rep(j,0,s[i].len-1){
                t[j]-'0' ? s[i].o++ : s[i].z++;
                // 上面不知道为什么没有加...
                // if(t[i]-'0') s[i]
                // 傻逼用了两次i
            }
            zs+=s[i].z;os+=s[i].o;
            if(s[i].len&1){
                ans++;base+=s[i].z+s[i].o;
            } else {
                // int tp = s[i].len / 2;
                // if(zs>=tp && os>=tp) zs-=tp,os-=tp;
                // 如果不行,他们的资源直接被强行配置了,给别人了,最后再丢给他们
                // 但是突然想到另外的一种情况就是偶数也可以全1 或者 全0 !
                // 可以最后一起分,然后最后优先最短的先分,并且一半一半地分
                tmp.insert(s[i].len);
            }
        }
        // cout<<"ALL zs: "<<zs<<" os: "<<os<<endl;
        // for(auto x:tmp){
        // for (multiset<int>::reverse_iterator rit=tmp.rbegin() ; rit!=tmp.rend(); ++rit){
        //     int x = *rit;
        //     int tp = x/2;
        //     if(zs>=tp && os>=tp /*&& zs+os>=x+base*/) zs-=tp,os-=tp,ans++;
        //     // 此时有一种被分`光`了-->>[0,tp]之间(后面tp越来越大,所以不购分)
        //     // 那为啥不给小的全分那个剩余的值,然后让大的凑一半一半岂不是更好?
        //     else if(zs>=x/*+base*/) zs-=x,ans++;
        //     else if(os>=x/*+base*/) os-=x,ans++;

        //     // cout<<"base: "<<base<<" x: "<<x<<" zs: "<<zs<<" os: "<<os<<endl;
        // }
        int tp = min(zs,os);
        ans+=tp/2;
        cout<<ans<<endl;
    }

    return 0;
}