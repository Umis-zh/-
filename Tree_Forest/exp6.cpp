#include "Tree.h"


void forestToExp(csNode *T){
    if(T){
        cout<<T->data;
        if(T->fchild){
            cout<<"(";
            forestToExp(T->fchild);
        }
        if(T->nsibling){
            cout<<",";
            forestToExp(T->nsibling);
        }
        else cout<<")";

    }



}

int main() {
    // 读取第一组数据
    csNode* root1 = NULL;
    Tree::createTree(R"(D:\Code\C_CODE\Tree_Forest\tData\tree11.tre)", root1);
    Tree tree1(root1);
    
    // 读取第二组数据
    csNode* root2 = NULL;
    Tree::createTree(R"(D:\Code\C_CODE\Tree_Forest\tData\F20.tre)", root2);
    Tree tree2(root2);
    
    // 输出广义表表示
    forestToExp(tree1.root);
    cout<<endl;
    forestToExp(tree2.root);
    
    return 0;
}