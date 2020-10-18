// ————————————————
// 版权声明：本文为CSDN博主「dinosoft」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/dinosoft/article/details/5829550
#include<iostream>
using namespace std;
const long N = 200000;
long prime[N] = {0},num_prime = 0;
int isNotPrime[N] = {1, 1};

int main(){
    for(long i = 2 ; i < N ; i ++){
        // 确定素数
        if(!isNotPrime[i]) prime[num_prime++]=i;
        for(long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++){
            isNotPrime[i * prime[j]] = 1;
            if(!(i%prime[j])) break;//关键处2
        }
    }
    return 0;
}