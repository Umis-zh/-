#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <cstring>
#include <vector>


using namespace std;
typedef char elementype;

struct PTNode
{
    elementype data;
    int parent;
};


typedef struct biNode{
    elementype data;
    biNode *fchild,*nsibling;
} csNode,*csTree;

class Tree
{
public:
    static bool createTree(char fileName[],csNode *&T);
    static int firstchild(vector<PTNode>&T,int v);
    static int next(vector<PTNode>&T,int w);
    static void fileCreate(csNode *&T,vector<PTNode> &tree,int v);
    static void strLTrim(char *str);
public:
    csNode *root;
public:
    Tree(csNode *T);
    ~Tree();
    void preOrder(csNode *T);
    void postOrder(csNode *T);
    void empty(csNode *T);
    void destory(csNode *&T);
};


#endif