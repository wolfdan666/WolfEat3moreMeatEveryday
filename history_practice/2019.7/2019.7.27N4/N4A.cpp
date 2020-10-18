/*
图论好久没写，写太慢了自己，然后让队友写去了
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
const int M = 1e5+7;
bool visited[M];
struct node{
    int id;
    vector<int> next;
} a[M];
int n,k;

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>a[i].id>>tmp;
        a[i].next.push_back(tmp);
    }
    return 0;
}