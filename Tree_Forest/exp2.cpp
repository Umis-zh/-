#include "BiTree.h"

void getNode(btNode* T,elementype x,btNode *&father,btNode *&target){
    if(T==NULL) return;
    if(x==T->data){
        father=NULL;
        target=T;
        return;
    } 
    if (T->lchild != NULL &&T->lchild->data==x)
    {
        father=T;
        target=T->lchild;
        return;
    }
    if (T->rchild != NULL &&T->rchild->data==x)
    {
        father=T;
        target=T->rchild;
        return;
    }
    getNode(T->lchild,x,father,target);
    getNode(T->rchild,x,father,target);
    return;
}

void nodeInformation(btNode *father,btNode *target){
        if(target==NULL){
            cout<<"节点不存在"<<endl;
            return;
        }
        cout<<"节点："<<target->data<<endl;
        if(father!=NULL)cout<<"父节点："<<father->data<<endl;
        else {
            cout<<"没有父节点"<<endl;
            cout<<"没有兄弟节点"<<endl;
            return;
        }

        if (father->lchild==target&&father->rchild!=NULL)
        {
            cout<<"有右兄弟"<<father->rchild->data<<endl;
        }
        else if(father->rchild==target&&father->lchild!=NULL)
        {
            cout<<"有左兄弟"<<father->lchild->data<<endl;
        }
        else cout<<"没有兄弟节点"<<endl;
        return;
}

int main(){
    btTree x,y;
    BiTree::createBitree(R"(D:\Code\C_CODE\Tree_Forest\BTdata\bt21.btr)",x);
    BiTree::createBitree(R"(D:\Code\C_CODE\Tree_Forest\BTdata\bt14.btr)",y);
    BiTree x1(x);
    BiTree x2(y);
    cout<<endl;
    cout<<endl;
    btNode *father1,*father2,*target1,*target2=NULL;
    getNode(x1.root,'h',father1,target1);
    getNode(x2.root,'C',father2,target2);
    nodeInformation(father1,target1);
    nodeInformation(father2,target2);
    return 0;
}
