/*nl代表目前的number of 零, l 之前的 number of 零*/
/*"%x"以16进制的形式输出,是我孤陋寡闻了*/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[10];
int main(){
    int T,t;
    scanf("%d",&T);
    for(int ii=1;ii<=T;ii++){
        int f=0,l=0,nl=0;
        /*观察下面的代码容易知道,只有最前面为0的时候是f=1,
        其他地方为0,f为i-nl(减掉了0的长度即为0开始的地方)

        综上:
        f是最长连续0开始的位置
        然后l是保存维护最长连续0的长度
        nl是当前的最长连续0的长度*/
        for(int i=1;i<=8;i++){
            a[i]=0;
            for(int j=1;j<=16;j++){
                scanf("%1d",&t);
                a[i]=a[i]*2+t;
            }
            if(!a[i]) nl++;
            else{
                /*判断现在的连续0的数目是否超过之前的连续0的数目*/
                if(nl>=l&&nl>1){
                    f=i-nl;l=nl;
                }
                nl=0;
            }
            if(i==8&&nl>1){
                if(nl>l){
                    f=i-nl+1;l=nl;
                }
                /*末尾有0，但是末尾的连续0和最前面的连续0相同
                所以考虑字典序最小，由于'0'-48,':'-58
                所以优先让前面输出0,后面就输出':'*/
                if(nl==l&&f==1){
                    f=i-nl+1;l=nl;
                }
            }
        }
        printf("Case #%d: ",ii);
        if(f==1)printf(":");
        for(int i=1;i<=8;i++){
            if(i==f){
                printf(":");
                i+=l;
            }
            if(i>8)puts("");
            else printf("%x%c",a[i],":\n"[i==8]);
        }
    }
    return 0;
}