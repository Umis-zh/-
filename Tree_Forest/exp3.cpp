#include "BiTree.h"

btNode* findLCAInfo(btNode*T,elementype x,elementype y){

    if(T==NULL) return NULL;
    if(T->data==x||T->data==y) return T;
    btNode *left=findLCAInfo(T->lchild,x,y);
    btNode *right=findLCAInfo(T->rchild,x,y);

    if (left&&right) return T;
    
    return (left!=NULL) ? left:right;

}

int main() {
    btTree tree1 = NULL, tree2 = NULL;
    
    // 加载第一组数据
    BiTree::createBitree(R"(D:\Code\C_CODE\Tree_Forest\BTdata\bt261.btr)", tree1);
    BiTree bt1(tree1);
    
    // 加载第二组数据
    BiTree::createBitree(R"(D:\Code\C_CODE\Tree_Forest\BTdata\bt21.btr)", tree2);
    BiTree bt2(tree2);
    
    // 测试第一组数据中的LCA
    cout << "测试 bt261.btr:" << endl;
    btNode*T1= findLCAInfo(bt1.root,'c','p'); // 替换为实际节点值
    cout<<"公共节点为"<<T1->data<<endl;
    
    // 测试第二组数据中的LCA
    cout << "测试 bt21.btr:" << endl;
    btNode*T2= findLCAInfo(bt2.root,'n','s'); // 替换为实际节点值
    cout<<"公共节点为"<<T2->data<<endl;
    
    return 0;
}