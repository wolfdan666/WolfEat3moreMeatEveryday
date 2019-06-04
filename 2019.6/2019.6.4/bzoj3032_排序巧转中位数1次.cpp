/*
2019年6月4日21:48:01 开始构思怎么写，因为看完了李煜东老师的思路了

*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
const int N=1e5+5;
typedef long long ll;
int x[N],y[N],s1[N],s2[N];

int main()
{
    int n,m,num;
    scanf("%d%d%d",&n,&m,&num);
    for(int i=1;i<=num;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        x[a]++;
        y[b]++;
    }
    if(num%m!=0&&num%n!=0){
        printf("impossible\n");
        return 0;
    }
    for(int i=1;i<=n;i++)   //化简 从0出发
        x[i]-=num/n;
    for(int i=1;i<=m;i++)
        y[i]-=num/m;
    ll ans=0;
    if(num%n==0){
        for(int i=1;i<=n;i++)
          s1[i]=s1[i-1]+x[i];     //前缀和
        sort(s1+1,s1+1+n);
        ll k=s1[(n+1)/2];
        for(int i=1;i<=n;i++)
            ans+=abs(k-s1[i]);
    }
    if(num%m==0){
        for(int i=1;i<=m;i++)
          s2[i]=s2[i-1]+y[i];    //前缀和
        sort(s2+1,s2+m+1);
        ll k=s2[(n+1)/2];
        for(int i=1;i<=n;i++)
            ans+=abs(k-s2[i]);
    }
     if(num%n==0&&num%m==0)
        printf("both ");
    else if(num%n==0&&num%m!=0)
      printf("row ");
    else
       printf("column ");
    printf("%lld\n",ans);
    return 0;
}