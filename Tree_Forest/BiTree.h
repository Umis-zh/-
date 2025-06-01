#ifndef BITREE_H
#define BITREE_H


#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef char elementype;

typedef struct biNode{
    elementype data;
    biNode *lchild,*rchild;
} btNode,*btTree;

class BiTree
{
public:
    static bool createBitree(char fileName[],btNode *&T);
    static void fileCreate(btNode *&T,vector<vector<char>> &strLine,int nLen,int &nRow);
    static void strLTrim(char *str);
public:
    btNode *root;
public:
    BiTree(btNode *T);
    ~BiTree();
    void preOrder(btNode *T);
    void inOrder(btNode *T);
    void postOrder(btNode *T);
    void empty(btNode *T);
    void destory(btNode *&T);
};


#endif