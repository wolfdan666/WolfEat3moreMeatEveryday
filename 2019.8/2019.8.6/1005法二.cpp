#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5;
int n,m,t;
struct p{
    int num[11];
    char str[11];
}a[11][N];
bool cmp(p aa, p bb){
    return strcmp(aa.str,bb.str)<0;
}

void pre(){
    int b[15]={0,1,2};
    for(int k=2;k<=9;k++){

        int cnt=1;
        do{
            for(int i=1;i<=k;i++){
                a[k][cnt].num[i]=b[i];
                if(i!=1)a[k][cnt].str[i-2]=b[i]-b[i-1]+'A';
            }
            a[k][cnt].str[k-1]='\0';
            cnt++;
        }while(next_permutation(b+1,b+k+1));

        sort(a[k]+1,a[k]+cnt,cmp);
        b[k+1]=k+1;
    }
}

int main(){
    scanf("%d",&t);
    while(t--){
        int k;
        scanf("%d%d",&n,&k);
        if(n>9){
            int c[30];
            c[1]=n;
            for(int i=2;i<=n;i++)c[i]=i-1;
            for(int i=1;i<k;i++){
                next_permutation(c+1,c+n+1);
            }
            for(int i=1;i<=n;i++){
                i==1||printf(" ");
                printf("%d",c[i]);
            }
            printf("\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            i==1||printf(" ");
            printf("%d",a[n][k].num[i]);
        }
        printf("\n");
    }
    return 0;
}