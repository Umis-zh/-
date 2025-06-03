#include "BiTree.h"

void transform(btNode *T,char data[],int i){
    if(T==NULL) return; 
    data[i]=T->data;
    transform(T->lchild,data,2*i);
    transform(T->rchild,data,2*i+1);
}

void print(char data[]){
    for(int i=1;i<100;i++){
         cout<<data[i]<<" ";
    }
    cout<<endl;
}

int main(){
    char data1[100];
    memset(data1,'#',99);
    char data2[100];
    memset(data2,'#',99);
    btTree x,y;
    BiTree::createBitree("D:\\Code\\C_CODE\\Tree_Forest\\BTdata\\bt8.btr",x);
    BiTree::createBitree(R"(D:\Code\C_CODE\Tree_Forest\BTdata\bt14.btr)",y);
    BiTree x1(x);
    BiTree x2(y);
    x1.preOrder(x1.root);
    cout<<endl;
    transform(x1.root,data1,1);
    print(data1);

    x2.preOrder(x2.root);
    cout<<endl;
    transform(x2.root,data2,1);
    print(data2);
    return 0;
}
