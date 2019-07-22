/*
一开始3点半写的时候只是结果不对，现在2019年7月22日16:34:47 直接不能运行了... 菜爆了...

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int M = 1e5+10;
int n;double tmp;
struct car{
    int id,l,s,v;
} c[M];
bool cmp(car a,car b){ return a.s < b.s;}

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(false);
    while(cin>>n){
        cin>>c[0].l;
        for(int j=1;j<=n;j++) cin>>c[j].l;
        cin>>c[0].s;
        for(int i=1;i<=n;i++) cin>>c[i].s;
        cin>>c[0].v;c[0].id=0;
        for(int i=1;i<=n;i++) cin>>c[i].v,c[0].id=i;

        sort(c,c+n+1,cmp);
        double t1 = (double)c[0].s/c[0].v;
        int i=1;int vhead = c[0].v;
        for(; i==n || c[i].id!=0;i++){
            int cnt=0;
            while( i-(1+cnt)>0 && c[i].v == c[i-(1+cnt)].v ) cnt++;
            int tp = i-(1+cnt);
            if(c[i].v!=c[tp].v){
                /*这里到后面再更新vhead*/
                /*这里有问题,还是只能用前一个的相对,而且我没有考虑速度慢的情况...思路浑浊了,先清空*/
                tmp = (double)(c[i].s-(c[tp].s+c[tp].l))/(c[i].v-c[tp].v);
            }
            else{
                /*i等于0才会进来,而且速度一直相等...所以这里不用更新vhead*/
                t1 = c[i].s/c[i].v; continue;
            }
            if(t1 > tmp){
                t1 = t1+c[tp].l/vhead;
            } else{
                t1 = c[i].s/c[i].v;
                vhead = c[i].v;
            }
        }
        int cnt=0;
        while( i-(1+cnt)>0 && c[i].v == c[i-(1+cnt)].v ) cnt++;
        int tp = i-(1+cnt);
        if(c[i].v!=c[tp].v){
            /*这里到后面再更新vhead*/
            tmp = (double)(c[i].s-(c[tp].s+c[tp].l))/(c[i].v-c[tp].v);
        }
        else{
            /*i等于0才会进来,而且速度一直相等...所以这里不用更新vhead*/
            t1 = c[i].s/c[i].v; continue;
        }
        if(t1 > tmp){
            t1 = t1+c[tp].l/vhead;
        } else{
            t1 = c[i].s/c[i].v;
            vhead = c[i].v;
        }

        cout<<fixed<<setprecision(10)<<t1<<endl;
    }
    return 0;
}