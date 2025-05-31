#ifndef LINKEDLIST_H
#define LINKEDLIST_H
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

#endif