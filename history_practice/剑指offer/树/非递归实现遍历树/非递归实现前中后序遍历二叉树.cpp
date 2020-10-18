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

//中序遍历---最简单的一种
void InOrderWithoutRecursion2(BTNode* root){
    //空树
    if (root == NULL) return;

    //树非空
    BTNode* p = root;
    stack<BTNode*> s;
    while (!s.empty() || p){
        // 有左or根
        if (p){
            s.push(p);
            p = p->lchild;
        }
        // 否则输出一个,看看右边
        else{
            p = s.top();
            s.pop();
            cout << setw(4) << p->data;
            p = p->rchild;
        }
    }
}

//前序遍历
void PreOrderWithoutRecursion2(BTNode* root){
    if (root == NULL)
        return;
    BTNode* p = root;
    stack<BTNode*> s;
    while (!s.empty() || p){
        if (p){
            cout << setw(4) << p->data;
            s.push(p);
            p = p->lchild;
        }
        else{
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void PreOrderWithoutRecursion3(BTNode* root){
    if (root == NULL)
        return;
    stack<BTNode*> s;
    BTNode* p = root;
    s.push(root);
    //循环结束条件与前两种不一样
    while (!s.empty()){
        //这句表明p在循环中总是非空的
        cout << setw(4) << p->data;
        /*
        栈的特点：先进后出
        先被访问的根节点的右子树后被访问
        */
        if (p->rchild) s.push(p->rchild);
        if (p->lchild) p = p->lchild;
        else{//左子树访问完了，访问右子树
            p = s.top();
            s.pop();
        }
    }
    cout << endl;
}

/*
后序遍历递归定义：先左子树，后右子树，再根节点。
后序遍历的难点在于：需要判断上次访问的节点是位于左子树，还是右子树。
若是位于左子树，则需跳过根节点，先进入右子树，再回头访问根节点；
若是位于右子树，则直接访问根节点。
*/

//后序遍历
void PostOrderWithoutRecursion(BTNode* root){
    if (root == NULL) return;

    stack<BTNode*> s;
    //pCur:当前访问节点，pLastVisit:上次访问节点
    BTNode* pCur, *pLastVisit;

    pCur = root;
    pLastVisit = NULL;
    //先把pCur移动到左子树最下边
    while (pCur){
        s.push(pCur);
        pCur = pCur->lchild;
    }
    while (!s.empty()){
        //走到这里，pCur都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子)
        pCur = s.top();
        s.pop();
        //一个根节点被访问的前提是：无右子树或右子树已被访问过
        if (pCur->rchild == NULL || pCur->rchild == pLastVisit){
            cout << setw(4) << pCur->data;
            //修改最近被访问的节点
            pLastVisit = pCur;
        }
        /*这里的else语句可换成带条件的else if:
        //若左子树刚被访问过或者左子树不存在，则需先进入右子树(根节点需再次入栈)
        else if (pCur->lchild == pLastVisit || pCur->lchild == nullptr)
        因为：上面的条件没通过就一定是下面的条件满足。仔细想想！
        */
        else{
            //根节点再次入栈
            s.push(pCur);
            //进入右子树，且可肯定右子树一定不为空
            pCur = pCur->rchild;
            while (pCur){
                s.push(pCur);
                pCur = pCur->lchild;
            }
        }
    }
    cout << endl;
}

int main(){


    return 0;
}