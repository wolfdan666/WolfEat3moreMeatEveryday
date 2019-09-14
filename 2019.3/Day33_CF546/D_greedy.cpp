// 2019年3月15日20:40:30 开始看题
// 我想到的是穷举遍历，找出能到达的最小下标，但是好像复杂度过高，emmm，借鉴一下吧
// 2019年3月15日21:08:44终于理解了大佬的code，就是直接用C数组记录各个点能倒退的距离，然后如果刚好这个距离
// 和主角的位置是一样的，那就正好可以换一个位置，从后向前遍历，就不会出错，真是太巧妙了！强
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int N,M;
int P[1000006];
int C[1000006];
vector<int> gofrom[1000006];
int x,y,ans;

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>P[i];
    for(int i=0;i<M;i++){
        cin>>x>>y;
        gofrom[y].push_back(x);
    }

    for(int i=N-1;i>=0;i--)
        if(C[P[i]]==N-1-i-ans and i!=N-1)
            ans++;
        else
            for(int f:gofrom[P[i]])
                C[f]++;

    cout<<ans;
}

// tle  in  test 16!!!   我就改了一下头文件！！！真他妈的，第一次吃万能头文件的坑，做题再也不用了，cin也是
// 奇怪，改回来，tle在15！？？什么鬼

// 查明原因，居然是C++14能过，C++11不能过！

#include <iostream>
#include <vector>
using namespace std;

int N,M;
int P[1000006];
int C[1000006];
vector<int> grafo[1000006];
int x,y,ans;

int main(){

    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>P[i];
    for(int i=0;i<M;i++){
        cin>>x>>y;
        grafo[y].push_back(x);
    }

    for(int i=N-1;i>=0;i--)
        if(C[P[i]]==N-1-i-ans and i!=N-1)
            ans++;
        else
            for(int f:grafo[P[i]])
                C[f]++;

    cout<<ans;
}