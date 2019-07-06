// 我的思路是直接itoa，然后计算字符2的出现次数...其实好像不用，直接str相接，最终计算10000*4=4w 最长,4w字节==40K<<4G
// 写题的时候发现自己智障了... 其实取模就行

#include<bits/stdc++.h>
using namespace std;
int l,r;
int ans;

int check(int n){
    int cnt = 0;
    while(n){
        cnt += (n%10 == 2);
        n/=10;
    }
    return cnt;
}

int main(){
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        ans += check(i);
    }
    cout<<ans<<endl;
    return 0;
}