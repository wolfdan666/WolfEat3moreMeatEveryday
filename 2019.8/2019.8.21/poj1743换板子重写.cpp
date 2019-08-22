/*
2019年8月21日10:33:40 换了板子还是RE!

da要加一个位置的字符,让它比所有的字符都小
然而calheight却不要...就是因为这个RE了..

然后仍然wa了...

最后发现是check函数又使用了sa!所以就是它那里的n要用最开始的n
所以就只有getheight要用n-1

因为getheight中的最后一个sa的rank是没有用的,所以直接让n-1代入就行？
应该确实是这样的

2019年8月21日11:31:45 还是不太理解为啥可以这样...为啥check要n+1??????????
那个被我hack的AC代码的check没有n+1...

因为你check用了sa[0]..以及for用的是'' < ''
*/

#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int maxn = 20010;
int sa[maxn];
int n;
int str[maxn];

int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int cmp(int *r,int a,int b,int l){return r[a]==r[b]&&r[a+l]==r[b+l];}

void da(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) ::ws[i]=0;
    for(i=0;i<n;i++) ::ws[x[i]=r[i]]++;
    for(i=1;i<m;i++) ::ws[i]+=::ws[i-1];
    for(i=n-1;i>=0;i--) sa[--::ws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p){
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) ::ws[i]=0;
        for(i=0;i<n;i++) ::ws[wv[i]]++;
        for(i=1;i<m;i++) ::ws[i]+=::ws[i-1];
        for(i=n-1;i>=0;i--) sa[--::ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
        x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    for(int i = 0 ;i<n;i++) cout<<sa[i]<<" "; cout<<endl;
    return;
}



/*LCP:最长公共字串部分*/
int rank[maxn],height[maxn];

/*r为字符串数组,sa是后缀数组,n为字符串长度*/
void calheight(int *r,int *sa,int n){
    int i,j,k=0;
    /*用sa[]得到rank[]*/
    for(i=1;i<=n;i++) ::rank[sa[i]]=i;
    /*j就是后缀i的前一名的后缀位置,然后如果前一个串之间有k,那么就从k--起步*/
    for(i=0;i<n;height[::rank[i++]]=k)
    for(k?k--:0,j=sa[::rank[i]-1];r[i+k]==r[j+k];k++);
    return;
}
bool check(int c){
    int Max=sa[0],Min=sa[0];
    for(int i=1;i<n;i++){
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
        /*因为转变差值了，所以少一个值,但是后缀数组要加一个位置，所以不用n--*/
        str[n-1]=0;//n--;
        // for(int i=0;i<=n-1;i++) cout<<str[i]<<" "; cout<<endl;

        /*da要加一个位置的字符,让它比所有的字符都小
        然而calheight却不要...就是因为这个RE了..*/
        da(str,sa,n,178);
        calheight(str,sa,n-1);
        int l=0,r=n+1,ans=0;


        while(l<=r){
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