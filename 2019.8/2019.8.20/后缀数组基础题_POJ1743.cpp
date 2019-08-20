/*
2019年8月20日19:30:03开始看题

因为是从后缀数组专题找的，所以知道用后缀数组和二分，
不过还是有点挑战性，那就干起来吧

完蛋,好久没写二分,连2分通用板子都不会写了...

2019年8月20日21:24:06 参考了别人的代码，
发现自己没有考虑声调的升降问题！

2019年8月20日21:51:35 自己卡在了那个height数组意义上，所以
check函数的理解以及ans+1的理解一直过不去...

有点晕 --> 先去跑步放松一下吧
然后跑步过程真的想明白了！一个点
*/

#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int maxn = 20010;
int sa[maxn],height[maxn],rank[maxn],t[maxn],t2[maxn],c[maxn];
int n;
int str[maxn];

void build_sa(int m,int n){
    int *x=t,*y=t2;
    for(int i=0;i<m;i++)c[i]=0;
    for(int i=0;i<n;i++)c[x[i]=str[i]]++;
    for(int i=1;i<m;i++)c[i]+=c[i-1];
    for(int i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1){
        int p=0;
        for(int i=n-k;i<n;i++)y[p++]=i;
        for(int i=0;i<n;i++)if(sa[i]>=k)y[p++]=sa[i]-k;
        for(int i=0;i<m;i++)c[i]=0;
        for(int i=0;i<n;i++)c[x[y[i]]]++;
        for(int i=1;i<m;i++)c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        x[sa[0]]=0;p=1;
        for(int i=1;i<n;i++)
            x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++);
        if(p>=n)break;
        m=p;
    }
}

void getheight(int n){
    int k=0;
    for(int i=1;i<=n;i++)::rank[sa[i]]=i;
    for(int i=0;i<n;i++){
        if(k)k--;
        int j=sa[::rank[i]-1];
        while(str[i+k]==str[j+k])k++;
        height[::rank[i]]=k;
    }
}

bool check(int c){
    int Max=sa[0],Min=sa[0];
    for(int i=1;i<n;i++){
        cout<<"ASDSD"<<endl;
        // 有希望成为最长公共前缀不小于k 的两个后缀一定在同一组
        // 并且正好相邻，所以之后比较一下sa最大最小值就行

        /*现在要想清楚的问题是，height的同一组是在一起的吗？*/

        /*这里的for是枚举的排名值，而height就是相邻排名的
        最长公共前缀，但是同一组还是不相邻啊*/
        /*不，排名不相邻都没有height这一说了！而且只有排名
        相邻才能拥有最大可能的相同串，所以只要这样比较就可以了*/
        if(height[i]>=c)
            Max=max(Max,sa[i]),Min=min(Min,sa[i]);
        else
            Max=sa[i],Min=sa[i];
        /*因为之前我们处理成了差值，所以我们内卷了一个值，
        我们的差值相当于左右两个值，所以4个值代表着5个值
        所以最长公共字串只要在4的时候就相当于5,然后sa的
        差值还是要相间隔5才行==>这样真实的5个值也才是真的
        间隔5个值，所以同理答案也就是c+1

        发现有1个blog主写着ans+1,但是这里又写着c,所以他们
        应该没有真正理解，而且数据没有考虑到一些特例，而是
        着重卡时间去了...

        特例
        9
        1 2 3 4 5 6 7 8 9
        */
        if(Max-Min>=c+1)
            return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>n){
        if(n==0) break;
        for(int i=0;i<n;i++) cin>>str[i];
        for(int i=0;i<n-1;i++) str[i]=str[i+1]-str[i]+90;

        /*因为转变差值了，所以少一个值*/
        str[n-1]=0;n--;

        build_sa(178,n);
        getheight(n);
        int l=0,r=n+1,ans=0;
        while(l<=r){
            cout<<"WA"<<endl;
            int mid=(l+r)>>1;
            if(check(mid)) l=mid+1,ans=mid;
            else r=mid-1;
        }
        if(ans<4) cout<<0<<endl;
        else cout<<ans+1<<endl;
    }

    return 0;
}

/*
9
1 2 3 4 5 6 7 8 9

我的板子对于这个样例就直接re翻车了...什么鬼


*/