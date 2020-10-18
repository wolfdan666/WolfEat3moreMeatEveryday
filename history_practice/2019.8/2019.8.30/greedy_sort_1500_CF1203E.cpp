/*
2019年8月30日21:46:18 开始看题
2019年8月30日21:53:59 想到的是暴力把每个人都+1,-1丢入set中,然后ans = set.size
2019年8月30日21:54:52 写
2019年8月30日22:00:08 发现每个人只能贡献一次,那就维护一下
2019年8月30日22:03:53 发现还要sort一下！否则漏情况！----> 傻逼了，不然别人告诉你MAXN干嘛！
2019年8月30日22:08:11 交--->AC   花了  22mins
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int M = 150005;
int b[M];
int n,tp;
set<int> s;
int a[3] = {-1,0,1};

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(b,b+n);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            int ttp = b[i]+a[j];
            if(s.find(ttp)==s.end() && ttp > 0){
                s.insert(ttp);
                break;
            }
        }
    }
    cout<<s.size()<<endl;

    return 0;
}