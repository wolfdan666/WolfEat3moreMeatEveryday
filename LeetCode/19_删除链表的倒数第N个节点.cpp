/*
2020年2月2日10:54:04 开始
看到题目就知道是很明显的双指针题目，因为之前见过类似的

2020年2月2日11:21:04
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了5.04%的用户

27mins...菜了
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;

        // a->next 指向被删除节点
        ListNode * a = head;
        ListNode * b = head;
        while(b && n--) b = b->next;
        // 保证n有效，所以不用考虑太多
        // if(n != 0) throw ;

        // 单输入[1]的特例WA我一下
        if(b == NULL){
            // 删除头节点
            if(n == 0) return head->next;
            // 删除头结点之前的等价于没有删
            if(n) return head;
        }
        // 删除头结点之后的
        while(b->next){
            a = a->next;
            b = b->next;
        }

        ListNode * p = a->next;
        a->next = p->next;
        delete p;

        return head;
    }
};

int main(){


    return 0;
}