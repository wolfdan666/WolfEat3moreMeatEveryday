// 2019年4月25日20:29:28 开始看题
// emmm,本来自己是在对着模板改写的，但感觉这个处理有点繁杂，结果发呆了25mins,所以不做这个处理了吧

// 这个操作有点骚，由于今天有点心不在焉，所以没有深入，只是浅层理解，下不为例
// https://www.cnblogs.com/cenariusxz/p/4510986.html
// #include <bits/stdc++.h>

// g++内存溢出，c++AC...  绝了

#include "cstdio"
#include "cstring"
#include "string"
#include "iostream"
#include "queue"
#include "vector"
#include "algorithm"
using namespace std;
#define maxn 130

struct Trie{
    Trie *next[maxn],*fail;
    int cnt;
}*root;

struct status{
    Trie *last;
    int cnt;
    status(Trie *last,int cnt):last(last),cnt(cnt) {}
};

Trie *newnode(){
    Trie *ret=new Trie;
    memset(ret->next,0,sizeof(ret->next));
    ret->fail=0;
    ret->cnt=0;
    return ret;
}

void init() {root=newnode();}

void Insert(string str,int index){
    Trie *pos=root;
    for(int i=0;i<str.size();i++){
        int c=str[i];
        if(!pos->next[c]) pos->next[c]=newnode();
        pos=pos->next[c];
    }
    pos->cnt=index;
}

void getfail()
{
    queue<Trie *> Q;
    for(int c=0;c<maxn;c++)
    {
        if(root->next[c])
        {
            root->next[c]->fail=root;
            Q.push(root->next[c]);
        }
        else root->next[c]=root;
    }
    while(!Q.empty())
    {
        Trie *x=Q.front();Q.pop();
        for(int c=0;c<maxn;c++)
        {
            if(x->next[c])
            {
                x->next[c]->fail=x->fail->next[c];
                Q.push(x->next[c]);
            }
            else x->next[c]=x->fail->next[c];
        }
    }
}

vector<int> find(string str)
{
    Trie *pos=root,*last;
    queue<status> Q;
    vector<int> ans;
    for(int i=0;i<str.size();i++)
    {
        int c=str[i];last;
        if(pos->next[c])
        {
            pos=pos->next[c];
            last=pos;
            while(last->cnt)
            {
                Q.push(status(last,last->cnt));
                ans.push_back(last->cnt);
                last->cnt=0; //修改last->cnt
                last=last->fail;
            }
        }
    }
    while(!Q.empty()) //恢复last->cnt
    {
        status x=Q.front();Q.pop();
        x.last->cnt=x.cnt;
    }
    return ans;
}

int main()
{
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    int n,m;
    string tt;
    while(cin>>n)
    {
        init();
        for(int i=1;i<=n;i++)
        {
            cin>>tt;
            Insert(tt,i);
        }
        getfail();
        cin>>m;
        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            cin>>tt;
            vector<int> ans=find(tt);
            sort(ans.begin(),ans.end());
            if(!ans.size()) continue;
            cnt++;
            printf("web %d:",i);
            for(int j=0;j<ans.size();j++) printf(" %d",ans[j]);
            printf("\n");
        }
        printf("total: %d\n",cnt);
    }
}