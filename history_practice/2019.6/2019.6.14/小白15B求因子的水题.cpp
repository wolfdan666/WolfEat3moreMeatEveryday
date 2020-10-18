#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,T;
    cin>>T;
    while(T--) {
        cin>>n;
        if(n==1){ cout<<1<<endl;continue;} // 还好自己测了一下边界
        int ans = 2;
        for(int i=2;i<n;i++){
            if(n%i==0) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}