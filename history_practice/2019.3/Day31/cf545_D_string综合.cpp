// 2019年3月11日20:18:51开始看题
// 2019年3月11日20:31:38 前缀和的倍数以及长度的倍数一致的时候就可以输出
// 2019年3月11日20:59:43第一发tle了，发现lu用了getFail,好像不用，不过自己确实做得步骤多了
// 2019年3月11日21:11:30不过感觉又会tle，居然re4，看数据发现t是单独一个0！我写的鲁棒性太差了
// 后面又交了，发现自己根本没有考虑重复性，没用kmp，后面借鉴了lu的code才写完

// 2019年3月11日22:14:32  自己还是练习太少了,比陆达明菜太多了!!!为了夺金，要苦练了，因为你的对手很可能就是比陆达明还牛逼的人
#include<bits/stdc++.h>
using namespace std;
const int M = 500000+5;
char s[M],t[M];int f[M];

void getFail(char *p,int *f,int m){
    f[0]=f[1]=0;
    for(int i=1;i<m;i++){
        int j=f[i];
        while(j&&p[i]!=p[j]) j=f[j];
        f[i+1]= p[i]==p[j] ? j+1:0;
    }
}

int main(int argc, char const *argv[]){
    scanf("%s%s",s,t);
    int n=strlen(s),m=strlen(t);
    getFail(t,f,m);
    if(n<m) printf("%s\n",s);
    else{
        int ssum=0/*,tsum=0*/,tsumtem=0;
        for(int i=0;i<n;i++) ssum+=s[i]-'0';
        // for(int i=0;i<m;i++) tsum+=t[i]-'0';
        for(int i=0;i<m-f[m];i++) tsumtem+=t[i]-'0';
        // int cnt=n/m; // 长度的倍数     // 改了这里，while也要改
        int szore = n-ssum;
        // int tzore = m-tsum;
        int tzoretem = (m-f[m])-tsumtem;// tsumtem只用来计算cnt，不能影响总的部分
        int cnt = min(tsumtem?ssum/tsumtem:M,tzoretem?szore/tzoretem:M);
        szore-=cnt*tzoretem;  ssum-=cnt*tsumtem;
        while(cnt--){
            // if((szore-tzore)>=0&&(ssum-tsum)>=0){printf("%s",t);szore-=tzore;ssum-=tsum;}
            // else{
            //     while(szore--) printf("%c",'0' );
            //     while(ssum--) printf("%c", '1');
            // }
            // printf("%s",t);szore-=tzore;ssum-=tsum;
            for (int i = 0; i < m-f[m]; ++i){
                printf("%c", t[i]);
            }
        }
        for(int i=m-f[m];i<m;i++){// 由于前面是重复的，所以一定有余，可以直接输出
            if((t[i]-'0')==1&&ssum>0){
                printf("%c", t[i]);
                ssum--;
            }
            else if((t[i]-'0')==0&&szore>0){
                printf("%c", t[i]);
                szore--;
            }
            else break;
        }
        while(szore--) printf("%c",'0' );
        while(ssum--) printf("%c", '1');
        puts("");
    }

    return 0;
}