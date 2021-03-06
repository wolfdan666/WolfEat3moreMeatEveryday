// https://www.cnblogs.com/Patt/p/5503322.html
// 这里有点尴尬 都是 10以内的系数

#include <bits/stdc++.h>
#define rep(i, l, r) for(int i=l; i<r; i++)
using namespace std;
const double PI(acos(-1));
typedef complex<double> C;

const int N(1<<17);
int ans[N];
C a[N], b[N];
char s[N], t[N];

void bit_reverse_swap(C *a, int n){
    for(int i=1, j=n>>1, k; i<n-1; i++){
        if(i < j) swap(a[i],a[j]);
        //tricky
        for(k=n>>1; j>=k; j-=k, k>>=1);    //inspect the highest "1"
        j+=k;
    }
}

void FFT(C* a, int n, int t){
    bit_reverse_swap(a, n);
    // 这里是蝶形算子的预处理吧
    for(int i=2; i<=n; i<<=1){
        C wi(cos(t*2*PI/i), sin(t*2*PI/i));
        for(int j=0; j<n; j+=i){
            C w(1);
            for(int k=j, h=i>>1; k<j+h; k++){
                // 局部t和外部的t没有关系
                C t=w*a[k+h], u=a[k];
                a[k]=u+t;
                a[k+h]=u-t;
                w*=wi;
            }
        }
    }
    // 逆DFT变换需要的一些操作
    if(t==-1) rep(i, 0, n) a[i]/=n;
}

// 找到一个大于x的2的幂次数
int trans(int x){
    int i=0;
    for(; x>1<<i; i++);
    return 1<<i;
}


int main(){
    freopen("inrand.txt","r",stdin);
    freopen("out.txt","w",stdout);
    for(; ~scanf("%s", s); ){
    {
        // 毫秒
        // TIME_INTERVAL_SCOPE("C++ FFT time cost:\n");
        // 微秒
        timespec t1, t2;
        clock_gettime(CLOCK_MONOTONIC, &t1);

        //要计时的程序
        int n=strlen(s),l=trans(n-1);
        // 加0的预处理
        rep(i, 0, n) a[i]=C(s[n-1-i]-'0');
        rep(i, n, l) a[i]=C(0);

        // 分别对A,B进行预处理,然后点对表达式想乘,然后再逆DFT的FFT变换一下
        FFT(a, l, 1);

        rep(i,0,l) printf("%f%c%fj\n", a[i].real(),a[i].imag()<0 ? '-':'+',abs( a[i].imag()));


        clock_gettime(CLOCK_MONOTONIC, &t2);
        //那么f所花时间为
        double deltaT = (t2.tv_sec - t1.tv_sec) * 10^9 + t2.tv_nsec - t1.tv_nsec;//  纳秒
        deltaT /= 1000;
        printf("%f us\n", deltaT );
    }
    }
    return 0;
}