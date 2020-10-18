#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
const int M = 1e5+7;
int n,a[M],T,k;

int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n>>k;
        if(n%k==0 && ((ll)1+n)*n%(2*k)==0){
            cout<<"yes"<<endl;
            for(int i=1;i<=k;i++){
                cout<<i<<" "<<n-i+1<<endl;
            }
        }
        else cout<<"no"<<endl;
    }
    return 0;
}