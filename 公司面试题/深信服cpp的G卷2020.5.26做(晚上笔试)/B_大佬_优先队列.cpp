#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    priority_queue<int, vector<int>, less<int>> max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;
    while(cin >> N){
        while(N-- > 0){
            int num ;
            cin >> num;
            if(max_q.size() == min_q.size()){
                max_q.push(num);
                min_q.push(max_q.top());
                max_q.pop();
            }
            else{
                min_q.push(num);
                max_q.push(min_q.top());
                min_q.pop();
            }
        }
        cout << min_q.top() << endl;
    }

    return 0;
}