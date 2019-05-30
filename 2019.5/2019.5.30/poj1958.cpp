// 2019年5月30日21:08:44 开始
// 2019年5月30日21:18:06 AC

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long d[12],f[13];

int main(int argc, char const *argv[])
{
    d[1] = 1;
    for(int i=2;i<=11;i++){
        d[i] = 2*d[i-1] + 1;
    }
    memset(f,0x3f,sizeof(f));// 不能放在f[1]=1后面！
    f[1]=1;
    for(int i=2;i<=12;i++){
        for(int j=1;j<i;j++){
            f[i]=min(f[i],2*f[j]+d[i-j]);
        }
    }
    for(int i=1;i<=12;i++) cout<<f[i]<<endl;
    return 0;
}