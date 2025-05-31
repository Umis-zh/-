#include"LinkedList.h"
#include<iostream>
//奇数偶数分离算法
void resloveLinkList(LinkedList L,LinkedList &A,LinkedList &B){
    linkedList p=L.head->next;
    int m=1,n=1;
    while(p!=nullptr){
        if(p->data%2==0){
            A.listInsert(m,p->data);
            m++;
        }
        else{
            B.listInsert(n,p->data);
            n++;
        }
        p=p->next;
    }

}

//构建测试数据
int main(){
    LinkedList L,A,B,L1,A1,B1;
    int x1[] = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,60};
    int x2[] = {10,20,30,40,50,60,70,80,90,100};
    L.quickCreate(x1,15);
    //L.createListR();
    L.print();//展示初始链表
    std::cout<<std::endl;
    resloveLinkList(L,A,B);
    A.print();//展示偶数链表
    std::cout<<std::endl;
    B.print();//展示奇数链表
    std::cout<<std::endl;

    L1.quickCreate(x2,10);
    //L.createListR();
    L1.print();//展示初始链表
    std::cout<<std::endl;
    resloveLinkList(L1,A1,B1);
    A1.print();//展示偶数链表
    std::cout<<std::endl;
    B1.print();//展示奇数链表
}