// 2019年5月31日17:07:23 开始看题
// H最高牛高,I最高牛下标,R-->关系
// 2019年5月31日17:16:35 借鉴了李煜东的代码开始合上书默写
// 2019年5月31日17:36:11 第一发CE,因为本地可以不包含cstdio,而服务器必须要
// 2019年5月31日17:37:34 AC吃饭去...
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef pair<int,int> P;  // pair在std里面
int d[10010];// 差分数组
int c[10010];// 高度数组,也就是d数组的前缀和
// map<P,bool> existened[10010];  // 这里是数组map了！！！
map<P,bool> existened;

int main(int argc, char const *argv[])
{
    int N,I,H,R;
    int A,B;
    cin>>N>>I>>H>>R;
    while(R--){
        scanf("%d%d",&A,&B);

        if(A>B) swap(A,B);  // 漏写了很重要的一步

        if(existened[mp(A,B)]) continue;
        existened[mp(A,B)] = true;
        d[A+1]--;d[B]++;
    }
    for(int i=1;i<=N;i++){
        c[i]=c[i-1]+d[i];
        cout<<c[i]+H<<endl;
        // cout<<c[i]<<endl;
    }
    return 0;
}
