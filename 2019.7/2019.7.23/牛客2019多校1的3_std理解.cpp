/*2019年7月23日15:24:41 看了一个小时多了还是只看完一半，
有很多地方模糊，所以可以先通览一遍*/

#include <bits/stdc++.h>
using namespace std;
template <class T>
bool Reduce(T &a,T const &b) {
    return a>b?a=b,1:0;
}

const int XN=1e4+11;
const long long INF=1e18;

vector<long long> Merge(vector<long long> const &a,vector<long long> const &b) {
    vector<long long> c(a.size()+b.size()-1,INF);
    for(size_t i=0;i<a.size();++i)
        for(size_t j=0;j<b.size();++j)
            Reduce(c[i+j],a[i]+b[j]);
    return c;
}

vector<long long> Go(vector<pair<int,int>> const &a,int dest) {
    vector<long long> c(a.size(),INF),t(a.size(),INF);
    c[0]=dest==-1?0:abs(dest-a[0].first);
    t[0]=0;
    for(int i=1;i<(int)a.size();++i) {
        /*两袋奶之间的距离*/
        int len=abs(a[i].first-a[i-1].first);
        /*到第j袋奶的距离*/
        for(int j=0;j<i;++j)
            t[j]+=len;
        /*比较取下前一袋奶的时间和到达这一袋奶的时间,并且取小的值*/
        for(int j=i;j>=1;--j)
            Reduce(t[j],t[j-1]+a[i].second);
        /*更新t[j],并且赋值给j*/
        for(int j=0;j<=i;++j)
            Reduce(c[j],t[j]+(dest==-1?0:abs(dest-a[i].first)));
    }
    return c;
}

int main() {
//  freopen("in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        //cerr<<T<<':';
        int n,m,k;cin>>n>>m>>k;
        static tuple<int,int,int> p[XN];
        vector<int> x{1};
        for(int i=1;i<=k;++i) {
            cin>>get<0>(p[i])>>get<1>(p[i])>>get<2>(p[i]);
            /* 把行单独地存起来 */
            x.push_back(get<0>(p[i]));
        }
        /*对行进行排序并且删除掉重复的行*/
        sort(x.begin(),x.end());
        x.erase(unique(x.begin(),x.end()),x.end());
        static vector<pair<int,int>> a[XN];
        static long long Ans[XN];
        for(size_t i=0;i<x.size();++i)
            a[i].clear();
        for(int i=1;i<=k;++i) {
            /*不小于*/
            a[lower_bound(x.begin(),x.end(),get<0>(p[i]))-x.begin()].push_back({get<1>(p[i]),
                    get<2>(p[i])});
            Ans[i]=INF;
        }
        for(size_t i=0;i<x.size();++i)
            sort(a[i].begin(),a[i].end());
        static vector<long long> f[2];

        /*开始特判第一行*/
        auto t=a[0];
        /*在头部插入{1,0}--->题目说他一开始在1,1处出发*/
        t.insert(t.begin(),{1,0});
        /*走完并且回到中点*/
        f[0]=Go(t,(m+1)/2);
        /*走完不回到中点*/
        auto g=Go(t,-1);
        for(size_t i=0;i<t.size();++i)
            Reduce(Ans[i],g[i]);

        for(int i=1;i<(int)x.size();++i) {
            /*给前后分段,然后t0是从中间到最左边，t1是从中间到最右边*/
            auto sp=lower_bound(a[i].begin(),a[i].end(),make_pair((m+1)/2,0));
            vector<pair<int,int>> t0(a[i].begin(),sp),t1(sp,a[i].end());
            t0.push_back({(m+1)/2,0});reverse(t0.begin(),t0.end());
            t1.insert(t1.begin(),{(m+1)/2,0});

            auto f0=Go(t0,(m+1)/2),f1=Go(t1,(m+1)/2),g0=Go(t0,-1),g1=Go(t1,-1);
            /*g0是左边到右边再回到中间,g1是右边到左边再回到中间*/
            g0=Merge(f1,g0);g1=Merge(f0,g1);

            assert(g0.size()==g1.size());

            vector<long long> g(g0.size());
            for(size_t i=0;i<g.size();++i)
                g[i]=min(g0[i],g1[i]);
            /*f数组是滚动的- 下面这个是和上一行合并*/
            g=Merge(f[(i-1)&1],g);
            /*这里是用回中点和上一层合并*/
            f[i&1]=Merge(f[(i-1)&1],Merge(f0,f1));

            /*最后这里还是懵逼了,2019年7月23日17:23:27 太难了,战略原因pass掉了*/
            for(size_t j=0;j<g.size();++j) {
                Reduce(Ans[j],g[j]+=x[i]-x[i-1]);
                f[i&1][j]+=x[i]-x[i-1];
            }
        }

        for(int i=1;i<=k;++i)
            cout<<Ans[i]<<(i==k?'\n':' ');
    }
    return 0;
}
