/* 写到一半队友过了... */
/* 第一发还wa了50%.. */
/* 看了最快的做法，惊叹其之美(将条件用到极致) */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
int T;
string n,ans;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    while(T--){
        ans.clear();
        cin>>n;
        int tmp = 0,tmp2 = 0;
        for(int i=0;i<(int)n.length();i++){
            tmp = tmp*10 + (n[i] - '0');
            tmp2 += n[i] - '0';
        }
        /*mdzz,可能除不尽*/
        // int k = tmp / tmp2;
        int i;
        /*若n长度为1,则能达到最多1w位*/
        for(i=1;i<=10000;i++){
            if(tmp2*i%tmp==0) break;
        }
        for(int j=0;j<i;j++) ans+=n;
        cout<<ans<<endl;
    }

    return 0;
}


#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)printf("%d",n);
        printf("\n");
    }
}