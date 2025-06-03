#include "BiTree.h"
#include "Stack.h"

void printAllLeafPaths(btNode*T,Stack<char> &out){

    out.push(T->data);
    if(T->lchild==NULL&&T->rchild==NULL) {
        out.print();
        out.pop();     
        return;
    }
    else{
    if(T->lchild!=NULL)printAllLeafPaths(T->lchild,out);
    if(T->rchild!=NULL)printAllLeafPaths(T->rchild,out);
    }
    out.pop();

}


int main() {
    btTree tree1 = NULL, tree2 = NULL;
    
    // 加载第一组数据
    BiTree::createBitree(R"(D:\Code\C_CODE\Tree_Forest\BTdata\bt261.btr)", tree1);
    BiTree bt1(tree1);
    
    // 加载第二组数据
    BiTree::createBitree(R"(D:\Code\C_CODE\Tree_Forest\BTdata\bt21.btr)", tree2);
    BiTree bt2(tree2);
    
    Stack<char> out(30);
    // 测试第一组数据的路径
    cout << "测试 bt261.btr:" << endl;
    printAllLeafPaths(bt1.root,out);
    
    // 测试第二组数据的路径
    cout << "测试 bt21.btr:" << endl;
    printAllLeafPaths(bt2.root,out);
    
    return 0;
}