/*
cd说他wa了，我才发现我也wa了...

艹，果然傻逼了，判断了第一位1没有判断后面位是0

*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
int n,k;
string s;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    cin>>s;
    if(k==0) { cout<<s<<endl; return 0;}
    if(n==1) { cout<<0<<endl; return 0;}
    for(int i=0;i<k;i++){
        if(i==0){
            if(s[i]=='1'){ if(k<n) k++;}
            else s[i]='1';
        }
        // else s[i] = '0';
        else{
            if(s[i]=='0'){if(k<n) k++;}
            else s[i] = '0';
        }
    }
    cout<<s<<endl;
    return 0;
}