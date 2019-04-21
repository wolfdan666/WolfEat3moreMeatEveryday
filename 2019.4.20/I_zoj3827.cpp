// 2019年4月20日18:26:37 跟榜看I题
// 2019年4月20日18:35:36 一个信息论的阅读理解模拟题，读题到现在2019年4月20日18:35:59 ... 直接写
// 2019年4月20日18:49:02 交了，还WA了...惭愧啊，自己平时也写过这个，结果比赛的时候wa了
// 样例能过怎么就Wa了！因为没有对概率为0的值进行考虑！？
// 果然，考虑0 AC，2019年4月20日18:57:35

#include<bits/stdc++.h>
using namespace std;
#define e exp(1)
double a[110];
int N,T;
string s;

void f(double x){
    double ans=0;
    for(int i=0;i<N;i++) ans -= a[i]*(log(a[i])/log(x));
    printf("%.12f\n", ans);
}

int main(int argc, char const *argv[])
{
    double k = 0.00000000000001;
    // cout<< pow(6,2) <<endl;
    // cout<<k*log(k)/log(2)<<endl;
    cin>>T;
    while(T--){
        cin>>N>>s;
        for(int i=0;i<N;i++){
            cin>>a[i];
            if(abs(a[i]-0)<1e-13){a[i]=k;continue;}
            a[i]/=100;
        }
        if(s[0]=='b') f(2);
        else if(s[0]=='n') f(e);
        else f(10);
    }
    return 0;
}