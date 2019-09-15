/*
需要离散化到O(m)

但是离散化损失了区间长度..我咋计数..不会啊..12点39分先改cd的线段树

12点55分发现内存大小跑不了线段树...


case忘了++,wa一发
然后memset还是让复杂度O(T*n)...TLE..
我在a[i]加入sum之后让它归0，就不用memset...还是TLE

然后加了快读才过...13点52分
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e6+10;
int a[M],T,n,m,l,r,ans,sum;
vector<int> b;

inline int read() {
    int x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for (;isdigit(ch);ch=getchar())x=x*10+ch-'0';return x*f;
}

int main(){
    // ios::sync_with_stdio(false);cin.tie(0);
    // cin>>T;
    T = read();
    int kase = 1;
    while(T--){
        // cin>>n>>m;
        n = read(),m = read();
        // memset(a,0,sizeof a);
        if(!b.empty()) b.clear();
        ans = 0,sum = 0;
        while(m--){
            // cin>>l>>r;
            l = read(),r = read();

            l++,r++;

            a[l]--;a[r+1]++;
            b.push_back(l),b.push_back(r+1);
        }

        // 待巩固--->ok
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()),b.end());

        // for(int i=0;i<=n;i++) cout<<a[i]<<" \n"[i==n];

        // for(int i=1;i<=n;i++){
        //     a[i]+=a[i-1];
        //     if(a[i]%2) ans++;
        // }
        int sz = b.size();
        sum+=a[b[0]];
        a[b[0]] = 0;
        for(int i=1;i<sz;i++){
            if(sum&1) ans+=b[i]-b[i-1];
            // if(sum%2) ans+=b[i]-b[i-1];
            sum+=a[b[i]];
            a[b[i]] = 0;
        }
        // if(sum%2) ans+=n+1-b[sz-1];
        if(sum&1) ans+=n+1-b[sz-1];

        // for(int i=0;i<=n;i++) cout<<a[i]<<" \n"[i==n];
        printf("Case #%d: %d\n",kase++,ans);
        // cout<<"Case #"<<kase++<<": "<<ans<<endl;
    }

    return 0;
}