#include<iostream>
typedef int elementType;

typedef struct slNode{
    elementType data;
    slNode *next;
}node,*linkedList;

class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        LinkedList(LinkedList &A);
        int length();
        bool getElement(int i,elementType &x);
        bool locate(elementType x,linkedList &p);
        bool listInsert(int i,elementType x);
        bool listDelete(int i);

        void quickCreate(int x[],int m);
        void createListR();
        void createListH();
        void print();
    public:
    linkedList head;
};

LinkedList::LinkedList(){
    head = new node;
    head->next = nullptr;
};

int LinkedList::length(){
    node *p = head;
    int len = 0;
    while(p->next != nullptr) {
        p = p->next;
        len++;
    };
    return len;
};

bool LinkedList::getElement(int i,elementType &x){
    if(i<1) return 0;
    node *p = head->next;
    int cnt = 1;
    while(i != cnt && p != nullptr){
        cnt++;
        p=p->next;
    }
    if(p == nullptr) return 0;
    else {
        x = p->data;
        return 1;
    }

};

bool LinkedList::locate(elementType x,linkedList &p){
    p = head->next;
    while(p != nullptr){
        if(x == p->data) return 1;
        p = p->next;
    }
    return 0;
};

bool LinkedList::listInsert(int i,elementType x){
    node *p = head;
    node *s;
    int j = 0;

    if(i<1) return 0;
    while(j != i-1&&p != nullptr){
        p=p->next;
        j++;
    }
    if(p == nullptr) return 0;//插入位置超越表长
    else{
        s = new node;
        s->data = x;
        s->next = p->next;
        p->next = s;
        return 1;
    }
};

bool LinkedList::listDelete(int i){
    if(i < 1) return 0;

    linkedList p = head;
    linkedList q;
    int j = 0;
    
    while(j != i-1&&p != nullptr ){
        p = p->next;
        j++;
    }

    if(p == nullptr||p->next == nullptr) return 0;
    q = p->next;
    p->next = q->next;
    delete q;
    return 1;
};

void LinkedList::createListR(){
    elementType x;
    linkedList r,u;
    r = head;
    std::cout<<"请输入节点元素值（输入-9999结束）"<<std::endl;
    std::cin>>x;
    while(x!=-9999){
        u=new node;
        u->data = x;
        u->next = nullptr;
        r->next = u;
        r = u;
        std::cin>>x;
    };
}

void LinkedList::createListH(){
    elementType x;
    linkedList p,q;
    p = head;
    std::cout<<"请输入节点元素值（输入-9999结束）"<<std::endl;
    std::cin>>x;
    while(x!=-9999){
        q = new node;
        q->data = x;
        q->next = p->next;
        p->next = q;
        std::cin>>x;
    };
}

void LinkedList::print(){
    linkedList p = head->next;
    while(p != nullptr){
        std::cout<<p->data<<" ";
        p=p->next;
    }
};

LinkedList::~LinkedList() {
    // 先检查头指针是否为空
    if (head != nullptr) {
        linkedList p, q;
        p = head;
        while (p) {
            q = p->next;
            delete p;
            p = q;
        }
    }
}

void LinkedList::quickCreate(int x[],int m){
    for(int i = 0;i < m; i++){
        listInsert(i+1,x[i]);
    }
};

LinkedList::LinkedList(LinkedList &A){
    head=new node;
    linkedList p=A.head->next;
    linkedList q=head;
    while(p){
        q->next=new node;
        q=q->next;
        q->data=p->data;
        p=p->next;

    }
    q->next=nullptr;
}
