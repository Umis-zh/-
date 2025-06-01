#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

void dfs(int i,Stack<char> &S,Stack<char> &Q,string &x);

int main(){
    string x;
    cout<<"请输入数字串:"<<endl;
    cin>>x;

    Stack<char> S(x.length());
    Stack<char> Q(x.length());
    dfs(0,S,Q,x);
   
}

void dfs(int i,Stack<char> &S,Stack<char> &Q,string &x){
    char d;
    if(Q.full()){        
        Q.print();
        cout<<endl;
        return;

    }    
    if(!S.empty()){
        S.pop(d);
        Q.push(d);
        dfs(i,S,Q,x);
        Q.pop(d);
        S.push(d);
    }
    if(i<x.length()){
        S.push(x[i]);
        dfs(i+1,S,Q,x);
        S.pop();
    }
    
    return;
}