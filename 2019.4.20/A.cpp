// 2019年4月20日17:59:34开始准备看题,2019省赛训练1
// 大家a都几乎过了，我还没懂题意2019年4月20日18:05:50 ,加油
// 2019年4月20日18:07:11 懂了，也就是他的分数是本班拖后腿的，在另一个班不拖后腿

// 2019年4月20日18:26:00 AC龟速
#include<bits/stdc++.h>
using namespace std;
int a[55],b[55];
int sa,sb;

int main(int argc, char const *argv[])
{
    int T;int N,M;
    cin>>T;
    while(T--) {
        sa=sb=0;
        int ansa=-1,ansb=-1;
        cin>>N>>M;
        // for(int i=0;i<N;i++){
        N = N - 1;
        for(int i=0;i<N;i++){
            cin>>a[i];
            sa+=a[i];
        }
        for(int i=0;i<M;i++){
            cin>>b[i];
            sb+=b[i];
        }
        // if(sb%M==0){
            ansa = sb/M+1;
        // }
        // else ansa = sb/M + 1;
        if(sa%N==0){
            ansb = sa/N - 1;
        }
        else ansb = sa/N;// 保证有解，不用max
        cout<<ansa<<" "<<ansb<<endl;
    }
    return 0;
}