/*
Let ri be the maximal segment of gold cups that begins in the cup i.
Let li be the maximum segment of gold cups that ends in the cup i. Also, let the total number of gold cups be cntG.

Note that it makes no sense to change the cups of the same color.
Then let's consider the silver cup, which will change with the gold cup, let its number be i. Then if ri+1+li−1<cntG,
then we will update the answer with the value ri+1+li−1+1, and otherwise with the value ri+1+li−1.
This will not work if all the cups are golden. In this case, the answer is n.

*/

#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
	
	cin >> n >> s;
	
	vector <int> l(n), r(n);
	for(int i = 0; i < n; ++i){
		if(s[i] == 'G'){
			l[i] = 1;
			if(i > 0) l[i] += l[i - 1];
		}
	}
	for(int i = n - 1; i >= 0; --i){
		if(s[i] == 'G'){
			r[i] = 1;
			if(i + 1 < n) r[i] += r[i + 1];
		}
	}
	
	
	int res = 0;
	int cntG = 0;
	for(int i = 0; i < n; ++i)
			cntG += s[i] == 'G';
			
	for(int i = 0; i < n; ++i){
		if(s[i] == 'G') continue;
		int nres = 1;
		if(i > 0) nres += l[i - 1];
		if(i + 1 < n) nres += r[i + 1];
		res = max(res, nres);
	}
	
	res = min(res, cntG);
	if(cntG == n) res = cntG;
	cout << res << endl;
	return 0;
}
