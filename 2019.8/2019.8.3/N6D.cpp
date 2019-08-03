/*2019年8月3日12:33:47 发现大家都wa了！难到不是要最优？而是模拟题意？
每次放最大合适体积==然后最大数量
2019年8月3日12:55:57 2/183...然而我死循环了
2019年8月3日13:26:53 WA了,难受啊！想一下Corner Case
2019年8月3日14:16:24 继续debug
2019年8月3日14:40:37 感觉没啥问题的代码啊...换一题想想先把


2019年8月3日16:27:05 随意输入--找到了反例！--还有30mins，加油
6 4
2 3 5 4 2 3
Case #6: 6

这个反例证明了不能直接简单地模拟他的选法-->这个题意有故意误导作用！还是要用最优策略

如果改成从小的开始也会有相似的问题，所以还是不行，所以每次询问还是问多组？
那就询问多组！
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int M = 1e3+10;
int T,n,K,v[M],sum,vis[M];

bool check(int x){
    if(x*K<sum || x<v[n-1]) return false;
    if(x>=v[n-1] && K>=n) return true;
    /*l,r左右还没放的下标*/
    // memset(vis,0,n*sizeof(int));
    for(int i=0;i<n;i++) vis[i]=0;
    int tmp=0,ts=sum;
    // while(tmp--){
    int i=1,cnt=n;
    while(ts>0){
        int tps = 0;
        // bool cunzai = false;std::vector<int> tv;
        // for(int k=0;k<cnt/2+1;k++){
        //     while(i<=n && vis[n-i]) i++;
        //     if(n-(i+k)>=0&&vis[n-(i+k)]) {
        //         tps += v[n-(i+k)];
        //         vis[n-(i+k)]=1;
        //         tv.push_back(n-(i+k));
        //     }
        //     else break;
        //     while(tps<x){
        //         int tn = lower_bound(v,v+n-(i+k),x-tps)-v;
        //         if(v[tn]==x-tps && !vis[tn]){
        //             tps += v[tn];
        //             vis[tn]=1;
        //             tv.push_back(tn);
        //             cunzai = true;
        //             break;
        //         }
        //         int j=1;
        //         while(j<=tn && vis[tn-j]) j++;
        //         if(tn-j>=0) {
        //             tps += v[tn-j];
        //             vis[tn-j]=1;
        //             tv.push_back(tn-j);
        //         }
        //         else break;
        //     }
        // }
        // if(cunzai) goto END;
        // else {
        //     tps=0;
        //     while(!tv.empty()) {
        //         vis[tv.back()]=0;
        //         tv.pop();
        //     }
        // }
        // while(vis[n-i]) i++;
        /*防止访问异常区间,但分析知这肯定不是wa的原因*/
        while(i<=n && vis[n-i]) i++;
        /*此时必然!vis[n-i]*/
        if(n-i>=0) {
            tps += v[n-i];
                cout<<"I get you! : "<<v[n-i]<<endl;
            vis[n-i]=1;
        }
        else break;
        // int tps = v[r];vis[r]=1;r--;
        while(tps<x){
            // int tn = lower_bound(v,v+n-i,x-tps)-v;
            // if(v[tn]==x-tps && !vis[tn]){
            //     tps += v[tn];
            //         cout<<"I get you! : "<<v[tn]<<endl;
            //     vis[tn]=1;
            //     break;
            // }
            int tn = upper_bound(v,v+n-i,x-tps)-v;
            int j=1;
            while(j<=tn && vis[tn-j]) j++;
            if(tn-j>=0) {
                tps += v[tn-j];
                    cout<<"I get you! : "<<v[tn-j]<<endl;
                vis[tn-j]=1;
            }
            else break;
        }
        END:
        cout<<"How much is the tps "<<tps<<endl;
        ts -= tps;
        tmp++;
    }
    // if(sum>0) return false;// ts..
    if(tmp>K) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;int kase=1;
    while(T--){
        cin>>n>>K;
        sum = 0;
        for(int i=0;i<n;i++){
            cin>>v[i]; sum+=v[i];
        }
        sort(v,v+n);
        int l=1,r=1e6;
        while(l<r) {
            cout<<"l: "<<l<<" r: "<<r<<endl;
            int mid = (l+r)>>1;
            if(check(mid)) r=mid;else l = mid+1;
        }
        cout<<"Case #"<<kase++<<": "<<l<<endl;
        if(check(5)) cout<<"you are right!"<<endl;
    }

    return 0;
}