/*
2020年5月12日21:13:15 开始

决定用上次tx面试题学到的while版的冒泡写法

2020年5月12日21:28:54 AC...

深信服这样搞输入输出，导致不好本地IDE测试...

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const ll mod=1000000007;
const int inf = 0x3f3f3f3f;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}


struct node {
    int val;
    struct node *next;
};

static void list_sort(struct node *head);

struct node *list_create(int arr[], int size)
{
    struct node *head = NULL;
    int i;
    for (i = size - 1; i >= 0; --i) {
        struct node *p = (struct node *)malloc(sizeof(struct node));

        p->val = arr[i];
        p->next = head;
        head = p;
    }
    return head;
}
static void list_print(struct node *head)
{
    for (; head; head = head->next) {
        printf("%d", head->val);
        if (head->next)
            printf(" ");
    }
    printf("\n");
}
static void list_free(struct node *head)
{
    struct node *next;
    while (head) {
        next = head->next;
        free(head);
        head = next;
    }
}
static int input(int **arr, int *size)
{
    int i;
    int ret;

    ret = fscanf(stdin, "%d\n", size);
    if (ret != 1)
        return -1;
    *arr = (int *)malloc(sizeof(int) * (*size));
    for (i = 0; i < *size; ++i) {
        fscanf(stdin, "%d ", &(*arr)[i]);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    struct node *head;
    int *arr = NULL;
    int size = 0;

    if (input(&arr, &size) < 0) {
        fprintf(stderr, "input error\n");
        return 0;
    }
    head = list_create(arr, size);
    list_sort(head);
    list_print(head);
    list_free(head);
    free(arr);
    return 0;
}

static void list_sort(struct node *head){
    //TODO:
    bool changed = true;
    while(changed){
        struct node *next;
        struct node *tmpHead = head;
        changed = false;
        while(tmpHead){
            next = tmpHead->next;
            if(next == nullptr) break;
            else{
                if(tmpHead->val > next->val){
                    swap(tmpHead->val,next->val);
                    changed = true;
                }
            }
            tmpHead = next;
        }
    }
}