#include<bits/stdc++.h>

struct NODE{
    int ch[26];
    int len,fa;
    NODE(){memset(ch,0,sizeof(ch));len=0;}
}dian[MAXN<<1];

int las=1,tot=1;

void add(int c){
    int p=las;int np=las=++tot;
    dian[np].len=dian[p].len+1;
    for(;p&&!dian[p].ch[c];p=dian[p].fa)dian[p].ch[c]=np;
    if(!p)dian[np].fa=1;//以上为case 1
    else{
        int q=dian[p].ch[c];
        if(dian[q].len==dian[p].len+1)dian[np].fa=q;//以上为case 2
        else{
            int nq=++tot;dian[nq]=dian[q];
            dian[nq].len=dian[p].len+1;
            dian[q].fa=dian[np].fa=nq;
            for(;p&&dian[p].ch[c]==q;p=dian[p].fa)dian[p].ch[c]=nq;//以上为case 3
        }
    }
}

char s[MAXN];int len;

int main(){
    scanf("%s",s);len=strlen(s);
    for(int i=0;i<len;i++)add(s[i]-'a');
}