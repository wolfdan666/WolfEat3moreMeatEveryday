#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
struct node{
    int x,y;
    int stp;
    int cnt;
};
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int sx,sy;
int n,m;
int ex,ey;
bool check(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=m){
        return true;
    }
    else{
        return false;
    }
}
char Map[505][505];
int vis[505][505];
int  BFS(){
    queue<node>q;
    node st;
    st.x=sx;
    st.y=sy;
    st.stp=0;
    st.cnt=5;
    vis[sx][sy]=1;
    q.push(st);
    while(!q.empty()){
        node now =q.front();
        if(now.x==ex&&now.y==ey)return now.stp;
        q.pop();
        node nxt;
        for(int i=0;i<4;i++){
            nxt.x=now.x+dir[i][0];
            nxt.y=now.y+dir[i][1];
            nxt.stp=now.stp+1;
            nxt.cnt=now.cnt;
            if(check(nxt.x,nxt.y)&&vis[nxt.x][nxt.y]==0&&(Map[nxt.x][nxt.y]=='.'||Map[nxt.x][nxt.y]=='E')){
               vis[nxt.x][nxt.y]=1;
               q.push(nxt);
            }
        }
        if(now.cnt>=1){
        nxt.x=n+1-now.x;
        nxt.y=m+1-now.y;
        nxt.stp=now.stp+1;
        nxt.cnt=now.cnt-1;
        if(check(nxt.x,nxt.y)&&vis[nxt.x][nxt.y]==0&&(Map[nxt.x][nxt.y]=='.'||Map[nxt.x][nxt.y]=='E')){
               vis[nxt.x][nxt.y]=1;
               q.push(nxt);
            }
        }
    }
    return -1;

}
int main(){

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%s",Map[i]+1);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(Map[i][j]=='S'){
                sx=i;sy=j;
            }
            if(Map[i][j]=='E'){
                ex=i;ey=j;
            }
        }
    }
    cout<<BFS()<<endl;
    return 0;
}