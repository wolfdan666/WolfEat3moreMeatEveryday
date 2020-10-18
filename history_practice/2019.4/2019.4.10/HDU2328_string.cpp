// 借鉴今天第一题的板子和思路，于是就写得很轻松2019年4月10日21:40:12 大创答辩导致没吃晚饭，现在搞好git上传就去吃饭

#include<bits/stdc++.h>
using namespace std;
string str[4010],ans[1000];
int N;
bool cmp(string a, string b){ return a.length() < b.length();}

string pd(string a){
    int len = a.length();
    int k=0;
    for(int i = len; i >= 1; i--){  // 从最短字串str[0]的全长开始递减长度
        for(int j = 0; j+i <= len; j++){ // 逐步漂移长度为i的滑块
            string temp = a.substr(j, i);
            int b = 1;
            for(int h = 1; h < N; h++){
                if(str[h].find(temp) != -1)
                    continue;
                b = 0;
                break;
            }
            if(b){
                ans[k++]=temp; //cout<<"I come :"<<temp<<endl;
                // 输出发现原来，后面长度短的可以不管
            }
        }
        if(k){
            // for(int i=0;i<k;i++) cout<<ans[k]<<" ---"; cout<<endl;   // 这里debug写错，不是ans[k]
            sort(ans,ans+k);
            // for(int i=0;i<k;i++) cout<<ans[k]<<" ---"; cout<<endl;
            return ans[0];
        }
    }
    return "IDENTITY LOST";
}

int main(){
    ios::sync_with_stdio(false);
    // string test = "bbbbbabb";
    // cout<<test.substr(0,int(test.length()));
    while((cin>>N)&&N){
        for(int i = 0; i < N; i++){
            cin >> str[i];
        }
        sort(str, str+N, cmp);
        string flag = pd(str[0]);
        cout << flag << endl;
    }
    return 0;
}