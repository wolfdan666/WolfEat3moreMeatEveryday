/*原题被扣10%的钱233*/

#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int INF = 1e9;
const int SIZE = 1<<24;
const int MASK = SIZE - 1;
int L[1000005],R[1000005];
int cnt[SIZE],u[SIZE];
#define U(X) u[(X)&MASK]
#define CNT(X) cnt[(X)&MASK]
LL an;
void add(int x){
    if(U(x)==x)CNT(x)++;
    else{
        CNT(x)=1;
        U(x)=x;
    }
}
int get(int x){
    if(U(x)==x)return CNT(x);
    return 0;
}
int main(){
    DRI(n);
    REPP(i,1,n+1){RII(L[i],R[i]);R[i]++;}
    L[n+1]=R[n+1]=INF;n+=2;
    int now=INF,down=INF,up=INF,all=0;
    add(now);
    REPP(i,1,n)
    {
        int dif=L[i]-R[i-1];
        if(dif)
        {
            while(now-1>down&&dif)
            {
                now--;
                all-=get(now);
                an+=all;
                dif--;
            }
            if(dif){
                all=0;
                now-=dif;
                down=min(down,now);
            }
            add(now);
        }
        REPP(j,L[i],R[i])
        {
            now++;
            all+=get(now-1);
            an+=all;
            if(j+1!=R[i])add(now);
            else if(now>=up)add(now);
            if(now<up)add(now);
            up=max(up,now);
        }
    }
    cout<<an<<endl;
    return 0;
}