#ifndef SEQLIST_H
#define SEQLIST_H

#define MaxLen 100

class SeqList {
public:
    SeqList();
    int length();
    bool getElement(int i, int& x);
    int locate(int x);
    int listInsert(int i, int x);
    int listDelete(int i);
    int buildTestSeqList(int data[], int size);
    void show();

public:
    int data[MaxLen];
    int listLen;
};

#endif