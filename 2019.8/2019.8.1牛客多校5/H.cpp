/*
暴力算法...

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
const int M = 1e4+7;
string s,tmp,x,y;
int n,m,len;
int cnt[12];

int main(){
    // ios::sync_with_stdio(false);
    cin>>n>>m;
    int k = m*(m-1)/2;
    bool flag = 1;
    for(int i=0;i<k;i++){
        /*为什么下面用了getline，这里x,和len会被吃掉？*/
        /*因为getline会读入第一个空行,所以要用cin.get()把第一个空行吃掉*/
        cin>>x>>len;
        cin.get();
        getline(cin,y);
        int f = (cnt[x[0]-'a']!=0) + (cnt[x[1]-'a']!=0);

        /*定义在外面啊*/
        char a,b;
        if (cnt[x[0] - 'a'] != 0) a = x[0], b = x[1];
        else a = x[1],b = x[0];

        if(f==0){
            s+=y;
            for(int j=0;j<int(y.length());j++) cnt[y[j]-'a']++;
        }
        /* 把存在的字母(a)进行对比，不存在的字母(b)进行插入 */
        else if(f==1){
            int p = 0;string tmp1;bool f=0;
            while(y[p]==b){tmp1+=b;p++;cnt[b-'a']++;}
            /* 这里s.length()是动态变化的 */
            for(int j=0; p<len && j<int(s.length());j++){
                if(s[j]==y[p]) p++,f=1;
                else if(f && y[p]==b){
                    string tmp2;int inttmp=0;
                    while(p<len && y[p]==b){tmp2+=b;p++;inttmp++;cnt[b-'a']++;}
                    s.insert(j,tmp2);
                    j+=inttmp;
                }
            }
            if(p<len){ s+=y.substr(p,len); break;}
            s = tmp1+s;
        }
        /*这里如果顺序反了可能是插入顺序的问题,所以这里可能是要调整顺序！*/
        else if(f==2){
            /*init*/
            vector<int> change;
            change.clear();tmp.clear();
            char a = x[0], b = x[1];
            for(int j=0;j<int(s.length());j++){
                if(s[j]==a) tmp+=a,change.push_back(j);
                if(s[j]==b) tmp+=b,change.push_back(j);
            }
            // cout<<"s: "<<s<<" tmp: "<<tmp<<endl;
            // if(tmp!=y) flag=0;
            /*用y更新tmp...但是万一是本来就是反的呢？*/
            for(int k = 0;k < int(y.length());k++){
                s[change[k]] = y[k];
            }
            // cout<<"s: "<<s<<" y: "<<y<<endl;
        }
        // cout<<"s: "<<s<<"flag: "<<flag<<endl;

    }
    if(int(s.length())>n) flag = 0;
    if(flag) cout<<s<<endl;
    else cout<<-1<<endl;
    return 0;
}