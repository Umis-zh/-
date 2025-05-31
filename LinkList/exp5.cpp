#include"LinkedList.h"
#include<iostream>
//奇查找倒数第k个元素算法
bool findReciprocalK(LinkedList L,int k){
    linkedList p=L.head;
    linkedList q=L.head->next;
    int i=1;
    while(q!=nullptr&&i!=k){
        q=q->next;
        i++;
    }
    if(i!=k|q==nullptr) return 0;//长度不足
    else p=p->next;
    while(q->next) {
        q=q->next;
        p=p->next;   
    }
    std::cout<<p->data<<std::endl;
    return 1;
}

//构建测试数据
int main(){
    LinkedList L1;
    int x1[] = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,60};
    L1.quickCreate(x1,15);
    //L.createListR();
    L1.print();//展示初始链表
    std::cout<<std::endl;
    findReciprocalK(L1,5);
}