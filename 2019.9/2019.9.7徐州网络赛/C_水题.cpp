/*
题意：给定一个整数w表示西瓜的重量，切成两半之后每一部分都是2的倍数公斤。如果 满足要求输出YES，否则输出NO
题解：判断w是否能被2整除，另外还需要考虑w的值不能为2（分成两半之后各自为1， 不是2的倍数）。

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    if(n%2==0&&n!=2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}

