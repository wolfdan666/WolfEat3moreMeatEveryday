/*
这个题目很简单，就是我们之前数据结构课的作业题
2020年2月9日14:07:53 决定速写

    // new 表达式尝试申请存储空间，并在已申请的存储空间上，
    // 尝试构造并初始化为一个无名对象，或无名对象的数组。
    // new表达式返回一个指向所构造的对象或者对象数组的纯右值指针。
所以下面两种写法等价...自己回学校要复习一遍C++ Primer
    // ListNode l1 = ListNode(1);
    // ListNode *l1p = &l1;
    ListNode * l1p = new ListNode(1);
2020年2月9日14:52:24 AC, 45mins...菜爆了！
执行用时: 4 ms,在所有 C++提交中击败了98.87% 的用户
内存消耗: 9.1 MB , 在所有C++提交中击败了12.19% 的用户
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 为了良好的处理，所以最后面返回head->next
        // ListNode * head;
        ListNode * head = new ListNode(1);
        ListNode * ans = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                // LeetCode:runtime error: member access within null pointer of type 'struct ListNode'
                // 本地是可以运行的...
                // 所以就把head 初始化一下, 如上面45行代码...
                ans->next = l1;
                l1 = l1->next;
            } else {
                ans->next = l2;
                l2 = l2->next;
            }
            ans = ans->next;
        }
        if(l1 == NULL) ans->next = l2;
        else ans->next = l1;

        return head->next;
    }
};

int main(){
    // new 表达式尝试申请存储空间，并在已申请的存储空间上，
    // 尝试构造并初始化为一个无名对象，或无名对象的数组。
    // new表达式返回一个指向所构造的对象或者对象数组的纯右值指针。
    // ListNode l1 = ListNode(1);
    // ListNode *l1p = &l1;
    ListNode * l1p = new ListNode(1);
    ListNode *l1pHead = l1p;
    l1p->next = new ListNode(2);
    l1p = l1p->next;
    l1p->next = new ListNode(4);
    l1p = l1p->next;

    ListNode l2 = ListNode(1);
    ListNode *l2p = &l2;
    ListNode *l2pHead = l2p;
    l2p->next = new ListNode(3);
    l2p = l2p->next;
    l2p->next = new ListNode(4);
    l2p = l2p->next;

    Solution test;
    ListNode * testLink = test.mergeTwoLists(l1pHead,l2pHead);

    while(testLink != NULL){
        cout<<testLink->val<<" ";
        testLink = testLink->next;
    }
    cout<<endl;

    return 0;
}

// 1 1 2 3 4 4