#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int inf = 0x3f3f3f3f;
const int MAXN = 1e6+10;
ll ans;

char S[MAXN],T[MAXN];
int t,n,m;
int next[MAXN],extend[MAXN];
int val[30],sum[MAXN];
void EKMP(char *S,char *T,int *next,int *extend){
    int j=0;
    int k=1;
    while(j+1<n && T[0+j]==T[1+j])
        j++;
    next[1]=j;
    for(int i=2;i<n;i++)
    {
        int len=k+next[k]-1,L=next[i-k];
        if(L<len-i+1)
            next[i]=L;
        else
        {
            j=max(0,len-i+1);
            while(i+j<n && T[i+j] == T[0+j])
                j++;
            next[i]=j;
            k=i;
        }
    }
    j=0;
    while(j<n && S[0+j]==T[0+j])
        j++;
    extend[0]=j;
    k=1;
    for(int i=1;i<n;i++)
    {
        int len=k+extend[k]-1,L=next[i-k];
        if(L<len-i+1)
            extend[i]=L;
        else
        {
            j=max(0,len-i+1);
            while(i+j<n && j<n && S[i+j]==T[j])
                j++;
            extend[i]=j;
            k=i;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>t;
    while(t--){
        ans = 0;
        cin>>S;
        int len = strlen(S);
        n = m = len;
        EKMP(S,S,next,extend);
        for(int i=0;i<len;i++) ans+=extend[i];
        cout<<ans<<endl;

    }

    return 0;
}