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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        ListNode* cur = head;

        // 删了一些
        while(cur && cur->val == val){
            cur = cur->next;
        }
        ListNode* ans = cur;
        // 全删完了
        if(ans == NULL) return ans;

        while(cur->next){
            if(cur->next->val == val){
                cur->next = cur->next->next;
                // [1,2,2,1] 2
                continue;
            }
            cur = cur->next;
        }

        return ans;
    }
};

// 虚拟头结点+安全删除，牛逼
class Solution_AnQuan {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;

        while(cur->next){
            if(cur->next->val == val){
                // 内存泄露防止
                ListNode* del = cur->next;

                cur->next = cur->next->next;

                delete del;

                // [1,2,2,1] 2
                continue;
            }
            cur = cur->next;
        }

        ListNode* ans = dummyHead->next;
        delete dummyHead;
        return ans;
    }
};



int main(){


    return 0;
}