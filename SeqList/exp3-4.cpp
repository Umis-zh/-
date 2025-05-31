#include <iostream>
#include "SeqList.h"
using namespace std;

int main(){

    int n,k,m;
    cout<<"请输入初始人数，出圈的报数，留下的人数"<<endl;
    cin>>n>>k>>m;
    SeqList A;
    for(int i=1;i<=n;i++){
        A.listInsert(i,i);
    }
    int x=1,y=1,temp;
    while (A.length()!=m){
        if(y==k) {
            A.listDelete(x);//自动指向下一个元素
            y=1;
        }
        else{
            x=(x%A.length())+1;//从1开始的逻辑“循环”
            y++;
        }

    }
    A.show();

}