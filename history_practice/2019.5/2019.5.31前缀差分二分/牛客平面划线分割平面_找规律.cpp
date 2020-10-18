/*
    当1条线时  2个平面

    当2条线时  4个平面（交叉1根线等多出2个平面）

    当3条线时  7个平面  (交叉2根线等多出3个平面)

    当4条线时  11个平面 (交叉3根线等多出4个平面)

    .....

   其实已经可以递推了，前n项和 f(n)=n*(n+1)/2+1



    那么这题就是一次划两根，那就是f(2*n)=n*(2*n+1)+1

*/

#include <iostream>
using namespace std;

int main(){
    long long n;
    while(cin>>n)
        cout<<n*(n*2+1)+1<<endl;
    return 0;

}