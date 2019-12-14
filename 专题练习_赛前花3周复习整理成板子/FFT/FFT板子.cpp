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

// 这个写法有点玄幻，暂时先这样
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
    if(t==-1) rep(i, 0, n) a[i]/=n;    //!!error-prone: typo ==/=
}

// 找到一个大于x的2的幂次数
int trans(int x){
    int i=0;
    for(; x>1<<i; i++);
    return 1<<i;
}

int main(){
    for(; ~scanf("%s%s", s, t); ){
        // 加0的预处理
        int n=strlen(s), m=strlen(t), l=trans(n+m-1);
        rep(i, 0, n) a[i]=C(s[n-1-i]-'0');
        rep(i, n, l) a[i]=C(0);
        rep(i, 0, m) b[i]=C(t[m-1-i]-'0');
        rep(i, m, l) b[i]=C(0);

        // 分别对A,B进行预处理,然后点对表达式想乘,然后再逆DFT的FFT变换一下
        FFT(a, l, 1), FFT(b, l, 1);
        rep(i, 0, l) a[i]*=b[i];
        FFT(a, l, -1);
        // 精度处理
        rep(i, 0, l) ans[i]=(int)(a[i].real()+0.5); ans[l]=0;    //error-prone
        rep(i, 0, l) ans[i+1]+=ans[i]/10, ans[i]%=10;
        int p=l;
        for(;p && !ans[p]; --p);
        for(; ~p; putchar(ans[p--]+'0'));    //error-prone
        puts("");
    }
    return 0;
}
