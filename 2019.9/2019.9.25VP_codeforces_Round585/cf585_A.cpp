/*
2019年09月25日19:09:09 才交！ wa on test7！
2019年09月25日19:17:42 发现自己傻逼了，ansmin没有判断为负数

2019年09月25日19:19:06 AC  ---> 发现sublime下搜狗输入法有问题！！！---所以暂时使用VScode来打完这场比赛
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
int a1,a2,k1,k2,n;

int main(){
	a1 = rd(); a2 = rd(); k1 = rd(); k2 = rd(); n = rd();
	int base = a1*(k1-1) + a2*(k2-1);
	int top = a1*k1 + a2*k2;
	if(n>=top) {cout<<a1+a2<<" "<<a1+a2<<endl; return 0;}
	// int ansmin = n - base;
	int ansmin = n - base > 0 ? n-base : 0;
	int mi=k1;bool f=0;
	if(k1>k2){
		mi = k2; f=1;
	}
	int ansmax;
	if(f){
		if(n/k2>=a2){
			ansmax = a2;
			n -= a2*k2;
			ansmax += n/k1;
		}
		else{
			ansmax = n/k2;
		}
	} else {
		if(n/k1>=a1){
			ansmax = a1;
			n -= a1*k1;
			ansmax += n/k2;
		}
		else{
			ansmax = n/k1;
		}
	}
	cout<<ansmin<<" "<<ansmax<<endl;

    return 0;
}