#include"LinkedList.h"
#include<iostream>
//删除重复元素
void deleteRepeatingElements(LinkedList &L){
    linkedList p,q,temp;
    if(L.head->next==nullptr) return; 
    p=L.head->next;
    q=p->next;
    while (q)
    {
        if(p->data==q->data){          
            temp=q;
            q=q->next;
            p->next=q;
            delete temp;
        }
        else{
            p=p->next;
            q=q->next;
        }
        
    };
}

//构建测试数据
int main(){
    LinkedList L1,L2,L3;
    int x1[] = {1,2,3,4,5,6,7,8,9};
    int x2[] = {1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,9};
    int x3[] = {1,2,3,4,5,5,6,7,8,8,9,9,9,9,9};
    L1.quickCreate(x1,9);
    L2.quickCreate(x2,17);
    L3.quickCreate(x3,15);
    //L.createListR();
    L1.print();//展示初始链表
    std::cout<<std::endl;
    L2.print();
    std::cout<<std::endl;
    L3.print();
    std::cout<<std::endl;
    deleteRepeatingElements(L1);
    deleteRepeatingElements(L2);
    deleteRepeatingElements(L3);
    L1.print();//展示修改后链表
    std::cout<<std::endl;
    L2.print();
    std::cout<<std::endl;
    L3.print();
    std::cout<<std::endl;


}