/*
2019年7月17日16:20:42 开始看题

看完李煜东老师的提醒， 是排序，中位数，环形均分纸牌
然后自己就把 中位数，和均分纸牌看完了，
然后看完后 2019年7月17日16:40:41 发现解法就是  1. 先找到中位数  2. 然后均分纸牌

因为直接均分纸牌 得到的数值 会  由于向着中位数移动而变小！
2019年7月17日16:43:40 开写

2019年7月17日17:15:42 发现这样写的话，样例都会有问题，因为偶数的话，选哪个中位数有影响...还是看看大佬怎么写的把...
感觉自己真是菜得抠脚...自闭...继续加油，可以失败，但不可以放弃，希望打退役比赛的时候能展现出我全力以赴的水平吧，超越自己

2019年7月17日18:19:40 吃饭回来发现自己的思路确实是有很多漏洞的，主要是以糖果值取的中位数很容易举出反例！

2019年7月17日18:24:20 又看李煜东老师的书，发现书上给的例题是双垂直环！然后自己还没看完就开始写...结果就错了...看完李煜东老师的书，
觉得自己之前应该是没有消化好...

2019年7月17日18:48:51 重写了还狂wa... 发现别人写了long long...
只ans ll还不行，其他也要...跑了6.2s，怪不得延时限制10s...
 */
/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
const int M = 1e6+10;
int n,a[M],b[M],sum;
// int m,mi,l,r;
int ta[M],sa[M];
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
        b[i] = a[i];
        // 2019年7月17日16:58:27 分析觉得这种题目应该没有那么卡时间，所以直接使用辅助数组，快排
        // if(i==0){m=a[i];mi=0;}
        // if(a[i]==m){
        //     if(l<=r) l++;
        //     else r++;
        // }
        // else if(a[i]>m){
        //     if(l<=r)
        // }
    // 如何获取中位数都卡了半天.. 优先队列n/2大顶堆不靠谱，n*log(n/2) 直接写判断吧
    }
    sort(b,b+n);
    int tmp = b[n/2];
    int ave = sum/n;
    for(int i=0;i<n;i++){
        if(a[i]==tmp){
            int t=1;
            for(int j=i;t<=n;j=(j+1)%n,t++){
                ta[t] = a[t] - ave;
                sa[t] = ta[t] + sa[t-1];
                ans += abs(sa[t]);
            }
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
*/

/*
2019年7月17日18:28:35 开始重新写
*/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int M = 1e6+10;
long long n,ave,a[M],A[M],s[M],sum;
long long ans;

int main(int argc, char const *argv[])
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ave = sum/n;
    for(int i=1;i<=n;i++){
        A[i]=a[i] - ave;
        s[i]=s[i-1] + A[i];
    }
    sort(s+1,s+1+n);
    /*数组变成了从1开始之后，中位数是n/2+1！*/
    int tmp = s[n/2+1];
    for(int i=1;i<=n;i++) ans+=abs(s[i]-tmp);
    cout<<ans<<endl;
    return 0;
}