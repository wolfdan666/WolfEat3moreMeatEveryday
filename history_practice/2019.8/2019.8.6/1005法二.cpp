/*
思路：首先字典序最小的序列一定是n,1,2,3.........n-2,n-1这样的。
再考虑8的阶乘是40320，9的阶乘是362880，所以9以下的直接预处理全排列找出所有的可行解，
排序，对于每次访问第k大的输出即可，对于9以上的，从10开始那么第一项和第二项就是固定的a[1]=n，a[2]=1，
那么剩下的n-2项是大于等于8的，由于数据小于1e4所以全排列也不会影响到第二项的1，所以直接固定前两项，
对于后面的n-2项全排列k次即可
---------------------
Author：CSDN博主「hrbust-nzc」
原文链接：https://blog.csdn.net/qq_43316231/article/details/98520452

*/


#include<bits/stdc++.h>
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
        /*cnt记录的是长度为k的排列的个数...后面的sort得出名次*/
        int cnt=1;
        do{
            for(int i=1;i<=k;i++){
                a[k][cnt].num[i]=b[i];
                if(i!=1)a[k][cnt].str[i-2]=b[i]-b[i-1]+'A';
                /*加A是为了防止有负值！我猜strcmp应该是可以比较ASCII码里面所有值的,只要是char就行*/
                // if(i!=1)a[k][cnt].str[i-2]=b[i]-b[i-1];
            }
            a[k][cnt].str[k-1]='\0';
            cnt++;
        }while(next_permutation(b+1,b+k+1));
        /*按照题目要求的sort方式进行sort*/
        // if(k==3) for(int i=1;i<cnt;i++) cout<<string(a[k][i].str)<<" "; cout<<endl;
        sort(a[k]+1,a[k]+cnt,cmp);
        // if(k==3) for(int i=1;i<cnt;i++) cout<<string(a[k][i].str)<<" "; cout<<endl;
        b[k+1]=k+1;
    }
}

int main(){
    pre();
    scanf("%d",&t);
    while(t--){
        int k;
        scanf("%d%d",&n,&k);
        if(n>9){
            int c[30];
            c[1]=n;
            for(int i=2;i<=n;i++) c[i]=i-1;
            for(int i=1;i<k;i++){
                next_permutation(c+1,c+n+1);
            }
            for(int i=1;i<=n;i++){
                printf("%d%c",c[i]," \n"[i==n]);
            }
            continue;
        }
        for(int i=1;i<=n;i++){
            printf("%d%c",a[n][k].num[i]," \n"[i==n]);
        }
    }
    return 0;
}