/*
2019年09月24日21:25:36 开始看题
2019年09月24日21:43:13 不会写，于是去看了李煜东老师提供的github库中的代码

2019年09月24日21:58:19 感觉这个算法真的太精妙了，这太考验思维了，竟然是这样假定高度计算的！要成为一个牛逼的ACMer就必须精通Dp，所以加油
*/

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const ll mod=1000000007;
// const int inf = 0x3f3f3f3f;
// inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
// const int N = 31;
// int n,k,a[N],F[N][N][N][N][N];
// ll ans;

// int main(){
// 	while(~scanf("%d%d",&n,&k)){
// 		ans = 0;
// 		memset(F,0,sizeof F);
// 		for(int i=1;i<=n;i++){
// 			a[i]=rd();
// 		}
// 		F[0][0][0][0][0] = 1;
// 	}

//     return 0;
// }



//Author:XuHt
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
int n[6], k;

void work() {
	for (int i = 1; i <= k; i++) cin >> n[i];
	while (k < 5) n[++k] = 0;
	ll f[n[1]+1][n[2]+1][n[3]+1][n[4]+1][n[5]+1];
	memset(f, 0, sizeof(f));
	f[0][0][0][0][0] = 1;
	for (int i = 0; i <= n[1]; i++)
		for (int j = 0; j <= n[2]; j++)
			for (int k = 0; k <= n[3]; k++)
				for (int l = 0; l <= n[4]; l++)
					for (int m = 0; m <= n[5]; m++) {
						if (i < n[1]) f[i+1][j][k][l][m] += f[i][j][k][l][m];
						if (j < n[2] && i > j) f[i][j+1][k][l][m] += f[i][j][k][l][m];
						if (k < n[3] && j > k) f[i][j][k+1][l][m] += f[i][j][k][l][m];
						if (l < n[4] && k > l) f[i][j][k][l+1][m] += f[i][j][k][l][m];
						if (m < n[5] && l > m) f[i][j][k][l][m+1] += f[i][j][k][l][m];
					}
	cout << f[n[1]][n[2]][n[3]][n[4]][n[5]] << endl;
}

int main() {
	while (cin >> k && k) work();
	return 0;
}