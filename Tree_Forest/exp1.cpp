#include "Tree.h"

int main(){
    csTree T;
    Tree::createTree("D:\\Code\\C_CODE\\Tree_Forest\\tData\\F14.tre",T);
    Tree bt(T);
    bt.postOrder(bt.root);
    return 0;
}