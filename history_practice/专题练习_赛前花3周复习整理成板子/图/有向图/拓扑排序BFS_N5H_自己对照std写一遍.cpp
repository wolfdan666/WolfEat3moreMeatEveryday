/*
2019年8月2日19:25:05
拓扑排序bfs

拓扑排序算法思想
1、在AOV网络中选一个没有直接前驱的顶点, 并输出之;
2、从图中删去该顶点, 同时删去所有它发出的有向边;--->(我下面的题目使用stop实现删除)
3、重复以上步骤, 直到
◆ 全部顶点均已输出，拓扑有序序列形成，拓扑排序完成；
◆ 或者图中还有未输出的顶点，但已跳出处理循环。这说明图中还剩下一些顶点，
它们都有直接前驱，再也找不到没有前驱的顶点了。这时AOV网络中必定存在有向环。
*/
#include<bits/stdc++.h>
using namespace std;
const int M = 1e4+5;
int n,m,lentmp;
string s[10][10];
/*用string本来可以不用下面的len*/
int len[10][10];
int it[10][10];
string ans,t;
bool check();
bool solve();

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m*(m-1)/2;i++){
        cin>>t>>lentmp;
        int x=t[0]-'a',y=t[1]-'a';
        if(x>y) swap(x,y);
        len[x][y] = lentmp;
        // if(lentmp) cin>>s[x][y];
        /*我的头铁(~~比赛因此卡1小时去谷歌~~)写法
        先直接用cin.get()吃掉t和lentmp后面的回车
        再getline(),
        否则getline会吃那个回车而导致少读数据*/
        cin.get();
        getline(cin,s[x][y]);
    }
    if(!solve()) puts("-1");

    return 0;
}

/*暴力检测每队关系是否和整个串中的样子是一样的
法二: 也可以每一对关系得到一个ans的tmp串,然后再去==判断
      但是效率低
*/
bool check(){
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            int now = 0;
            for(int k=0;k<n;k++){
                if(ans[k]=='a'+i||ans[k]=='a'+j){
                    if(ans[k]!=s[i][j][now]) return 0;
                    now++;
                }
            }
            if(now!=len[i][j]) return 0;
        }
    }
    return 1;
}

bool solve(){
    for(int i=0;i<n;i++){
        /* 这里是每个大串的排序关系-通过m次的关系问询确定的

        注意前面巧妙地处理出了j小于k--->这就是拓扑排序的思路

        1.对没有出现过的关系(即s[j][k]的那一维全为空)stop[j]和stop[k]全都赋值为1
        2.对于到最后了的关系(即s[j][k][]='\0')全赋空


        因为有m*(m-1)/2 对 关系，也就是每两个都有比较，所以一定能够得出最前面的一个字符..所以就完美了！

        这里每次stop都会清零！*/
        bool stop[10] = {};
        for(int j=0;j<m;j++){
            for(int k=j+1;k<m;k++){
                if(!s[j][k][it[j][k]]) stop[j]=stop[k]=1;
                else if(s[j][k][it[j][k]]=='a'+j) stop[k]=1;
                else stop[j] = 1;
            }
        }
        bool done = false;
        for(int j=0;j<m;j++){
            if(!stop[j]){
                ans+='a'+j;
                for(int k=0;k<m;k++){
                    if(k<j) it[k][j]++;
                    else if(k>j) it[j][k]++;
                }
                done = true;
                break;
            }
        }
        if(!done) return 0;
    }
    if(!check()) return 0;
    cout<<ans<<endl;
    return 1;
}