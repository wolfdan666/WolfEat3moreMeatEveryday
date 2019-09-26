/* 
2019年09月26日11:41:35 开始看题
2019年09月26日11:51:24 去吃饭,边吃边想题
2019年09月26日14:20:40 开始写
2019年09月26日14:46:00 发现自己B的落子没有写好,重改
2019年09月26日14:55:16 发现样例三都错了,输出一下数据
2019年09月26日15:10:24 才交,坑... wa on test 5... 傻逼,写了50mins还wa了,实现速度还是要多多练习!-->以及要多思考!
80
????66??8?0?????0??8?45?328??0?6???121038??????4?17??12847??3??65??6?????2????62

傻逼了,写错了,写得时候分情况讨论没写好,写错了一些,应该简化思路思考成为,M想要数字的abs变大,然后B想要tp为0,这样就会写得更快更好,更不容易出错...

...2019年09月26日15:19:19 发现自己整个思路是错的!
我凭什么要顺序落子!?非循序落子反而能取得更优解!所以思路是错的!重写!

# 题意
- n个数字的车牌,n是偶数(n $/in$ [2,2\*$10^5$])
- 一些车牌偶数个数字被搽除了
- 定义美丽车牌的是` 前n/2个数字的数字和 == 后n/2个数字的数字和 `
- M讨厌美丽车牌,而B喜欢
- 玩一个游戏, M先手改被搽除的数字成为0-9中的一个(直到数字被填完)
- 数字填完是美丽的则 B win,否则 M win
a
# 题解
- 总体来说就是M极力去破坏,然后B极力去维护
- 先计算之前的左右的和值,如果左边大于右边,则是左到右遍历
    - 然后左半边M填9,B填0
    - 右半边M填0,B填9
    - 每次填完之后又要开始计算左右两边的和值
    - 最后一个M判断是否可以填0到9之间的数就行了

- 写到一半发现要特判B的落子,不一定每次都0,9,而是可以让相等的时候直接让相等!
- 这样就不用特判i == sz了...
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
const int M = 2e5+7;
int n,tp;
char s[M];
vector<int> somechange;

int main(){
	while(~scanf("%d",&n)){
		scanf("%s",s+1);
		somechange.clear();

		for(int i=1;i<=n;i++){
			if(s[i]!='?') tp = i<=n/2 ? tp+s[i]-'0' : tp-(s[i]-'0');
			// somechange.push_back(i); 傻逼,这里忘了加else
			else somechange.push_back(i);
		}

		cout<<"tp init: "<<tp<<endl; 

		int sz = somechange.size();
		if(sz){
			// i的奇偶判断谁在下棋
			for(int i=1;i<=sz;i++){
				// j 是 原来的下标位置

				// 2019年09月26日15:03:36 卡负1 这里,傻逼了
				// int j = somechange[i]; 
				int j = somechange[i-1]; 

				// 注意左边落子是加  **右边是减**
				// 左边大
				if(tp>=0){
					// 左右落子判断
					if(j <= n/2){
						if(i&1) tp+=9;
						// else if(tp >= -9 && tp <= 0) tp = 0;
						else tp+=0;
					} else {
						if(i&1) tp+=0;
						else if(tp >=0 && tp <= 9) tp = 0;
						else tp-=9;
					}
				} else {
					if(j <= n/2){
						if(i&1) tp-=0;
						else if(tp >= -9 && tp <= 0) tp = 0;
						else tp+=9;
					} else {
						if(i&1) tp-=9;
						else tp-=0;
					}
				}
				cout<<"j: "<<j<<" tp : "<<tp<<endl;
			}
		}
		printf("%s\n",tp ? "Monocarp" : "Bicarp" );
	}

    return 0;
}

 