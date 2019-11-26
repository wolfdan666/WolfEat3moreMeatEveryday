/*
2019年11月13日21:38:40 开始
直接看别人的代码吧，晚上听报告去了,昨天也没有想出来这题怎么写

通过数组实现存储取球情况

2019年11月13日21:55:08 快速下一题
*/
// 链接：https://www.nowcoder.com/questionTerminal/43f0d9a6a17040dc8c6ddf3b70541253?f=discussion

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
struct node{
    int num;
    vector<vector<int> > v;
};

int main(){
    int K, N,Ki;
    cin >> K >> N;
    vector<node> ball(K);
    for(int i=0;i<K;i++){
        node p;
        cin>>Ki;
        ball[i].num=Ki;
    }
    if(K==1) cout<<N<<endl;
    else {
        vector<int> tmpv;
        // 这里就是把第一种球的可以取出的个数值的各种方案存到里面
        for(int i=0;i<=ball[0].num;i++) {
            tmpv.push_back(i);
            ball[0].v.push_back(tmpv);
            tmpv.clear();
        }
        // dp算法，子状态递推...真的是dp大法好啊
        for(int i=1;i<K;i++){
            for(int j=0;j<(int)ball[i-1].v.size();j++){
                for(int k=0;k<=ball[i].num;k++){
                    tmpv=ball[i-1].v[j];
                    tmpv.push_back(k);
                    if(i==K-1){
                        if(accumulate(tmpv.begin(),tmpv.end(),0)==N){
                            for(int l=0;l<(int)tmpv.size();l++) cout<<tmpv[l];
                            cout<<endl;
                        }
                    }
                    else {
                        if(accumulate(tmpv.begin(),tmpv.end(),0)<=N) ball[i].v.push_back(tmpv);
                    }
                    tmpv.clear();
                }
            }
        }
    }

    return 0;
}