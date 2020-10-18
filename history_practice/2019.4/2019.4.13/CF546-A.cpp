// 2019年4月13日19:56:32开始看题
// 2019年4月13日20:04:33 AC,慢了
#include<bits/stdc++.h>
using namespace std;
int a[10010];

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int l,r;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        for(int j=l;j<=r;j++){
            a[j]=n-i;
        }
    }
    int k;
    cin>>k;
    cout<<a[k]<<endl;
    return 0;
}