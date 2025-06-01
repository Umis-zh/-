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

Tree::Tree(csNode *T)
{
    root=T;
}

Tree::~Tree()
{
    destory(root);
}

void Tree::preOrder(csNode *T){
    if(T==NULL) return;
    cout<<T->data<<" ";
    preOrder(T->fchild);
    preOrder(T->nsibling);
}

void Tree::postOrder(csNode *T){
    if(T==NULL) return;
    postOrder(T->fchild);
    cout<<T->data<<" ";
    postOrder(T->nsibling);  
}

void Tree::destory(csNode *&T){
    if (T)
    {
        destory(T->fchild);
        destory(T->nsibling);
        delete T;
    }
    T=NULL;
    
}

bool Tree::createTree(char fileName[],csNode *&T){
    FILE* pfile;
    char *token;
    vector<PTNode> tree;
    char str[1000];
    char temp[5];

    pfile=fopen(fileName,"r");
    if(!pfile){
        cout<<"错误：文件"<<fileName<<"打开失败"<<endl;
		return false;
    }
    while(fgets(str,1000,pfile)!=NULL){
        strLTrim(str);
        if(str[0]=='\n') continue;
        strncpy(temp,str,2);
        if(strstr(temp,"//")!=NULL) continue;
        break;
    }
    

    strLTrim(str);
    if(strstr(str,"Tree or Forest")==NULL)
    {   cout<<"错误：文件内容不合法"<<endl;
        fclose(pfile);
        return false;
    }


    while(fgets(str,1000,pfile)!=NULL){
        strLTrim(str);
        if(str[0]=='\n') continue;
        strncpy(temp,str,2);
        if(strstr(temp,"//")!=NULL) continue;
        break;
    }
    strLTrim(str);
    token=strtok(str," ");
    while (token!=NULL)
    {
        PTNode node;
        node.data=*token;
        node.parent=-1;
        tree.push_back(node);
        token=strtok(NULL," ");
    }
    int nNum=tree.size();
    
    while(fgets(str,1000,pfile)!=NULL){
        strLTrim(str);
        if(str[0]=='\n') continue;
        strncpy(temp,str,2);
        if(strstr(temp,"//")!=NULL) continue;
        elementype NF,NS;

        token=strtok(str," ");
        if(token==NULL){
            cout<<"错误：读取节点失败"<<endl;
            fclose(pfile);
            return false;
        }
        else NF=*token;

        token=strtok(NULL," ");
        if(token==NULL){
            cout<<"错误：读取节点失败"<<endl;
            fclose(pfile);
            return false;
        }
        else NS=*token;

        int np,nc;
        for(np=0;np<nNum;np++)
            if(tree[np].data==NF)
                break;
        for(nc=0;nc<nNum;nc++)
            if(tree[nc].data==NS)
                break;
        
        tree[nc].parent=np;
    }
        int v=0;
        fileCreate(T,tree,v);
        fclose(pfile);
        return true;
}

void Tree::fileCreate(csNode *&T,vector<PTNode> &tree,int v){
    T=new csNode;
    T->data=tree[v].data;
    T->fchild=NULL;
    T->nsibling=NULL;
    
    int w;
    w=firstchild(tree,v);
    if(w!=-1) fileCreate(T->fchild,tree,w);
    w=next(tree,v);
    if(w!=-1) fileCreate(T->nsibling,tree,w);
}

void Tree::strLTrim(char *str){
    int i,j;
    int n=strlen(str)+1;
    for(i=0;i<n;i++)
        if(str[i]!=' ') break;
    for(j=0;i<n;j++){
        str[j]=str[i];
        i++;
    }
}

int Tree::firstchild(vector<PTNode>&T,int v){
    if(v==-1) return -1;
    for(int i=0;i<T.size();i++)
        if(T[i].parent==v) 
            return i;   
    return -1;  
}

int Tree::next(vector<PTNode>&T,int w){
    for(int i=w+1;i<T.size();i++)
        if(T[i].parent==T[w].parent)
             return i;
    return -1;
}


