/*
主要是b[i]也可以是负数！b[i]是负数是没关系的！也可以算出来

好像是有一个坑点就是a[i]和b[i]同时也负数的时候可以得到正数！
所以可能出错在了这里！dls也wa了两次

2019年7月27日15:26:41 还是wa了...wa2发了...
2019年7月27日15:31:07 好像是没有考虑对后面造成的影响！
----> 发现李大佬都单挑5题了，我们3题，安大5题，科大6题

2019年7月27日15:55:09 队友告诉我C是原题，不过要用线段树维护，今天不学会线段树我不睡觉了！艹！
咖啡鸡好像3点半才打

2019年7月27日16:13:05 自闭，还是去扎扎实实学一下线段树先
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
#define ll long long
const int inf = 0x3f3f3f3f;
const int M = 3e6+7;
int a[M],b[M],s[M],w[M];
int p,n;
ll ans=-inf;
stack<int> sta;

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    /*最后一个不大于s[0]即可*/
    a[n+1]=s[0]=-inf;
    p=0;
    for(int i=1;i<=n+1;i++){
        if(a[i]>s[p]) s[++p] = a[i],w[p]=b[i];
        else{
            int width = 0;int nowwidth=width;
            while(s[p]>a[i]){
                width+=w[p];
                if(s[p]>0) nowwidth=width<0?w[p]:width+w[p];
                else nowwidth=width>0?w[p]:width+w[p];
                /*宽高都正或都负都可以这样
                不过高负宽正的话要丢入最小宽度
                高正宽负也要丢入最小宽度---
                但宽的正负有叠加性,前面正后面负就惨了

                如果高度正--前面宽度是负数就不要前面的宽度
                如果高度负--前面宽度正就也不要前面的宽度*/
                ans = max(ans,(ll)nowwidth*s[p]);
                p--;
            }
            s[++p]=a[i],w[p]=width+b[i];
            /*丢入所有状态算了,脑子有点混沌,等等*/
            /*int cnt = 0;
            while(s[p]>a[i]) {
                cnt+=w[p];
                sta.push(w[p]);
                ans = max(ans,(ll)cnt*s[p]);
                p--;
            }
            while(!sta.empty()) cnt-=sta.top(),s[++p]=a[i],s[p]=sta.top(),sta.pop();
            s[++p] = a[i],s[p] = b[i];*/
            }
    }
    cout<<ans<<endl;
    return 0;
}