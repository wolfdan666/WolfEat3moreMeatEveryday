/*
 *2019年3月27日20:58:01   开始看题
 *2019年3月27日21:30:30   开始写
 *2019年3月27日22:33:05   还是有bug，然后vscode的debug功能坏掉了，下次去修，所以先看答案吧，好烦啊啊
 *发现答案思路和我差不多，不过比我处理更巧妙，我更常规思考
 *test3 wa
 * 384 378 949 109 878 497  test8 tle 我佛了，我的处理超时！
 *交了tutorial思想的大佬code，我菜爆了！！！
 *2019年3月27日23:10:26 2个小时12mins  才解决这个数学题，真的垃圾！明天早起来训练
 */

#include<bits/stdc++.h>
using namespace std;
long long k,d,t;// 因为取模操作，所以最好ll
double ans;

int main(int argc, char const *argv[]){
    cin>>k>>d>>t;
    if(k%d==0){ cout<<(double)t<<endl; return 0;}
    else{
        if(k<d){
            double turn = (k*1.0/t + (d-k)*1.0/(2*t));
            int i=1;
            // for(;i*turn<1.0000000000;i++){
            for(;i*turn<1.0000000000||abs(i*turn-1.0000000000)<1e-9;i++){// test3教训
                ans+=d;
            }
            if(abs(i*turn-1.0000000000)<1e-9){// 处理了相等的情况
                cout<<ans<<endl; return 0;
            }
            else{
                // double tem = (1-(i-1)*turn)/t;
                double tem = (1-(i-1)*turn)*t;
                if(tem-k<1e-9) ans+=tem;// 这里因为是小于等于(可负)，所以不用加abs
                else ans+=k*1.0+(tem-k)*2.0;
            }
        }
        else{
            int n=1;
            for(;n*d<k;n++) ;// ==已经在取模中考虑了
            // int turn = k*1.0/t + 1.0*(n*d-k)/2*t;
            double turn = k*1.0/t + 1.0*(n*d-k)/(2*t);

            int i=1;
            for(;i*turn<1.0000000000||abs(i*turn-1.0000000000)<1e-9;i++){
                ans+=n*d;
            }
            if(abs(i*turn-1.0000000000)<1e-9){// 处理了相等的情况
                cout<<ans<<endl; return 0;
            }
            else{
                double tem = (1-(i-1)*turn)*t;
                if(tem-k<1e-9) ans+=tem;// 这里因为是小于等于(可负)，所以不用加abs
                else ans+=k*1.0+(tem-k)*2.0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}


// 自己写的tle了，没有简化步骤，所以math题一定要超级精简
#include <cstdio>
long long k, d, t;
int main() {
    scanf("%lld%lld%lld", &k, &d, &t);
    d = d * ((k - 1) / d + 1); // period
    t *= 2;
    double ans = d * (t / (k + d)); //period*num
    t %= k + d; // carry
    if(t <= 2 * k) ans += t / 2.0;
    else {
        ans += k;
        t -= 2 * k;
        ans += t;
    }
    printf("%f\n", ans);
    return 0;
}