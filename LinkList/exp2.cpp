#include"LinkedList.h"
#include<iostream>
//求交集算法
void getIntersection(LinkedList L1,LinkedList L2,LinkedList &L3){
    linkedList p=L1.head->next;
    linkedList q=L2.head->next;
    int m=1;
    while(p!=nullptr&&q!=nullptr){
        if(p->data>q->data) q=q->next;
        else if(p->data<q->data) p=p->next;
        else {
            L3.listInsert(m,p->data);
            m++;
            q=q->next;
            p=p->next;
        }
    }
}

//构建测试数据
int main(){
    LinkedList L1,L2,L3,K1,K2,K3,M1,M2,M3;
    int x1[] = {1,3,6,10,15,16,17,18,19,20};
    int y1[] = {1,2,3,4,5,6,7,8,9,10,18,20,30};
    int x2[] = {1,3,6,10,15,16,17,18,19,20};
    int y2[] = {2,4,5,7,8,9,12,22};
    int x3[] = {};
    int y3[] = {1,2,3,4,5,6,7,8,9,10};

    L1.quickCreate(x1,10);
    L2.quickCreate(y1,13);
    //L.createListR();
    L1.print();//展示初始链表
    std::cout<<std::endl;
    L2.print();
    std::cout<<std::endl;
    getIntersection(L1,L2,L3);
    L3.print();//展示交集链表
    std::cout<<std::endl;

    K1.quickCreate(x2,10);
    K2.quickCreate(y2,8);
    //L.createListR();
    K1.print();
    std::cout<<std::endl;
    K2.print();
    std::cout<<std::endl;
    getIntersection(K1,K2,K3);
    K3.print();
    std::cout<<std::endl;

    M1.quickCreate(x1,10);
    M2.quickCreate(y1,13);
    //L.createListR();
    M1.print();
    std::cout<<std::endl;
    M2.print();
    std::cout<<std::endl;
    getIntersection(M1,M2,M3);
    M3.print();
    std::cout<<std::endl;

   
}