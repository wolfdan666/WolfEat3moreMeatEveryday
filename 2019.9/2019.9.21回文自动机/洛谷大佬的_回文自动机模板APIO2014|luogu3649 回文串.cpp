// 洛谷大佬写法
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[300010];
struct Pld_T{
    int ch[26],fail,len,cnt;
};
Pld_T pld_t[300010];
int tot;
int main()
{
    int i,j,k,len;
    long long ans=0;
    scanf("%s",s+1);
    len=strlen(s+1);s[0]='#';
    pld_t[0].fail=1;k=0;pld_t[1].len=-1;tot=1;
    for(i=1;i<=len;i++){
        while(s[i-pld_t[k].len-1]!=s[i])k=pld_t[k].fail;
        if(!pld_t[k].ch[s[i]-'a']){
            pld_t[++tot].len=pld_t[k].len+2;
            j=pld_t[k].fail;
            while(s[i-pld_t[j].len-1]!=s[i])j=pld_t[j].fail;
            pld_t[tot].fail=pld_t[j].ch[s[i]-'a'];
            pld_t[k].ch[s[i]-'a']=tot;
        }
        k=pld_t[k].ch[s[i]-'a'];
        pld_t[k].cnt++;
    }
    for(i=tot;i>=2;i--){
        pld_t[pld_t[i].fail].cnt+=pld_t[i].cnt;
        if((long long)pld_t[i].cnt*pld_t[i].len>ans)
            ans=(long long)pld_t[i].cnt*pld_t[i].len;
    }
    printf("%lld",ans);
    return 0; 
}