/*
对于答案来说，一定是

前 i-1 个字符和 t的前 i 个一样，然后第 i 个字符比 t的 大 \(i\in [1,m]\)
前缀为t，然后长度比t长
对于第一种情况，枚举这个 i ，然后找最小的 p 可以使得从\(s[1\sim p]\) 中产生\(t_1t_2\cdots t_{i-1}\) ,然后在\(s[p+1,n]\)中找最左边的比\(t[i]\) 大的字符，假如 找到了\(s[pos]\)，那么后面的\(s[pos+1,n]\) 都可以加到答案后面（因为\(s[pos] > t[i]\) 已经保证答案大于t了)

对于第二种，根据求第一种的方法，不难求出

如何找最小的p？预处理一个\(sf[i][c]\) 数组，表示\(s[i]\) 后面第一个字符\(c\)在哪里即可

如何找pos? 也是用预处理的数组循环最多26次即可

复杂度\(O(n*26)\)
*/


#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int sf[N][26];

char s[N],t[N];

int n,m;
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s%s",s+1,t+1);
    for(int i=0;i<26;i++) sf[n][i] = n+1;

    // 预处理一个(sf[i][c]) 数组，表示(s[i]) 后面第一个字符(c)在哪里
    for(int i=n-1;i>=0;i--){
        memcpy(sf[i],sf[i+1],sizeof sf[i]);
        sf[i][s[i+1]-'a'] = i+1;
    }

    int p = 0,res = -1;
    for(int i=1;i<=m;i++){
        int pos = n+1;
        for(int j=t[i]-'a'+1;j<26;j++){
            pos = min(pos,sf[p][j]);//找到最近的那个s[pos] > t[i];
        }
        if(pos != n+1)
            res = max(res,i+n-pos);//(n-pos)为后面还可以加的长度
        // p在s中找到与t相同的"前缀"(不连续子串可以跳跃)
        p = sf[p][t[i]-'a'];
        if(p == n+1)break;
    }
    // 如果完全相同，那就要严格更大，所以p<n
    if(p < n) res = max(res,n-p+m);
    printf("%d\n",res);
    return 0;
}