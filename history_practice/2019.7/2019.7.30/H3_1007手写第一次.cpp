/*
由于不太熟悉，然后就板子部分一个函数一个函数的借鉴写，非板子的main()自己写

2019年7月30日17:13:01 感觉std写得shit一样，但我暂时不知道怎么改掉它..难受..

2019年7月30日17:22:12 为什么要AC啊，感觉写得很不科学啊，这个线段树哪里和a[i]的值结合起来了啊
自己照着写了一遍还是异常懵逼，昨天看了2小时，然后今天不算补基础的线段树，今天在这个上面也有
3小时了吧...难受,我咋这么菜啊

晚上又苦肝一小时...2019年7月30日20:31:46 还有不懂那个pushup为啥是max

2019年7月30日20:34:57 突然灵光一闪！
因为你一开始是一棵空树，然后你一个个插入，如果使用的是max，就相当于(to[i],n+1)这个区间以及每个子区间
都是你的插入值的和.         因为都是直接到了叶子节点去加和

如果使用加法，那么就出错了，就有很多重复计算，所以说[1->n]区间就是最大的前缀和

所以询问的时候就可以直接加和
 */

#include<bits/stdc++.h>
using namespace std;
#define mod 1e9+7
#define ll long long
const int M = 2e5+7;
ll int a[M],number[M<<2],bz[M<<2];
int number2[M<<2],bz2[M<<2],to[M];
struct node{
    int id;
    ll b;
} no[M];

bool cmp(node a,node b){
    return a.b==b.b ? a.id<b.id : a.b<b.b;
}

/* 自己重写std感觉上推数值好像还是不对，如果不理解的话，下次就算有板子也不能秒掉！
所以还是要先理解一下 ，多多重现算法*/
/* 先写着，等下写完全部看看有没有新的认识 */
/* 2019年7月30日16:59:35 还是不懂，维护区间之和难道不是要左右相加吗？

2019年7月30日20:34:57 突然灵光一闪！
因为你一开始是一棵空树，然后你一个个插入，如果使用的是max，就相当于(to[i],n+1)这个区间以及每个子区间
都是你的插入值的和.         因为都是直接到了叶子节点去加和

如果使用加法，那么就出错了，就有很多重复计算，所以说[1->n]区间就是最大的前缀和

所以询问的时候就可以直接加和*/
void PushUp(int rt){
    number[rt] = max(number[rt<<1],number[rt<<1|1]);
}

/* 其实这里是多组测试的初始化0值 */
/* 但是number2不PushUp清零吗？这里好像有问题，但为什么std能AC
惊呆的发现竟然放在了pushdown下推标记的时候清零了...感觉线段树的写法真多*/
void build(int l,int r,int rt){
    bz[rt]=bz2[rt]=number[rt]=0;
    if(l==r){number2[rt]=0;return;}
    int mid = (l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    PushUp(rt);
}

void pushdown(int l,int r,int rt){
    if(bz[rt]){
        bz[rt<<1] += bz[rt];
        bz[rt<<1|1] += bz[rt];
        number[rt<<1] += bz[rt];
        number[rt<<1|1] += bz[rt];
        bz[rt] = 0;
    }
    if(bz2[rt]){
        bz2[rt<<1] += bz2[rt];
        bz2[rt<<1|1] += bz2[rt];
        number2[rt<<1] += bz2[rt];
        number2[rt<<1|1] += bz2[rt];
        bz2[rt] = 0;
    }
}

void change(ll o,int L,int R,int l,int r,int rt){
    if(L>R) return;
    if(l==r){
        number[rt]+=o;
        /* 之前初始化成了0，所以这里可以这样...这个标程写得真随意... */
        number2[rt]+=1;
        return ;
    }
    /* 此节点(区段l,r)全被包含在内 */
    if(L<=l && r<=R){
        /* 先自己赋值，下推标记就直接给儿子赋值 */
        number[rt]+=o;
        bz[rt]+=o;
        bz2[rt] += 1;
        return ;
    }
    int mid = (l+r)>>1;
    /* pushdown和PushUp都只管修改相邻层 */
    pushdown(l,r,rt);
    /* 区段l,r包含L,R,或者有交叠,则访问子节点(子区段) */
    if(L<=mid) change(o,L,R,l,mid,rt<<1);
    if(R>mid) change(o,L,R,mid+1,r,rt<<1|1);
    PushUp(rt);
}

ll query(ll k,int l,int r,int rt){
    if(l==r) return number2[rt];
    int mid = (l+r)>>1;
    pushdown(l,r,rt);
    int ans;
    if(k < number[rt<<1]) ans = query(k,l,mid,rt<<1);
    else ans = query(k,mid+1,r,rt<<1|1);
    PushUp(rt);
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        build(1,n+1,1);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            no[i].b = a[i];
            no[i].id = i;
        }
        sort(no+1,no+n+1,cmp);
        /* 把与n+1有关的节点都打上number=1e9,number2=1的标记...
        只给n+1对应的叶子节点处打上了标记！其他地方没有进去过！
        就相当于在那里插入了一点*/
        change(1e9,n+1,n+1,1,n+1,1);
        for(int i=1;i<=n;i++) to[no[i].id] = i;
        for(int i=1;i<=n;i++){
            /*一个个插入,第一个时还没插入，是空树，所以肯定返回0*/
            ll k = query(m-a[i],1,n+1,1);
            printf("%lld ",i-k);
            /*按照队友的说法,那这里就是插入第一个*/
            /* 给排名在to[i]到n+1的地方都所有区段打上区间数值和number
            和此区间个数和number2 */
            change(a[i],to[i],n+1,1,n+1,1);
        }
        puts("");
    }
    return 0;
}