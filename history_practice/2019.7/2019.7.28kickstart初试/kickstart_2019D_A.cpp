/*
mdzz .. if(tmp&(1<<0)) cnt++;

A只会暴力,而且还写了这么久...感觉B是繁琐的代码细节处理题，C选址不会
是自己太菜了，所以第一次kickstart只交了一发A的暴力，然后2019年7月28日14:31:52 (也就是90mins后)没写了

先去学习线段树吧，等自己变牛逼了再来继续kickstart

*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
const int M = 1e5+10;
int T,N,Q,P,V;
int a[M];
ll ans;

int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    int kase = 1;
    vector<int> anstmp;
    while(T--){
        cin>>N>>Q;
        for(int i=0;i<N;i++) cin>>a[i];
        while(Q--){
            ans = 0;
            cin>>P>>V;
            a[P]=V;
            /* 从大到小只要找到一次就行 */
            for(int l=N;l>=1;l--){
                for(int i=0;i<=N-l;i++){
                    ll tmp = 0;
                    for(int j=i;j<i+l;j++){
                        tmp^=a[j];
                    }
                    int cnt = 0;
                    for(int i=0;i<10;i++){
                        if(tmp&(1<<i)) cnt++;
                    }
                    if(!(cnt&1)){
                        ans = l;
                        goto END;
                    }
                }
            }
            END:
            anstmp.push_back(ans);
        }
        cout<<"Case #"<<kase++<<":";
        for(int i=0;i<(int)anstmp.size();i++) cout<<" "<<anstmp[i]; cout<<endl;
        anstmp.clear();

    }
    return 0;
}