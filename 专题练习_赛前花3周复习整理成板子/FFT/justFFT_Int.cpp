// https://www.cnblogs.com/Patt/p/5503322.html
// 这里有点尴尬 都是 10以内的系数

#include <bits/stdc++.h>
#include "time_interval.h"
// #include <windows.h>
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

int tmp[4099]={41,67,34,0,69,24,78,58,62,64,5,45,81,27,61,91,95,42,27,36,91,4,2,53,92,82,21,16,18,95,47,26,71,38,69,12,67,99,35,94,3,11,22,33,73,64,41,11,53,68,47,44,62,57,37,59,23,41,29,78,16,35,90,42,88,6,40,42,64,48,46,5,90,29,70,50,6,1,93,48,29,23,84,54,56,40,66,76,31,8,44,39,26,23,37,38,18,82,29,41,33,15,39,58,4,30,77,6,73,86,21,45,24,72,70,29,77,73,97,12,86,90,61,36,55,67,55,74,31,52,50,50,41,24,66,30,7,91,7,37,57,87,53,83,45,9,9,58,21,88,22,46,6,30,13,68,0,91,62,55,10,59,24,37,48,83,95,41,2,50,91,36,74,20,96,21,48,99,68,84,81,34,53,99,18,38,0,88,27,67,28,93,48,83,7,21,10,17,13,14,9,16,35,51,0,49,19,56,98,3,24,8,44,9,89,2,95,85,93,43,23,87,14,3,48,0,58,18,80,96,98,81,89,98,9,57,72,22,38,92,38,79,90,57,58,91,15,88,56,11,2,34,72,55,28,46,62,86,75,33,69,42,44,16,81,98,22,51,21,99,57,76,92,89,75,12,0,10,3,69,61,88,1,89,55,23,2,85,82,85,88,26,17,57,32,32,69,54,21,89,76,29,68,92,25,55,34,49,41,12,45,60,18,53,39,23,79,96,87,29,49,37,66,49,93,95,97,16,86,5,88,82,55,34,14,1,16,71,86,63,13,55,85,53,12,8,32,45,13,56,21,58,46,82,81,44,96,22,29,61,35,50,73,66,44,59,92,39,53,24,54,10,45,49,86,13,74,22,68,18,87,5,58,91,2,25,77,14,14,24,34,74,72,59,33,70,87,97,18,77,73,70,63,68,92,85,2,80,13,27,2,99,27,25,43,24,23,72,61,81,3,32,5,93,25,31,92,42,22,86,64,0,87,60,13,74,70,70,35,33,11,60,96,67,85,50,40,94,95,24,19,25,76,94,58,2,71,66,78,93,51,84,18,64,19,52,0,87,60,26,10,57,70,15,76,27,43,58,64,9,82,86,65,87,77,74,25,27,29,28,23,20,2,62,23,96,37,61,95,25,64,60,2,16,30,26,11,71,11,47,53,20,90,24,88,63,40,51,62,29,0,13,58,78,65,7,77,0,58,39,3,60,57,24,77,8,13,87,1,50,60,28,93,84,5,40,11,4,35,56,72,50,23,85,56,16,26,57,26,57,37,71,69,61,96,22,17,12,17,96,85,41,23,29,29,65,59,32,96,55,53,62,84,34,54,72,57,69,32,63,7,83,11,35,67,48,75,38,23,42,54,11,41,75,59,25,21,70,26,34,5,83,50,98,79,1,93,34,37,34,56,93,76,5,62,48,81,0,13,41,55,55,42,62,11,77,24,78,52,43,96,73,40,13,75,72,18,10,17,32,12,95,69,31,40,88,85,90,97,89,90,45,53,14,51,40,44,58,35,59,92,5,64,81,3,29,75,8,92,97,49,56,61,27,67,41,29,40,13,74,1,77,15,83,13,92,24,1,92,59,70,28,27,84,75,86,98,70,87,47,4,3,21,63,6,63,10,71,89,40,64,42,19,13,91,4,18,32,50,5,75,39,3,22,98,47,84,48,71,64,13,75,45,12,46,78,69,62,19,85,89,44,65,40,45,8,18,70,1,23,32,72,52,87,70,63,1,3,23,27,0,69,15,65,28,43,47,88,43,37,9,63,49,81,88,42,8,60,21,58,54,88,46,90,49,43,30,20,48,67,36,83,35,26,85,38,53,29,24,48,23,59,57,66,44,55,18,26,11,25,55,1,49,96,84,15,64,42,75,13,42,96,48,72,26,6,73,29,4,5,26,12,75,93,65,36,36,41,14,94,56,52,36,38,82,55,15,31,30,41,25,11,37,86,90,50,62,34,93,53,16,52,8,62,33,54,3,34,3,56,48,24,17,13,9,28,0,80,18,58,50,55,61,64,3,76,43,9,2,61,89,48,82,53,74,20,2,23,31,69,78,59,8,19,71,3,45,81,4,92,85,13,98,89,22,38,37,10,61,34,8,61,59,93,15,69,37,69,58,0,71,64,17,15,55,15,30,39,12,88,82,54,85,10,84,74,80,15,51,41,15,79,10,98,73,88,77,32,56,89,13,8,41,90,23,63,28,84,78,0,71,85,74,71,33,67,53,95,68,25,76,29,50,98,9,93,86,80,16,49,67,28,79,64,21,5,26,16,16,26,66,87,81,64,40,86,21,62,21,64,9,15,2,73,24,41,45,62,23,31,6,68,18,2,7,7,81,12,36,30,14,9,84,56,90,93,96,52,54,45,8,48,91,12,31,14,39,58,22,4,95,52,69,79,38,23,18,66,59,98,86,96,62,33,58,22,46,92,37,25,47,58,2,7,98,30,92,0,78,99,52,48,82,40,15,75,62,67,36,97,18,97,28,51,16,30,49,25,58,29,20,40,60,47,62,55,75,92,61,54,98,46,14,46,88,69,38,63,75,15,21,75,15,28,34,70,5,64,57,62,61,24,49,69,30,23,50,33,25,10,37,36,37,78,93,36,14,64,91,49,35,5,37,4,37,23,64,70,8,68,81,85,52,73,52,94,76,26,96,72,49,40,74,19,43,11,41,89,19,65,5,85,16,50,15,9,64,66,93,74,9,0,95,73,89,61,72,68,58,31,68,26,10,22,74,79,10,52,82,91,95,64,74,64,2,55,60,74,72,21,22,47,77,89,5,95,94,50,43,54,81,12,72,39,28,12,62,67,8,15,8,23,59,34,4,86,19,58,45,6,66,0,67,92,87,32,56,74,47,21,83,22,31,76,83,48,23,82,18,76,20,11,82,56,90,25,24,86,77,69,43,34,77,68,68,91,96,83,28,27,26,71,97,12,3,27,8,45,8,85,38,37,43,13,1,50,28,11,50,49,92,54,69,81,65,67,13,93,34,72,72,30,1,42,77,77,70,2,64,81,90,23,37,23,79,95,69,27,42,10,82,58,26,87,70,28,51,58,13,60,83,86,42,10,72,28,34,41,18,3,67,65,38,81,57,50,14,98,58,61,63,56,7,78,89,35,65,75,86,86,33,60,30,48,28,92,33,40,66,35,10,99,37,92,82,28,52,69,44,94,8,52,47,32,35,8,64,97,43,49,15,41,89,0,12,48,23,51,74,33,91,0,54,90,97,19,80,78,31,44,40,87,99,25,83,38,92,93,52,11,60,34,40,97,85,29,40,5,91,92,10,49,78,79,71,77,73,93,20,97,26,76,90,82,78,59,18,89,59,49,24,72,80,8,67,8,77,3,70,7,96,74,22,11,19,61,56,90,63,83,16,32,52,41,54,13,62,96,60,15,4,99,36,80,98,32,87,84,40,17,6,70,41,82,49,23,58,5,21,95,96,16,78,78,79,58,77,50,7,29,81,95,78,76,53,99,84,65,93,8,72,43,29,14,68,55,91,73,22,48,51,86,44,46,77,17,29,16,74,91,69,12,46,93,91,15,49,57,40,52,36,51,87,26,62,55,83,94,80,97,65,65,13,61,78,78,78,40,11,47,45,70,75,89,50,49,33,65,14,82,7,32,96,67,22,82,10,41,31,87,5,79,21,38,51,47,8,46,76,59,89,22,66,86,55,28,14,60,53,77,48,3,61,31,82,55,97,6,52,21,96,81,21,55,47,24,18,35,76,74,59,98,74,53,22,35,43,88,53,32,47,80,26,78,50,1,61,99,55,63,16,73,61,45,73,74,50,53,81,87,99,10,43,65,72,29,81,12,76,81,47,90,71,5,72,32,89,20,65,31,58,93,6,78,48,6,71,66,96,97,20,94,29,88,9,84,69,78,17,15,26,84,68,6,28,97,18,90,99,85,86,99,20,10,71,13,15,85,18,80,31,67,87,44,86,7,60,27,74,31,52,71,68,93,85,37,11,4,77,6,68,22,13,0,42,37,38,88,55,89,47,81,93,84,87,61,93,17,1,82,47,65,53,4,84,95,25,21,64,81,72,6,56,43,93,80,80,68,11,13,68,51,16,79,68,40,31,33,79,63,59,53,36,95,65,74,20,35,80,76,55,25,71,8,59,56,2,32,5,40,75,62,85,62,80,36,97,2,8,80,40,76,58,93,40,46,74,73,97,80,35,72,0,7,55,66,41,88,81,68,15,96,25,9,12,36,55,62,43,42,21,22,12,48,18,68,17,14,50,90,35,59,69,95,3,40,79,99,5,91,61,81,52,53,33,29,87,42,53,83,20,14,18,44,63,29,52,64,69,70,5,47,94,87,26,76,23,40,79,90,88,10,71,45,21,70,83,89,55,78,79,6,62,35,87,96,33,88,35,79,93,90,62,65,1,5,7,67,69,34,71,57,98,45,97,18,38,44,72,63,28,64,1,23,90,4,1,27,97,92,71,63,1,63,21,65,21,45,10,95,41,22,12,51,15,55,93,38,79,82,8,54,22,7,45,38,44,90,39,54,4,23,25,78,24,81,30,33,23,94,30,46,87,45,5,16,50,89,38,63,35,97,9,30,24,8,37,74,20,72,93,55,34,61,56,6,84,75,82,19,41,32,84,79,79,83,67,36,25,18,37,28,19,77,37,91,56,95,60,1,93,32,36,80,75,7,84,74,19,90,76,41,51,29,90,74,72,91,89,87,90,39,93,53,63,81,3,5,76,79,95,39,68,98,83,39,15,21,93,26,22,38,28,81,99,78,91,23,43,34,43,49,2,7,2,41,87,46,91,37,13,0,16,90,62,35,26,10,77,82,60,89,5,74,63,22,95,66,60,38,88,11,45,67,25,67,89,42,63,47,2,17,99,23,26,3,48,51,70,36,58,67,56,5,31,62,19,75,56,31,95,44,91,3,88,15,50,19,72,91,83,33,75,42,69,0,54,78,85,57,33,93,90,3,50,33,22,71,11,90,38,41,58,47,52,58,79,2,83,90,2,68,22,95,35,8,61,42,94,99,88,78,42,57,41,47,69,45,80,13,64,10,61,85,73,4,62,3,2,69,54,29,52,74,49,30,44,44,49,18,65,63,52,73,70,31,47,11,69,98,98,3,52,79,53,43,22,88,63,34,50,22,40,11,92,51,80,77,16,76,78,20,15,48,98,79,35,57,83,62,2,62,20,70,22,73,41,86,88,17,17,92,98,67,49,65,89,32,19,81,3,30,28,31,89,52,30,72,64,7,95,28,81,90,10,77,71,36,59,43,40,33,37,93,30,74,93,82,3,61,90,62,7,97,51,23,90,17,40,3,66,83,61,59,45,86,51,65,1,40,9,97,83,50,58,21,75,81,87,71,87,99,4,79,38,0,30,61,18,5,40,28,59,22,98,60,98,35,81,14,67,93,96,61,46,38,70,38,76,55,17,71,60,52,58,33,55,65,26,1,34,59,93,48,73,92,93,33,37,3,90,11,94,68,27,98,89,48,79,47,49,31,69,75,98,49,36,99,23,43,31,54,61,34,85,67,16,93,4,66,53,8,23,84,92,67,48,69,30,11,14,90,27,43,4,99,74,95,6,58,89,58,9,89,47,40,18,64,75,26,89,3,66,12,40,70,76,95,41,86,51,9,87,83,85,90,50,86,55,81,28,2,77,62,24,65,72,32,85,28,46,89,78,83,25,65,60,45,78,21,55,20,27,73,34,51,75,36,34,1,37,10,74,90,56,71,80,35,45,82,25,18,73,12,37,98,5,62,17,92,39,47,46,3,31,15,39,58,29,45,94,99,45,72,75,62,72,73,80,38,97,42,8,3,77,25,34,1,78,82,69,36,78,39,38,21,26,63,77,75,24,81,0,61,62,2,48,95,84,16,37,7,93,84,44,59,21,58,43,68,77,19,57,41,91,64,23,15,72,29,41,15,15,36,57,59,0,52,93,41,29,48,27,98,24,24,74,33,85,38,70,62,29,84,9,78,23,85,0,24,93,5,12,65,67,7,77,84,4,90,34,91,21,85,34,90,42,98,86,18,21,24,97,76,54,69,8,27,93,68,66,2,38,0,19,18,90,84,39,56,8,32,78,14,87,39,74,20,27,54,88,41,98,42,2,21,4,46,56,9,33,8,61,33,86,4,85,42,42,60,61,20,43,78,87,13,63,91,34,15,56,61,12,11,59,51,38,70,24,7,7,84,51,1,89,58,41,90,13,12,55,60,93,72,2,76,43,73,66,51,75,28,32,61,69,3,29,7,92,51,53,92,70,19,72,7,94,5,40,83,62,9,7,38,60,71,71,54,47,14,23,29,89,66,87,56,32,70,39,66,22,83,60,53,5,91,59,86,87,29,42,17,45,56,88,52,54,66,33,60,19,31,38,67,76,98,14,20,53,7,69,16,22,42,7,63,60,47,93,30,17,43,76,14,26,17,34,20,71,92,64,54,66,93,64,75,0,12,0,51,76,79,43,77,89,61,85,72,34,44,61,63,4,46,88,8,57,30,23,64,74,46,37,81,18,11,92,91,32,23,61,91,61,30,98,69,91,0,79,17,17,14,95,41,36,67,28,53,9,73,81,3,69,16,83,67,85,2,30,57,81,67,10,66,87,71,77,45,64,38,71,47,15,92,11,57,5,53,71,80,40,30,75,20,90,77,98,86,4,89,31,44,88,10,18,19,59,27,9,19,79,16,0,96,53,58,30,93,6,49,54,72,60,94,54,33,46,29,71,28,59,41,21,88,66,33,85,70,29,61,60,8,82,62,6,78,79,97,87,38,69,83,40,95,66,33,9,57,17,34,53,35,58,93,43,93,66,51,40,94,37,74,12,97,51,95,17,92,92,37,30,13,96,10,89,28,9,86,44,40,82,69,20,93,92,62,14,27,7,94,5,13,11,13,93,64,3,95,62,81,46,9,48,68,24,11,54,35,27,33,40,62,27,77,17,40,42,0,0,58,76,54,35,30,31,95,37,23,22,27,29,11,11,54,80,53,93,21,85,28,43,0,55,71,70,52,75,31,40,34,40,86,34,48,39,65,96,12,62,52,31,87,64,57,48,56,70,50,82,1,93,99,32,44,31,75,4,50,26,66,38,1,23,43,41,80,95,18,59,63,28,29,88,54,13,79,69,66,79,77,37,2,15,92,23,72,48,23,53,48,95,97,8,8,11,93,65,81,2,10,28,56,5,65,23,69,15,53,5,84,78,45,40,33,85,0,68,94,33,85,48,81,32,56,10,72,82,1,6,35,60,71,27,37,43,68,33,95,71,3,42,11,79,34,12,93,30,61,34,58,26,6,91,43,88,27,19,84,24,93,35,24,94,82,67,27,5,46,86,89,40,37,50,59,78,56,77,3,42,0,11,25,43,95,16,15,4,6,68,41,35,98,25,13,23,12,18,57,96,39,86,94,46,43,22,11,80,55,58,47,70,90,73,27,13,54,96,72,50,41,41,46,25,13,24,29,95,3,94,93,67,87,40,79,41,25,34,60,0,7,21,92,93,17,17,3,43,93,39,11,25,28,78,48,50,92,44,54,23,53,36,47,46,26,61,4,38,71,86,5,99,56,28,67,51,19,91,66,17,46,93,87,21,12,67,99,44,97,1,28,42,4,68,68,41,96,62,20,44,18,25,19,84,74,84,59,49,14,95,3,32,51,37,14,63,51,19,90,17,83,18,84,52,86,69,48,37,97,24,68,27,48,93,82,71,69,93,77,14,4,84,43,95,11,93,92,98,90,99,90,93,74,49,74,14,73,69,18,65,33,38,11,52,63,8,49,88,45,31,20,6,71,68,21,58,57,47,82,38,22,23,6,6,89,56,45,51,23,18,50,97,36,91,6,10,13,51,80,44,43,41,45,78,49,5,14,85,27,24,4,56,17,27,55,2,86,68,98,79,11,89,58,90,75,10,32,89,96,50,12,22,29,72,36,77,53,76,70,85,52,51,97,51,1,35,93,72,16,16,28,11,25,38,96,39,44,56,26,2,58,88,21,86,8,77,28,79,47,49,80,45,28,62,26,19,77,91,47,85,31,6,84,54,69,9,56,21,45,65,16,60,97,35,90,77,49,5,86,88,75,43,77,30,87,55,82,53,0,54,89,88,15,8,10,40,99,97,7,54,4,37,85,99,92,13,12,82,83,51,29,37,33,0,64,83,57,68,10,68,8,41,32,37,84,99,1,69,83,56,92,40,87,12,10,20,35,63,15,97,77,74,34,53,33,78,86,24,34,75,49,12,84,24,92,4,22,55,13,62,73,84,60,22,53,97,22,50,37,17,6,31,97,5,36,57,99,90,98,85,47,84,92,25,96,55,28,38,42,28,95,42,37,6,67,53,93,5,46,9,24,54,65,39,6,9,92,99,75,36,61,47,18,13,27,12,96,9,41,30,90,34,15,86,23,66,44,36,37,16,93,49,71,44,77,85,0,90,85,25,18,68,6,29,8,41,25,36,80,16,70,84,47,28,36,4,0,23,64,11,40,50,4,83,66,41,70,45,6,88,56,7,66,57,78,99,74,55,91,90,32,58,96,17,90,67,7,34,46,62,2,39,26,95,6,14,50,86,79,76,22,79,1,12,76,64,57,70,38,12,44,61,80,0,43,56,61,47,39,8,90,52,79,18,19,7,84,47,77,75,13,9,71,42,39,36,21,1,34,29,58,36,69,97,4,98,2,5,38,32,65,16,81,79,23,27,71,13,82,40,16,88,19,89,13,59,51,71,83,64,38,12,84,59,1,74,33,59,14,49,95,22,41,16,77,52,65,91,38,10,67,55,87,24,22,39,41,48,4,34,68,41,72,68,74,76,37,33,41,45,18,15,74,52,46,56,24,66,81,44,40,34,96,76,27,5,18,91,41,65,91,71,59,0,17,16,43,24,64,5,57,2,66,75,46,32,89,46,45,3,52,1,26,53,84,49,50,5,46,25,70,36,95,93,23,32,56,96,10,76,92,50,90,95,52,50,15,36,61,60,84,29,34,50,82,6,36,84,90,17,82,66,16,88,25,1,10,50,82,21,93,38,54,93,95,80,38,67,20,45,83,65,96,33,90,32,89,39,83,17,29,53,79,13,0,52,45,61,51,18,63,13,7,54,76,17,11,29,64,66,31,42,98,22,55,87,57,58,64,62,10,46,65,80,65,46,40,97,42,64,94,84,70,15,0,6,6,2,96,33,11,67,15,45,75,54,48,19,79,88,21,92,97,97,9,52,71};

int main(){
    // freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    // int tp;
    // for(; ~scanf("%d", &tp); ){
    //     tmp.push_back(tp);
    // }

    {
        // 毫秒
        // TIME_INTERVAL_SCOPE("C++ FFT time cost:\n");
        // 微秒
        timespec t1, t2;
        clock_gettime(CLOCK_MONOTONIC, &t1);

        //要计时的程序
        int n=4096, l=trans(n-1);
        // 加0的预处理
        rep(i, 0, n) a[i]=C(tmp[i]);
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

    return 0;
}