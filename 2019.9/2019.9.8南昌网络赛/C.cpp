/*
队友ldm让我别交C了,没有意义...不如做其他题让一队上天
Codeforces 750 E -- 2600分 , lxc 7分钟一血带偏榜 最后2019年9月8日16:30:12的时候 179 / 3412

用线段树维护一个dp[i][j]表示从区间的起点，起始位状态i，到区间的终点，状态为j的时候的所需要删除的字符的最少的个数。
其中0表示前面没有包含任何关于“2017”的子序列，1表示包含子序列1，2表示包含子序列12，依次类推，
特别注意在3、4状态的时候的花费。不可能的状态标记为-1即可。查询的合并下区下区间的DP值即可。

参考大佬:https://blog.splayx.com:10443/?p=385
*/
/*#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
struct node{
    LL dp[5][5];
    node(){
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                dp[i][j] = INT_MAX;
    }
    node operator + (const node &b) const{
        node c;
        for(int i = 0; i < 5; i++)
            for(int j = i; j < 5; j++)
                // 查看两者之间各种状态的转化(i->j)需要删除的字符数
                for(int k = i; k <= j; k++) c.dp[i][j] = min(c.dp[i][j], dp[i][k] + b.dp[k][j]);
        return c;
    }
} tree[maxn * 4];
char s[maxn];

void build(int id, int L, int R){
    if(L == R){
        for(int i = 0; i < 5; i++) tree[id].dp[i][i] = 0;
        // 若非2,0,1,7,6 则直接使用初始化的MAX_INT就行...
        if(s[L] == '2'){
            // 0状态到达状态1只要删除0个
            tree[id].dp[0][1] = 0;
            tree[id].dp[0][0] = 1;
        }
        else if(s[L] == '0'){
            tree[id].dp[1][2] = 0;
            tree[id].dp[1][1] = 1;
        }
        else if(s[L] == '1'){
            tree[id].dp[2][3] = 0;
            tree[id].dp[2][2] = 1;
        }
        else if(s[L] == '7'){
            tree[id].dp[3][4] = 0;
            tree[id].dp[3][3] = 1;
        }
        else if(s[L] == '6'){
            tree[id].dp[3][3] = 1;
            tree[id].dp[4][4] = 1;
        }
    }
    else{
        int mid = L + R >> 1;
        build(id << 1, L, mid);
        build(id << 1 | 1, mid + 1, R);
        tree[id] = tree[id << 1] + tree[id << 1 | 1];
    }
}

node query(int id, int L, int R, int l, int r){
    if(l <= L && R <= r) return tree[id];
    else{
        int mid = L + R >> 1;
        if(r <= mid) return query(id << 1, L, mid, l, r);
        else if(l > mid) return query(id << 1 | 1, mid + 1, R, l, r);
        else return query(id << 1, L, mid, l, r) + query(id << 1 | 1, mid + 1, R, l, r);
    }
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    scanf("%s", s + 1);
    build(1, 1, n);
    while(q--){
        int l, r;
        scanf("%d %d", &l, &r);
        LL ret = query(1, 1, n, l, r).dp[0][4];
        if(ret == INT_MAX) puts("-1");
        else printf("%d\n", (int)ret);
    }
    return 0;
}*/


// 下面是代码二



#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N];
struct Node {
    int mat[5][5];
    Node operator + (Node x) {
        Node ans;
        for(int i=0;i<5;++i) {
            for(int j=0;j<5;++j) {
                ans.mat[i][j]=N;
                for(int k=0;k<5;++k) {
                    ans.mat[i][j]=min(ans.mat[i][j],mat[i][k]+x.mat[k][j]);
                }
            }
        }
        return ans;
    }
}a[N<<2];
void build(int l,int r,int x) {
    if(l==r) {
        for(int i=0;i<5;++i) {
            for(int j=0;j<5;++j) {
                a[x].mat[i][j]=(i==j)?0:N;
            }
        }
        if(s[l]=='2') a[x].mat[0][1]=0,a[x].mat[0][0]=1;
        if(s[l]=='0') a[x].mat[1][2]=0,a[x].mat[1][1]=1;
        if(s[l]=='1') a[x].mat[2][3]=0,a[x].mat[2][2]=1;
        if(s[l]=='9') a[x].mat[3][4]=0,a[x].mat[3][3]=1;
        if(s[l]=='8') a[x].mat[3][3]=1,a[x].mat[4][4]=1;
        return ;
    }
    int m=l+r>>1;
    build(l,m,x<<1);build(m+1,r,x<<1|1);
    a[x]=a[x<<1]+a[x<<1|1];
}
Node query(int l,int r,int L,int R,int x) {
    if(L<=l&&r<=R) return a[x];
    int m=l+r>>1;
    if(m<L) return query(m+1,r,L,R,x<<1|1);
    if(m>=R) return query(l,m,L,R,x<<1);
    return query(l,m,L,R,x<<1)+query(m+1,r,L,R,x<<1|1);
}
int main() {
    int n,q;
    while(~scanf("%d%d%s",&n,&q,s+1)) {
        // strrev(s+1);
        for(int i=1;i<=n/2;i++){
            swap(s[i],s[n-i+1]);
        }
        // cout<<s+1<<endl;
        build(1,n,1);
        while(q--) {
            int l,r;int tl,tr;
            scanf("%d%d",&tl,&tr);
            r = n-tl+1,l = n - tr + 1;

            // cout<<l<<" "<<r<<endl;

            int ans=query(1,n,l,r,1).mat[0][4];
            if(ans==N) ans=-1;
            printf("%d\n",ans);
        }
    }
    return 0;
}