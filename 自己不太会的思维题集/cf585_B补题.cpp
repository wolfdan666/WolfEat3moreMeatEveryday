/* 
大佬tutorial的代码
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200 * 1000 + 13;

int n;
int a[N];

inline void read() {	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

inline void solve() {
	int pos = -1;
	ll ans0 = 0;
    // 题目给的是a[i]!=0,大佬还要特地考虑一下鲁棒性
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			pos = i;
		}
		if (pos != -1) {
			ans0 += pos + 1;
		}
	}
    // bal是负数的个数，cnt1标识前面负数的对数，cnt2标识前面的正数的个数
    // ansP是正产的个数，负产个数可以直接用总的pair数减去ansP得到

    // cnt1其实是偶数对之前的所有元素的个数,比如-1 1 -1 `1 1 1` -1 -1 这样cnt1=3
	// cnt2同理就是奇数个负数之间的个数,这些都是为了后面的计算!所以上面的例子cnt2=1
    // 太精妙了!
    int cnt1 = 0, cnt2 = 0;
	int bal = 0;
	ll ansP = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			cnt1 = 0, cnt2 = 0, bal = 0;
			continue;
		}
		if (bal % 2 == 0) {	
			cnt1++;
		} else {
			cnt2++;
		}
		if (a[i] < 0) {
			bal++;
		}
        // 这里之所以可以这样加tutorial没说，其实是因为每次新加入之后
        // 新产生的pair一定是以a[i]作为右endpos的!所以可以这样加!

        // 到了a[i]后总负数个数是偶数,所以加所有偶数对间的cnt1值,
        // 可以心想一下a[i]为正或者负的时候 bal达到偶数值时的状态就懂了
		if (bal % 2 == 0) {
			ansP += cnt1;
		} else {
			ansP += cnt2;
		}
	}
	cout << n * 1ll * (n + 1) / 2 - ans0 - ansP << ' ' << ansP << endl;
}

int main () {
#ifdef fcspartakm
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    srand(time(NULL));
    cerr << setprecision(10) << fixed;
    
    read();
    solve();
    
    return 0;
    //cerr << "TIME: " << clock() << endl;
}