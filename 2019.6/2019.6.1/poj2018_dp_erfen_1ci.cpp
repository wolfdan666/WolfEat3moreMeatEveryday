// 2019年6月1日22:35:36看题
// 2019年6月1日22:40:48 借鉴李煜东老师的代码
#include<iostream>
#include<cstdio>
using namespace std;
const int M = 1e5+1;
double a[M],b[M],sum[M];

int main(int argc, char const *argv[])
{
    int N,L; cin>>N>>L;
    for(int i=1;i<=N;i++) scanf("%lf",&a[i]);
    double eps=1e-5; // *1000所以得知精度是1e(-3-2)
    double l=-1e6,r=1e6;
    // double l=1e-6,r=1e6;// 这样会导致假定的平均值(mid)恒大于0，所以一直l=mid  === 手贱加为理解透，所以多花了一会
    while(r-l>eps) {
        double mid = (l+r)/2;
        for(int i=1;i<=N;i++) b[i]=a[i]-mid;
        for(int i=1;i<=N;i++)
            sum[i]=sum[i-1]+b[i];
        double ans = -1e10;
        // double ans = 1e-10;// 这样会导致计算的平均值恒大于0，所以一直l=mid  === 手贱加为理解透，所以多花了一会
        double min_val = 1e10;
        for(int i=L;i<=N;i++){
            min_val = min(min_val,sum[i-L]);
            ans = max(ans,sum[i]-min_val);
        }
        if(ans>=0) l=mid;else r=mid;

        // cout<<"l:"<<l<<"r:"<<r<<endl;
    }
    cout<<int(r*1000)<<endl;
    return 0;
}