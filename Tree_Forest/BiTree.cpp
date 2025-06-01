#include <iostream>
#include <cstring>
#include <vector>
/*#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>*/

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

BiTree::BiTree(btNode *T)
{
    root=T;
}

BiTree::~BiTree()
{
    destory(root);
}

void BiTree::preOrder(btNode *T){
    if(T==NULL) return;
    cout<<T->data<<" ";
    preOrder(T->lchild);
    preOrder(T->rchild);
}

void BiTree::inOrder(btNode *T){
    if(T==NULL) return;
    inOrder(T->lchild);
    cout<<T->data<<" ";
    inOrder(T->rchild);
    
}

void BiTree::postOrder(btNode *T){
    if(T==NULL) return;
    postOrder(T->lchild);
    postOrder(T->rchild);
    cout<<T->data<<" ";  
}

void BiTree::destory(btNode *&T){
    if (T)
    {
        destory(T->lchild);
        destory(T->rchild);
        delete T;
    }
    T=NULL;
    
}

bool BiTree::createBitree(char fileName[],btNode *&T){
    FILE* pfile;
    char *token;
    vector<vector<char>> strLine;
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
    if(strstr(str,"BinaryTree")==NULL)
    {   cout<<"错误：文件内容不合法"<<endl;
        fclose(pfile);
        return false;
    }

    while(fgets(str,1000,pfile)!=NULL){
        strLTrim(str);
        if(str[0]=='\n') continue;
        strncpy(temp,str,2);
        if(strstr(temp,"//")!=NULL) continue;
        vector<char> strtemp;

        token=strtok(str," ");
        if(token==NULL){
            cout<<"错误：读取节点失败"<<endl;
            fclose(pfile);
            return false;
        }
        else strtemp.push_back(*token);

        token=strtok(NULL," ");
        if(token==NULL){
            cout<<"错误：读取节点失败"<<endl;
            fclose(pfile);
            return false;
        }
        else strtemp.push_back(*token);

        token=strtok(NULL," ");
        if(token==NULL){
            cout<<"错误：读取节点失败"<<endl;
            fclose(pfile);
            return false;
        }
        else strtemp.push_back(*token);

        strLine.push_back(strtemp);
    }
    int nRow=0;
    fileCreate(T,strLine,strLine.size(),nRow);
    fclose(pfile);
    return true;
}
void BiTree::fileCreate(btNode *&T,vector<vector<char>> &strLine,int nLen,int &nRow){
    if(nRow>=nLen) return;

    T=new btNode;
    T->data=strLine[nRow][0];
    T->lchild=NULL;
    T->rchild=NULL;
    int Row=nRow;
    if(strLine[Row][1]=='1') {
        //nRow++;
        fileCreate(T->lchild,strLine,nLen,++nRow);
    }
    if(strLine[Row][2]=='1'){
        //nRow++;
        fileCreate(T->rchild,strLine,nLen,++nRow);
    } 

}

void BiTree::strLTrim(char *str){
    int i,j;
    int n=strlen(str)+1;
    for(i=0;i<n;i++)
        if(str[i]!=' ') break;
    for(j=0;i<n;j++){
        str[j]=str[i];
        i++;
    }
}


//C++版本：
/*void BiTree::strLTrim(string &s){
    s.erase(s.begin(),find_if(s.begin(),s.end(),[](unsigned char ch){
        return !isspace(ch);
    }))
}*/