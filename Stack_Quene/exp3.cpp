#include <iostream>
#include "Queue.h"
using namespace std;

int main(){

    int n,k,m;
    cout<<"请输入初始人数，出圈的报数，留下的人数"<<endl;
    cin>>n>>k>>m;
    Queue<int> Q(n+1);
    for(int i=1;i<=n;i++)Q.enQueue(i);
    int x=1;
    while (Q.len()!=m)
    {
        if(x==k){
            Q.outQueue();
            x=1;
        }
        else{
            int y;
            Q.outQueue(y);
            Q.enQueue(y);
            x++;
        }

    }
    Q.print();
    

}