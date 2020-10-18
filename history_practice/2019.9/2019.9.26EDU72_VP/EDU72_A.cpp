/*
2019年09月26日19:31:46 开始

T组q.
str 点力量, int 点智力. exp 的经验

2019年09月26日19:39:50 才读懂题目...

2019年09月26日20:01:20 时间才交...还wa on test 3...太菜了...写二分写半天还错了...还看书好久,没事,失败了,继续冲!一直冲!
// mid不能取c,但是可以取0,傻逼了!2019年09月26日20:14:01  AC
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
int a,b,c,T;

int main(){
	cin>>T;
	while(T--){
		a=rd();b=rd();c=rd();
		if(a+c<=b) printf("%d\n", 0);
		else{
			// mid不能取c,但是可以取0,傻逼了!2019年09月26日20:14:01 
			// int l=1,r=c;
			int l=0,r=c;
			int mid;
			while(l<r){
				mid = (l+r)>>1;
				if(a+mid>b+(c-mid)) r = mid;
				else l=mid+1;
			}

			// 二分求出加到的最少的点数,然后自然ans = [r,c] = r-c+1
			printf("%d\n", c-r+1);
		}
	}

    return 0;
}