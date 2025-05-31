#include <iostream>
#include <Cstring>
using namespace std;
typedef char elementype;

typedef struct biNode{
    elementype data;
    biNode *lchild,*rchild;
} btNode,*btTree;

class BiTree
{
    static void createBiTree();
    static void fileCreate();
public:
    btNode *root;
public:
    BiTree(btNode *T);
    ~BiTree();
    void preOrder(btNode *T);
    void inOrder(btNode *T);
    void postOrder(btNode *T);
    void empty(btNode *T);
};

BiTree::BiTree(btNode *T)
{
    root=T;
}

BiTree::~BiTree()
{

}

void BiTree::preOrder(btNode *T){
    if(T=nullptr) return;
    cout<<T->data<<" ";
    preOrder(T->lchild);
    preOrder(T->rchild);
}

void BiTree::inOrder(btNode *T){
    if(T=nullptr) return;
    inOrder(T->lchild);
    cout<<T->data<<" ";
    inOrder(T->rchild);
    
}

void BiTree::postOrder(btNode *T){
    if(T=nullptr) return;
    postOrder(T->lchild);
    postOrder(T->rchild);
    cout<<T->data<<" ";  
}

void BiTree::createBiTree(){

}