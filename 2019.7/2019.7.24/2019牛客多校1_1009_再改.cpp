/*2019年7月23日20:33:32 建立完后缀数组,觉得有必有记录一下时间，所以就写了这个
看一下自己写手动写第一遍的速度

2019年7月23日21:02:26 老是卡住，还是得借鉴别人的.刷多次吧
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
const int M = 1e5+7;
char s[M], s1[M];
int l[26],r[26],used[26];
int n,k;
/*字母后的各字母后缀和数组*/
int cnt[M][26];
/*字母下标记录数组*/
vector<int> g[26];

int main(){
    // ios::sync_with_stdio(false);cin.tie(0);
    while(~scanf("%s%d", s, &k)){
        for(int i=0;i<26;i++) cin>>l[i]>>r[i];
        /*init*/
        memset(used,0,sizeof(used));
        n = strlen(s);
        for(int i=0;i<26;i++) cnt[n][i]=0,g[i].clear();
        for(int i=n-1;i>=0;i--) for(int j=0;j<26;j++) cnt[i][j]+=cnt[i+1][j]+(s[i]==('a'+j));
        for(int i=0;i<n;i++) g[s[i]-'a'].push_back(i);
        vector<int>::iterator head[26];
        for(int i=0;i<26;i++) head[i]=g[i].begin();
        int last = -1;
        /*solve*/
        for(int i=0;i<k;i++){
            bool f=0;
            for(int j=0;j<26;j++){
                if(used[j] == r[j]) continue;
                /*subsequence时不用连续，但是要保持前后顺序,所以可以共用同一个last*/
                while(head[j]!=g[j].end() && (*head[j]) <= last) head[j]++;
                if(head[j] == g[j].end()) continue;
                used[j]++;
                bool flag = 1;
                int pos = *head[j],sum=0;

                /*注意这里是pos+1,因为现在讨论的是本位已经使用的情况下,对其他位置的影响*/
                for(int p=0;p<26;p++){
                    if(cnt[pos+1][p] + used[p] < l[p]) flag = 0;
                    sum += max(l[p] - used[p],0);
                }
                /*后面的位置的所有字母要达到的最小总和如果超过了能用的量,
                能使用的 位置 不够了
                就说明此位置不能放'a'+j字母*/
                if(sum > k-(i+1)) flag = 0;
                sum = 0;
                for(int p=0;p<26;p++) sum += min(cnt[pos+1][p],r[p]-used[p]);
                /*后面的位置的所有字母最多放的位置个数和如果小于剩余的位置
                能使用的 位置 填不满了
                就说明此位置不能放'a'+j字母*/
                if(sum < k-(i+1)) flag = 0;
                if(!flag) used[j]--;
                else{
                    s1[i] = 'a' + j;
                    f = 1;
                    last = pos;
                    break;
                }
            }
            if(!f){
                cout<<"-1"<<endl;
                goto end;
            }
        }
        s1[k]=0;
        cout<<s1<<endl;
        end:;
    }

    return 0;
}