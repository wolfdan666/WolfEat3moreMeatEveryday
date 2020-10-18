/*
1.struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in）
    当pre或in的size为0时，返回NULL
    当不为0时，调用构造二叉树的函数PreInOrder
2.PreInOrder(vector<int> pre, vector<int> in, int i, int j, int k, int h , struct TreeNode **p)//先序序列中从i到j，中序序列中从k到h，建立一棵二叉树存放在p中,该函数递归完成：
   （1）边界条件：构建到叶子节点，即当前节点在无左右子节点
   （2）初始化条件：先序序列的第一个节点为本次递归根节点
   （3）循环（递归）：在中序序列中找到该根节点，中序序列中该根点之前的的节点为其左子树的点，让他们作为中序序列进行下一次递归，并且让先序序列中第一个节点之后紧跟着的几个（与进入下一次递归的中序序列节点个数一样）节点序列一起进入下一次递归；中序序列中该根节点之后的节点作为其右子树节点，让他们作为中序序列进行下一次递归，并且让先树序列中剩余的节点序列也一起进入下一次递归。

    //通过先树遍历和中树遍历获取后续遍历结果 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        struct TreeNode *head;
        if (pre.size() <= 0)
            head = NULL;

        else
            PreInOrder(pre, in , 0, pre.size() - 1, 0, in.size() - 1, &head);
        return head;
    }

    void PreInOrder(vector<int> pre, vector<int> in, int i, int j, int k, int h , struct TreeNode **p){
      //先序序列中从i到j，中序序列中从k到h，建立一棵二叉树存放在p中

        int m;
        (*p) = (TreeNode*)malloc(sizeof(TreeNode));
        (*p)->val = pre.at(i);

        m = k;

        //在中序序列中找到根节点
        while(in.at(m) != pre.at(i))
            m++;

        //递归调用建立左子树
        if(m == k) (*p)->left = NULL;  //左子树为空
        else PreInOrder(pre, in, i + 1, m - k + i, k, m - 1 , &((*p)->left));

        //递归调用建立又子树
        if(m == h) (*p)->right = NULL;
        else PreInOrder(pre, in, m - k + i + 1, j, m + 1, h , &((*p)->right));
    }
};

void PostOrder(TreeNode *p)
{
    if(p != NULL)
    {
        PostOrder(((p)->left));
        PostOrder(((p)->right));
        printf("%d\t",(p)->val);
    }
}

int
main()
{
    int a1[] ={1,2,4,7,3,5,6,8};
    int a2[] ={4,7,2,1,5,3,8,6};

    vector<int> pre(a1, a1 + 8);
    vector<int> in(a2, a2 + 8);

    Solution s;
    struct TreeNode *head = s.reConstructBinaryTree(pre, in);
    PostOrder(head);
    system("pause");
}