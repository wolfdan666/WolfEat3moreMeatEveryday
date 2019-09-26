/*
2019年09月25日19:51:05 直接考虑终态,两者拥有相同的a,b,所以a,b总量必须都是偶数,否则-1
2019年09月25日20:11:11 找到了规律了，写起来(上a下b加入vector a,上b下a加入vector b,这样就很容易看出最优的交换规律)
2019年09月25日20:38:07 交了  wa on test 35！  还剩11mins
还剩50s的时候找到bug，然后改下面这几行直接交到7秒的时候交了，AC，吓死我了！！！电子竞技！刺激！！！
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
const int M = 2e5+7;
char s[M],t[M];
vector<int> a;
vector<int> b;
int n,ans;

int main(){
	n = rd();
	scanf("%s%s",s,t);
	for(int i=0;i<n;i++){
		// if(s[i]=='a'&&t[i]=='b') a.push_back(i);
		if(s[i]=='a'&&t[i]=='b') a.push_back(i+1);
		// else if(s[i]=='b'&&t[i]=='a') b.push_back(i);
		else if(s[i]=='b'&&t[i]=='a') b.push_back(i+1);
	}
	int cnt1 = a.size(), cnt2 = b.size();
    // 使用移位有很短的写法，但是为了易读，算了--> 还是写吧

	// for(int i=0;i<cnt1;i++) cout<<a[i]<<" \n"[i==cnt1-1];
	// for(int i=0;i<cnt2;i++) cout<<b[i]<<" \n"[i==cnt2-1];

    ans += (cnt1>>1) + (cnt2>>1);
	// 都为偶数
	bool f=0;
	if(cnt1&1){
		if(cnt2&1) ans+=2,f=1;
		else ans = -1;
	}
    // 还剩50s的时候找到bug，然后改下面这几行直接交到7秒的时候交了，AC，吓死我了！！！电子竞技！刺激！！！
	else if(cnt2&1){
		if(cnt1&1) ans+=2,f=1;
		else ans=-1;
	}
	cout<<ans<<endl;
	if(ans!=-1){
		if(f){
			for(int i=0;i<cnt1-1;i+=2){
				cout<<a[i]<<" "<<a[i+1]<<endl;
			}
			for(int i=0;i<cnt2-1;i+=2){
				cout<<b[i]<<" "<<b[i+1]<<endl;
			}
			// cout<<a[cnt1]<<" "<<a[cnt1]<<endl;
			// cout<<a[cnt1-1]<<" "<<a[cnt1-1]<<endl;
			cout<<a[cnt1-1]<<" "<<a[cnt1-1]<<endl;
			// cout<<a[cnt1]<<" "<<a[cnt2]<<endl;
			// cout<<a[cnt1-1]<<" "<<a[cnt2-1]<<endl;
			cout<<a[cnt1-1]<<" "<<b[cnt2-1]<<endl;
		} else {
			for(int i=0;i<cnt1;i+=2){
				cout<<a[i]<<" "<<a[i+1]<<endl;
			}
			for(int i=0;i<cnt2;i+=2){
				cout<<b[i]<<" "<<b[i+1]<<endl;
			}
		}
	}
    return 0;
}