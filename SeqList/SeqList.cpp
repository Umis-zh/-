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
};

int SeqList::listDelete(int i){
    if(listLen == 0) return 0;
    if(i < 1||i > this->listLen) return 1;
    else{
        for(int j = i;j < listLen;j++) data[j-1] = data[j];
    }
    listLen--;
    return 2;
};

int SeqList::buildTestSeqList(int data[], int size) {
    if(size > MaxLen) return 0;
    for (int i = 0; i < size; ++i) listInsert(i + 1, data[i]);
    return 1;
};

void SeqList::show(){
    for(int i = 0;i < this->length();i++){
        std::cout<<this->data[i]<<" ";
    }
    std::cout<<std::endl;
};
