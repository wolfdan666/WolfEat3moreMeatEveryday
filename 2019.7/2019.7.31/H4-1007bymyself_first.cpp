/* 2019年7月31日21:30:15
结论题:空格到最后一行的奇偶性和逆序对的奇偶性是否相同
那么直接加到一起判断是奇还是偶(奇偶性相同得偶数)

如果我们要求解步数的话
我们首先是用逆序数进行判定是否有解，有解才进行搜索。

使用曼哈顿距离递减 和 IDA*(迭代层数达到120层就放弃) 的方式
曼哈顿是初始排列到目标排列每个数字abs(x1-x2)+abs(y1+y2)的和值

*/
#include<bits/stdc++.h>
using namespace std;
int T,a[16];

int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        int cnt = 0;
        for(int i=0;i<16;i++) cin>>a[i];
        for(int i=0;i<16;i++){
            if(!a[i]){
                cnt+=3-i/4;
            }
            else{
                for(int j=0;j<i;j++){
                    if(a[j] && a[j]>a[i])
                        cnt++;
                }
            }
        }
        if(cnt&1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}