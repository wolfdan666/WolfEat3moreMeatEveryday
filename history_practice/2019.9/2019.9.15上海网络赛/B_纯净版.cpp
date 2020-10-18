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
    T = read();
    int kase = 1;
    while(T--){
        n = read(),m = read();
        if(!b.empty()) b.clear();
        ans = 0,sum = 0;
        while(m--){
            l = read(),r = read();

            l++,r++;

            a[l]--;a[r+1]++;
            b.push_back(l),b.push_back(r+1);
        }
        // 先排序，因为unique只从左到右顺序查重，然后unique得到最后一个被删除的位置，用erase搽除尾部
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()),b.end());

        int sz = b.size();
        sum+=a[b[0]];
        a[b[0]] = 0;
        for(int i=1;i<sz;i++){
            if(sum&1) ans+=b[i]-b[i-1];
            sum+=a[b[i]];
            a[b[i]] = 0;
        }
        if(sum&1) ans+=n+1-b[sz-1];
        printf("Case #%d: %d\n",kase++,ans);
    }

    return 0;
}