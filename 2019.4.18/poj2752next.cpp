// 2019年4月18日21:07:48开始看题
// 就是把所有非 0 的next[]值用getFail一直记录然后输出,记得最后输出自己本身的长度
// 真心不懂poj这个到底怎么判题的，我也是醉了，每次都莫名其妙地RE了
/*#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
const int M = 4e5+5;
// string s;
int f[M];
char s[M];
vector<int> ans;

// void getFail(string p){
void getFail(char * p){
    // int n = int(p.length());
    int n = int(strlen(s));
    f[0]=f[1]=0;
    for(int i=1;i<n;i++){
        int j = f[i];
        while(j&&p[i]!=p[j]) j = f[j];
        f[i+1] = p[i]==p[j] ? j+1:0;
    }
    // for(int i = 0;i<=n+1;i++) cout<<f[i]<<" "; cout<<endl;
}

int main(int argc, char const *argv[])
{
    // ios::sync_with_stdio(false);
    // while(cin>>s) {
    while(scanf("%s",s)!=EOF){
        getFail(s);
        // int l = int(s.length());
        int l = int(strlen(s));
        int tem = l;
        while(f[tem]) {
            ans.push_back(f[tem]);
            tem = f[tem];
        }
        vector<int>::reverse_iterator rit = ans.rbegin();
        // cout<<*rit;
        printf("%d ",*rit);
        for(rit++;rit!= ans.rend();++rit){
            // cout<<" "<<*rit;
            printf("%d ",*rit);
        }
        printf("%d \n",l);
        ans.clear();
    }
    return 0;
}*/


#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 400000 + 10;
char s1[maxn];
int len;
int nextv[maxn];
int ans[maxn];
void getnext(){
    int i = 0,j = -1;
    nextv[0] = -1;
    while(i<len){
        if(j == -1 || s1[j] == s1[i]){
            nextv[++i] = ++j;
        }
        else
            j = nextv[j];
    }
}
int main(){
    int n;
    while(scanf("%s",s1)!=EOF){
        // memset(nextv,0,sizeof(nextv));
        len = strlen(s1);
        getnext();
        int tmp = len;
        ans[0] = len;
        int cnt = 1;
        while(nextv[tmp]!=0){
            ans[cnt++]=nextv[tmp];
            tmp = nextv[tmp];
        }
        for(int i=cnt-1;i>0;i--)
            printf("%d ",ans[i]);
        printf("%d\n",ans[0]);
    }
    return 0;
}