/*
有一说一,这个题目真的是恶心!

我第三遍写,发现这样贪心最终也是不对的,还是没有考虑到全面的情况!因为有种可能是左边还剩两个??,右边使左右两边差距变成0了...===> 然而实际策略应该是先限制别人,然后自己被限制,然后死掉
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
		printf("%s\n",tp ? "Monocarp" : "Bicarp" );		
	}	 

    return 0;
}