// 帮学弟  debug hhh


#include<iostream>
using namespace std;

struct bnode{
    bnode *lchild;
    bnode  *rchild;
    int data;
};

class atree{
public:
    atree(){ root =NULL;}
    // ~atree(){}
    void preorder(){preorder(root);}
    void inorder(){inorder(root);}
    void postorder(){postorder(root);}
    void creat(){creat(root);}
    // void visit(bnode *T){cout<<T->data;}

private:
    bnode *root;
    void visit(bnode *T){cout<<T->data<<endl;}
    void preorder(bnode* T){
        if(T!=NULL){
            visit(T);
            preorder(T->lchild);
            preorder(T->rchild);
        }
    }
    void inorder(bnode* T){
        if(T!=NULL)
        {
        inorder(T->lchild);
        visit(T);
        inorder(T->rchild);}}
   void postorder(bnode* T){
        if(T!=NULL)
        {
        postorder(T->lchild);
        postorder(T->rchild);
        visit(T);}}
   void creat(bnode *&T){   // bnode *是类型，要真正引用要&
        int b;
        cin>>b;
        if(b!=-1){
            T=new bnode;
            T->data=b;
            // T->lchild=NULL;
            // T->rchild=NULL;
            creat(T->lchild);
            creat(T->rchild);
            return ;
        }
        else{
            T = NULL;
            return ;
        }
    }

};

int main(){
    atree a;
    a.creat();
    a.preorder();


    return 0;
}