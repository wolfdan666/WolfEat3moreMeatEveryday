// 2019年5月3日20:37:21开始看题
// 思路：从头扩散出去，然后看满足条件的地方(下标到了n-1就成为了叶子),最后数叶子数

#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll ans;

ll solve(int i,int n){
    if(i>=n-1) return 1;
    else if(s[i]=='0') return 0;
    else{
        if(s[i]<'3'){
            if(s[i]=='1'){
                ans += slove(i+1) + solve(i+2);
            }
            if(s[i]=='2'){
                if(s[i+1]){

                }
            }
        }
    }
}

int main(int argc, char const *argv[]){
    while(cin>>s&&s[0]!='0'){
        ans = 0;
        cout<<solve(0,int(s.length()))<<endl;
    }
    return 0;
}