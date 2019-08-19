#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
int T,cnt;string s;
// bool f[110];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>s;
        cnt = 0;
        int sz = s.length();
        for(int i=0;i<sz;i++){
            if(s[i]=='y') continue;
            if(s[i]=='z'){ cnt++; s[i]='a';break;}
            else break;
        }
        /*没变过直接终止*/
        /*变过就变第一个不是y的*/
        if(cnt)
                for(int i=0;i<sz;i++){
                    if(s[i]!='y'){ s[i]++; break;}
                }
        cout<<s<<endl;
    }

    return 0;
}