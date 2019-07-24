#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 3e5 + 7;
char s[M];
char s_new[2*M];
int p[2*M];

int Init(){
    int len = strlen(s);
    // cout<<"test"<<len<<endl;
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;

    for (int i = 1; i < len; i++){
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }

    s_new[j] = '\0';  // 别忘了哦
    return j;  // 返回 s_new 的长度
}

void Manacher(){
    int len = Init();  // 取得新字符串长度并完成向 s_new 的转换
    // int max_len = -1;  // 最长回文长度

    int id;
    int mx = 0;

    for (int i = 1; i < len; i++){
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i);  // 需搞清楚上面那张图含义, mx 和 2*id-i 的含义
        else
            p[i] = 1;

        while (s_new[i - p[i]] == s_new[i + p[i]])  // 不需边界判断，因为左有'$',右有'\0'
            p[i]++;

        // 我们每走一步 i，都要和 mx 比较，我们希望 mx 尽可能的远，这样才能更有机会执行 if (i < mx)这句代码，从而提高效率
        if (mx < i + p[i]){
            id = i;
            mx = i + p[i];
        }

        // max_len = max(max_len, p[i] - 1);
    }
    // return max_len;
    return ;
}

int main(){
    while(~scanf("%s",s)){
        int n = strlen(s);

        // for(int i=1;i<=n;i++) cout<<s[i]<<endl;
        s[n+1]='\0';
        for(int i=n;i>=1;i--) s[i]=s[i-1];
        // for(int i=1;i<=n;i++) cout<<s[i]<<endl;
        Manacher();
        printf("%d ",n );
        for(int len=2;len <= n;len++){
            int ans = 0;
            for(int l=1;l<=n-(len-1);l++){
                int r = l + len - 1;
                int r2 = (l+r)/2;
                int x = l+r;
                int y = l+r2;
                // int y = x&1? x/2+1 : x/2;
                // int y =  x/2+1 ;
                if(p[x]-1>=len && p[y]-1>=len/2) ans++;
            }
            printf("%d",ans );
            if(len!=n) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}