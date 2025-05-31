#define MaxLen 100
#include<iostream>


class SeqList
{
public:
    SeqList();
    int length();
    bool getElement(int i,int &x);
    int locate(int x);
    int listInsert(int i,int x);
    int listDelete(int i);
    int buildTestSeqList(int data[], int size);
    void show();

public:
    int data[MaxLen];
    int listLen;
};

SeqList::SeqList(){
    listLen = 0;
};

int SeqList::length(){                                                                                                                                                               
    return listLen;
};

bool SeqList::getElement(int i,int &x){
    if(i < 1 || i >this->listLen) return 0;
    else x = this->data[i-1];
    return 1;
};

int SeqList::locate(int x){
    for(int i = 0;i < this->listLen;i++)
        if(this->data[i] == x) return i + 1;
    return -1;
};

int SeqList::listInsert(int i,int x){
    int j;
    if(listLen == MaxLen) return 0;
    if(i < 1||i >this->listLen+1) return 1;
    else{ 
        for(j = listLen-1;j >= i-1;j--){
            data[j+1] = data[j];
        };
        data[i-1] = x;
        listLen++;
        return 2;
    };
}

int SeqList::listDelete(int i){
    if(listLen == 0) return 0;
    if(i < 1||i > this->listLen) return 1;
    else{
        for(int j = i;j < listLen;j++) data[j-1] = data[j];
    }
    listLen--;
    return 2;
}

int SeqList::buildTestSeqList(int data[], int size) {
    if(size > MaxLen) return 0;
    for (int i = 0; i < size; ++i) listInsert(i + 1, data[i]);
    return 1;
}

void SeqList::show(){
    for(int i = 0;i < this->length();i++){
        std::cout<<this->data[i]<<" ";
    }
    std::cout<<std::endl;
}

//分离算法实现
void resolveSeq(SeqList A,SeqList &P,SeqList &Q){
    for(int i = 0;i < A.length();i++){
        if(A.data[i]%2 == 0) Q.listInsert(Q.length()+1,A.data[i]);
        else P.listInsert(P.length() + 1,A.data[i]);       
    }
}


//测试数据的构建
int main(){
    SeqList A,B,P1,Q1,P2,Q2;
    
    A.listInsert(1,1);
    A.listInsert(2,2);
    A.listInsert(3,3);
    A.listInsert(4,4);
    A.listInsert(5,5);
    A.listInsert(6,6);
    A.listInsert(7,7);
    A.listInsert(8,8);
    A.listInsert(9,9);
    A.listInsert(10,10);
    A.listInsert(11,20);
    A.listInsert(12,30);
    A.listInsert(13,40);
    A.listInsert(14,50);
    A.listInsert(15,60);

    resolveSeq(A,P1,Q1);
    for(int i = 0;i < P1.length();i++){
        std::cout<<P1.data[i]<<" ";
    }
    std::cout<<std::endl;

    for(int i = 0;i < Q1.length();i++){
        std::cout<<Q1.data[i]<<" ";
    }
    std::cout<<std::endl;


    B.listInsert(1,10);
    B.listInsert(2,20);
    B.listInsert(3,30);
    B.listInsert(4,40);
    B.listInsert(5,50);
    B.listInsert(6,60);
    B.listInsert(7,70);
    B.listInsert(8,80);
    B.listInsert(9,90);
    B.listInsert(10,100);

    resolveSeq(B,P2,Q2);
    for(int i = 0;i < P2.length();i++){
        std::cout<<P2.data[i]<<" ";
    }
    std::cout<<std::endl;

    for(int i = 0;i < Q2.length();i++){
        std::cout<<Q2.data[i]<<" ";
    }
    std::cout<<std::endl;
}