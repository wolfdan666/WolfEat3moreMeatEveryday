/*
2019年09月26日20:15:04 开始看题
2019年09月26日20:17:26 想到了cnznb,砍龙救公主
- n个战略,x个龙头
- x=0胜利,
- n个策略,有d刀,砍下龙头min(d,x)个,如果龙没死,长出h个头!

通过优先策略组合-->求最少使用的策略数!

感觉应该是使用刀多的,长得少的,然后直接遍历?
砍不死的时候,优先使用能掉头的,然后砍得死就直接用

所以是两个结构体,两个排序???
10^11,还要小心long long

2019年09月26日21:01:03 写完测试,发现自己看错了题目,每种策略都可以多次使用!(加粗都没看到..)===> 那应该更简单!

2019年09月26日21:07:01 TLE on test 2! while(x)的弟弟行为
2019年09月26日21:15:51 wa on test 2...
2019年09月26日21:24:29 终于AC...妈的,VP快结束了,这个水平真的只能当pupil!哭了,还是要多多单人练习!
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
const int M = 110;
int t,n;
ll x;
struct P{
	int id,tp;
} a[M];
struct Q{
	int id,d;
} b[M];

bool cmp1(P a,P b){ return a.tp > b.tp; }
bool cmp2(Q a,Q b){ return a.d > b.d; }

int main(){
	t = rd();
	while(t--){
		n=rd();x=rd();
		// memset(vis,0,sizeof vis);
		for(int i=0;i<n;i++){
			int d=rd();int h=rd();
			a[i].id=b[i].id=i;
			b[i].d=d;
			a[i].tp=d-h;
		}
		sort(a,a+n,cmp1);
		sort(b,b+n,cmp2);
		int cnt=0;
		// 傻逼,写了两个if,没有continue
		if(b[0].d>=x){ printf("%d\n",++cnt); continue;}
		if(a[0].tp>0){
			cnt = (x-b[0].d)%a[0].tp==0 ? (x-b[0].d)/a[0].tp : (x-b[0].d)/a[0].tp+1;
			printf("%d\n",++cnt);
		}
		else puts("-1");

		// while(x){
		// 	if(b[0].d>=x){ printf("%d\n",++cnt); break;}
		// 	else{
		// 		// 这里肯定是没有用过的,因为前面判用过只是为了看是否能一套秒了,秒了就直接退出了,没秒就没用
		// 		// 而且这里肯定是没有一刀砍死的策略才进来的!不用担心x=0;
		// 		if(a[0].tp>0){
		// 			// vis[a[i].id]=1;
		// 			x-=a[0].tp;
		// 			cnt++;
		// 		}
		// 		else{ puts("-1");break;}
		// 	}
		// }
	}

    return 0;
}