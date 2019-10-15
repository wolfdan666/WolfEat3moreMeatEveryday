/*
2019年10月15日21:44:59 开始补题

2019年10月15日22:04:09 自闭得陷入了哲学思考,为啥大佬AC了.不用分左右两边谁先填充呢

因为大佬是让左右总是保持着相同的宽度权重的,然后左右之间能均摊到的剩下的k的高度是一样的!!!所以不管k还够不够把k加到哪一边都是一样的

是我菜了啊
*/

// By LittleBeetle, contest: Codeforces Round #592 (Div. 2), problem: (E) Minimizing Difference, Accepted, #, hack it!
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1000020;
int n,i,j,a[N],mid,opt;
long long k,s;
void init(){
	scanf("%d%lld",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
}
void work(){
	mid=n+1>>1;
	for(i=1;i<=mid;i++)
		s+=a[mid]-a[i];
	for(;i<=n;i++)
		s+=a[i]-a[mid];
	if(s<=k){
		printf("0");
		return;
	}
	i=1;j=n;
	opt=0;
	while(i+1<j){
		if(1ll*(a[i+1]-a[i])*i<=k){
			k-=1ll*(a[i+1]-a[i])*i;
			i++;
		}
		else{
			a[i]+=k/i;
			opt=1;
			break;
		}
		if(1ll*(a[j]-a[j-1])*(n-j+1)<=k){
			k-=1ll*(a[j]-a[j-1])*(n-j+1);
			j--;
		}
		else{
			a[j]-=k/(n-j+1);
			opt=1;
			break;
		}		
	}
	if(i+1==j&&opt==0)
		printf("%d",a[j]-a[i]-k/i);
	else
		printf("%d",a[j]-a[i]);
}
int main(){
	init();
	work();
	return 0;
}