#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int q,num[1004],tl;
char s[100005];
char t[100005];
int Next[100005];

void getnext(char *ptr)
{

    int i,n,k;
    n=strlen(ptr);
    k=-1;
    Next[0]=-1;
    i=0;
    while(i<n)
    {
        if(k==-1 || ptr[i]==ptr[k])// k=-1用于指针i的移动 结合k=Next[k]看
        {
            i++;
            k++;
            Next[i]=k;
        }
        else k=Next[k];
    }
}

int kmp(char *a,char *b)//匹配ab两串，a为父串
{
    int i=0,j=0;
    int len1=strlen(a);
    int len2=strlen(b);
    getnext(b);
    while(i<len1&&j<len2)
    {
        if(j==-1||a[i]==b[j])
            ++i,++j;
        else
            j=Next[j];

    }
    if(j==len2)
        return  i-j;
    else
        return -1;
}

int main(){
    scanf("%s",t);
    tl = strlen(t);
    cin>>q;
    while(q--){
        scanf("%s",s);
        int sl=strlen(s);
        if(sl==tl){
            if(kmp(s,t)!=-1) cout<<"jntm!"<<endl;
            else cout<<"friend!"<<endl;
        }
        else if(tl>sl){
            if(kmp(t,s)!=-1) cout<<"my child!"<<endl;
            else cout<<"oh, child!"<<endl;
        }
        else{
            if(kmp(s,t)!=-1) cout<<"my teacher!"<<endl;
            else cout<<"senior!"<<endl;
        }

    }
    return 0;
}
