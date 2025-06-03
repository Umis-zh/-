#include "Tree.h"

void forestDegree(csNode *T,int&w){
    int wx=0;
    csNode *temp=NULL;
    if(T!=NULL){
        wx++;
        temp=T->nsibling;
    
    while(temp){
        wx++;
        temp=temp->nsibling;
    }
    if(wx>w) w=wx;
    forestDegree(T->fchild,w);
    forestDegree(T->nsibling,w);
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

    int w1=0,w2=0;
    forestDegree(tree1.root,w1);
    forestDegree(tree2.root,w2);
    // 计算并输出森林的度
    cout << "森林tree11的度为: " << w1 << endl;
    cout << "森林F20的度为: " << w2 << endl;
    
    return 0;
}