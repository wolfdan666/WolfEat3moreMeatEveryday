/*
2019年10月09日16:33:54 开始看题
2019年10月09日17:45:12 写了好久下面的题解,然后写完题解才写的code,现在才交,赶紧去吃饭先...wa on test 5...吃饭去,等下来
2019年10月09日18:18:14 回来发现是ans 偏大,应该是状态机哪里的ans维护写多了值
 而且答案是6,我是8,而且s3只要变成1,就一直为1,所以可能不是state 1的错
2019年10月09日19:08:13 输入情况发现,后面s1就等于6了...所以可能s1赋值出了点小问题

2019年10月09日19:11:14 写个暴力程序看下面例子最长的G是不是6===> 2019年10月09日19:15:40 测试结果是4...

300
SSGSGSSSGSGSSSSGGSGSSGGSGSGGSSSGSSGSGGSSGGSGSSGGSGGSSGSSSGSGSGSSGSGGSSSGSSGSSGGGGSSGSSGSSGSGGSSSSGGGGSSGSSSSSSSSGSSSSGSGSSSSSSSSGSGSSSSGSSGGSSGSGSSSSSSGSGSSSGGSSGSGSSGSSSSSSGGGSSSGSGSGSGGSGGGSSGSGSSSGSSGGSSGSSGGGGSGSSGSSSSGGSSSSGGSGSSSSSSGSSSGGGSGSGGSSGSSSSSSGGSSSGSSSSGGGSSGSSSGSGGGSSSSGSSSGSGSGGGGS

2019年10月09日19:28:24 wa on test 14...
Input
5
GGSSG
Output
2
Answer
3
Checker Log
wrong answer expected '3', found '2'

2019年10月09日19:50:23 终于AC了,绝了.....,这题搞了整整2个小时多...不舍得看tutorial...


2019年10月09日16:40:18
- 就定义s1,s2,s3
- s1和s2相隔一个字母,s3是备用字母
- 一开始检测s1,然后如果发现s1和s2相隔两个字母,那么就让s3=s1(其实s3只要记录有一个其他地方的G就行,只是为了填个间隔,所以直接让s3.len=1),ans = max(ans,s1.len),重新检测s1
- 如果s1,s2匹配上了,那么先算一次ans = max(ans,(s1+s2+s3).len),如果s3是0,后面检测到G,还要来一次前面的检测...
- 如果s2和新s3间隔相差1,然后再检测一遍ans后开始令s1=s2,s2.len=1
- 如果相差2,那么就重新找s1

实现:
- 我们通过状态机的思路来解题(发现真的好用!怪不得很多计算机系统的硬件编程都用了状态机)

- 状态0定义成: 启动
	- 遇到金,为了防止串结束退出,所以维护一下答案
- 状态1定义成: 我们正在检测s1(结合后面知道其实有没有s3是在后面考虑了,所以状态1没有分成两种状态) ---> 状态转移:
	- 遇到了空格(银),进入状态2
	- 遇到金,为了防止串结束退出,所以维护一下答案
- 状态2定义成: 我们遇到了s1+空格(银)的状态 ---> 状态转移:
	//- 如果遇到第二个0,维护答案,然后回到状态1
	- 如果遇到第二个0,维护答案,跳到状态6(这个状态一般比较难想到,是wa了几次之后才想到的...)
	- 如果遇到了G,那么我们进入状态3去检测s2
	- 遇到金,为了防止串结束退出,所以维护一下答案
- 状态3定义成: 我们遇到了s1+一个空格(银)+G,正在继续找s2 ---> 状态转移:
	//- 如果遇到了空格(银),那么我们再状态转移
	- 如果遇到了空格(银),那么我维护答案,跳到状态4检测是否还有空格
		// - 如果有s3,维护答案,跳到状态1  (当时看到大家都去吃饭,分心了,写差了...)
		//- 如果有s3,维护答案,跳到状态1
		//- 没有s3,检测s3,跳到4
	- 遇到金,为了防止串结束退出,所以维护一下答案
- 状态4: (s1+空格+s2+空格)可能的找s3并且观望下一个状态 ---> 状态转移:
	- 如果s2+空格+G.维护答案,跳到状态3(这里还要维护一些东西,要小心)
	- 找到了第二个空格,跳到状态5
- 状态5: 没有s3,然后目前s1+空格+s2+至少两个空格 ---> 状态转移:
	- 遇见G,维护答案,跳转状态1
- 状态6: 前面有仅有一部分s1,后面遇到两个或两个以上空格 ---> 状态转移:
	- 如果遇到G,那么ans = max(ans,s1+1),把后面这个移到前面维护一下,s3=1,然后跳转到状态1(这样就保证只有两部分连续G,并且这两部分相隔至少2个空格时能够互相搬运)
	- 没遇到继续停留在状态6

**注意遇到金,一定要维护一下.防止串结束退出**
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}
const int M = 1e5+10;
int n,s1,s2,s3,ans,state;
char s[M];

int main(){
	n = rd();
	scanf("%s",s); 
	rep(i,0,n-1){
		switch(state){
			case 0 : 
				if(s[i]=='G') state = 1,s1=1,ans = max(ans,s1+s3);

				cout<<s1<<" "<<s2<<" "<<s3<<endl;
				
				break;
			case 1 : 
				if(s[i]=='G'){ s1++,ans = max(ans,s1+s3);
				cout<<s1<<" "<<s2<<" "<<s3<<endl;
				}
				else if(s[i]=='S') state = 2;
				
				cout<<s1<<" "<<s2<<" "<<s3<<endl;
				break;
			case 2 : 
				if(s[i]=='G'){ state=3,s2=1,ans = max(ans,s1+s2+s3);
				cout<<s1<<" "<<s2<<" "<<s3<<endl;
				}
				else{
					// 我猜是wa在了这里,因为后面跳到的状态2不一定要加s2!
					// ans = max(ans,s1+s2+s3);
					ans = max(ans,s1+s3);
				cout<<s1<<" "<<s2<<" "<<s3<<endl;
					// 再来空格s1 = 0!!!
					// s1 = 1; s3 = 1;
					
					// s1 = 0; s3 = 1;
					// state = 1;
					
					state = 6;
				}
				
				break;
			case 3 : 
				if(s[i]=='G'){ s2++,ans = max(ans,s1+s2+s3);
				cout<<s1<<" "<<s2<<" "<<s3<<endl;
				}
				else{
					// if(s3) ans=max(ans,s1+s2+s3),state=1;
					// else state = 4;
					ans=max(ans,s1+s2+s3);
					state = 4;
				cout<<s1<<" "<<s2<<" "<<s3<<endl;
				}
				break;
			case 4 : 
				if(s[i]=='G'){
					ans=max(ans,s1+s2+1);
				cout<<s1<<" "<<s2<<" "<<s3<<endl;
					s3=1,s1=s2,s2=1;
					state = 3;
				} else {
					// 之前状态三遇到银之前的遇到金都有维护,所以这里可以不维护
					state = 5;
				}
				break;
			case 5 : 
				if(s[i]=='G'){
					s3=1;
					ans=max(ans,s1+s2+s3);
					cout<<s1<<" "<<s2<<" "<<s3<<endl;

					// 应该是wa在这,刚刚急着去吃饭,然后这里忘了改状态了...
					s1=1,s2=0;

					state = 1;
				}
				break;
			case 6 : 
				if(s[i] == 'G'){
					ans = max(ans,s1+1);
					s1=1,s3=1;
					state = 1;
				}
				break;
		}

	}
	printf("%d\n", ans);

    return 0;
}