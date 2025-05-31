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

//求交集算法的实现
void getMerge(SeqList A,SeqList B,SeqList &C){
    int p = 0,q = 0;
    while(p < A.length() && q < B.length()){
        if(A.data[p] == B.data[q]){
        C.listInsert(C.length() + 1,A.data[p]);
        p++;
        q++;    
        }
        else if(A.data[p] < B.data[q]) p++;
        else q++;        
    }
}



//测试数据的构建
int main(){
    SeqList P1,Q1,P2,Q2,P3,Q3,L1,L2,L3;
    int x1[]={1,3,6,10,15,16,17,18,19,20};
    int y1[]={1,2,3,4,5,6,7,8,9,10,18,20,30};
    int x2[]={1,3,6,10,15,16,17,18,19,20};
    int y2[]={2,4,5,7,8,9,12,22};
    int x3[]={};
    int y3[]={1,2,3,4,5,6,7,8,9,10};

    P1.buildTestSeqList(x1,10);
    Q1.buildTestSeqList(y1,13);
    P2.buildTestSeqList(x2,10);
    Q2.buildTestSeqList(y2,8);
    P3.buildTestSeqList(x3,0);
    Q3.buildTestSeqList(y3,10);

    getMerge(P1,Q1,L1);
    getMerge(P2,Q2,L2);
    getMerge(P3,Q3,L3);

    L1.show();
    L2.show();
    L3.show();
   

};