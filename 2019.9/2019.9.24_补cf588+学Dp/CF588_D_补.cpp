/*
2019年09月24日20:52:13 TLE on test 1! ===> 再也不要用cin,cout了
2019年09月24日20:57:13 WA on test 6！===> 我照着lxc大佬的代码写的！为什么wa了！
2019年09月24日21:05:20 傻逼了，我没有print lld!输出了一个%d
2019年09月24日21:06:54 	GNU C++11	Accepted	61 ms	600 KB

If there are multiple people with the same set of skills (i.e., the same values of a), it's optimal to take each of them to the camp as they won't think they're better than everyone else.

Now consider a person i which has a different set of skills than everyone else.

If they have a strictly smaller set of skills than someone already in the group, they can safely be included in the group.
If they don't, we can prove that they can't ever be included in the group.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
const int M = 7e3+10;
int n;
struct _{
	ll a;int b;
} f[M];
map<ll,int> cnt;

int main(){
	scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%I64d",&f[i].a);
    	++cnt[f[i].a];
    }
    for(int i=1;i<=n;i++) f[i].b = rd();
    ll ans=0;
	set<int> ss;
	for(auto t:cnt) if(t.second>=2){
		for(int i=1;i<=n;i++)
			if((f[i].a|t.first)==t.first) ss.insert(i);
	}
	for(auto t:ss) ans+=f[t].b;
	// printf("%d\n", ans);
	printf("%I64d\n", ans);


    return 0;
}


// xyyf	D - Marcin and Training Camp	GNU C++14	Accepted	108 ms
#include<bits/stdc++.h>
#define int long long
using namespace std;map<long long,long long>num;
int n,m,k,a[101010],b[101010],res[101000],val[101010],pt,ans,cnt;
main(){
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i],num[a[i]]++;if(num[a[i]]>=2)res[++pt]=a[i];}
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=pt;i++)for(int k=1;k<=n;k++)
		if((res[i]&a[k])==a[k])val[k]=1;
	for(int i=1;i<=n;i++)ans+=val[i]*b[i];
	cout<<ans;
}