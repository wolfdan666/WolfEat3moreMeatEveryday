/*
2019年09月26日15:22:37 
其实根本不用记录什么位置.只要分左右还可以落子的个数以及tp(左边减去右边的差值来判断最优解就行了)

2019年09月26日15:44:51 发现好像有系统的一些原因,导致代码重用有问题..先去上课,等下来测1

玄学,发现测多组的时候有些输入的 答案 可能每次不同! 然后 wa on test 35 , 不折腾了,快点看tutorial!
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
const int M = 2e5+5;
int n,tp,cnt1,cnt2,sum;
char s[M];

int main(){
	while(~scanf("%d",&n)){
		scanf("%s",s+1);
		// 因为
			// cout<<cnt1<<" "<<cnt2<<endl;
		// cnt1=cnt2=0;
		for(int i=1;i<=n;i++){
			if(s[i]!='?') tp = i<=n/2 ? tp+s[i]-'0' : tp-(s[i]-'0');
			else{
				if(i<=n/2) cnt1++;
				else cnt2++;
			}
		}
		
		sum = cnt1 + cnt2;
		if(sum){
			for(int i=1;i<=sum;i++){
				if(tp>=0){
					if(i&1){
						if(cnt1) tp+=9,cnt1--;
						// 左边不能变大,那我可以阻止右边变大!
						else cnt2--;
					} else {
						if(cnt2) if(tp<=9) tp=0,cnt2--;else tp-=9,cnt2--;
						// 右边不能变大了,不能缩小tp了,那我也不让你左边再变大
						else cnt1--;
					}
				} else {
					if(i&1){
						if(cnt2) tp-=9,cnt2--;
						else cnt1--;
					} else {
						if(cnt1) if(tp>=-9) tp=0,cnt1--;else tp+=9,cnt1--;
						else cnt2--;
					}
				}
			}
		}
			// cout<<cnt1<<" "<<cnt2<<endl;
		printf("%s\n",tp ? "Monocarp" : "Bicarp" );		
	}	 

    return 0;
}