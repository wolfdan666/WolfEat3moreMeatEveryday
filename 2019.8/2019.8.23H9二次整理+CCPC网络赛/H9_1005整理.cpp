#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
int T;string s;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>s;
        /*没变过直接终止*/
        /*变过就变第一个不是y的*/
        int sz = s.length();
        for(int i=0;i<sz;i++){
            if(s[i]=='y') continue;
            if(s[i]=='z'){ s[i]='b';break;}
            else break;
        }
        cout<<s<<endl;
    }

    return 0;
}