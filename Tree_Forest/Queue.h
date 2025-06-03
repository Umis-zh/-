#ifndef QUEUE_H
#define QUEUE_H
template<typename T>
class Queue
{
private:
    T *data;
    int front,rear;
    int length;
public:
    Queue(int x);
    ~Queue();
    Queue(const Queue<T> &B);
    Queue<T>& operator=(const Queue<T>&other);
    bool empty();
    bool full();
    bool getFront(T &x);
    bool enQueue(const T &x);
    bool outQueue();
    bool outQueue(T &x);
    void print();
    int len();
};

template<typename T>
Queue<T>::Queue(int x)
{
    length=x;
    data= new T[x];
    front=0;
    rear=0;
}

template<typename T>
Queue<T>::~Queue()
{
    delete []data;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>&other){
    if(this==&other) return *this;
    delete []data;
    
    front=other.front;
    rear=other.rear;
    length=other.length;
    data=new T[other.length];
    for(int i=0;i<length;i++) data[i]=other.data[i];
    return *this;
}


template<typename T>
Queue<T>::Queue(const Queue<T> &B)
{
    front=B.front;
    rear=B.rear;
    length=B.length;
    data=new T[B.length];
    for(int i=0;i<length;i++) data[i]=B.data[i];
}

template<typename T>
bool Queue<T>::empty()
{
    return (front==rear);
}

template<typename T>
bool Queue<T>::full()
{
    return (front==(rear+1)%length);
}

template<typename T>
bool Queue<T>::getFront(T &x)
{
    if(empty()) return 0;
    x=data[(front+1)%length];
    return 1;
}

template<typename T>
bool Queue<T>::enQueue(const T &x)
{
    if(full()) return 0;
    rear=(rear+1)%length;
    data[rear]=x;
    return 1;
    
}

template<typename T>
bool Queue<T>::outQueue()
{
    if(empty()) return 0;
    front=(front+1)%length;
    return 1;
}

template<typename T>
bool Queue<T>::outQueue(T &x)
{
    if(empty()) return 0;
    front=(front+1)%length;
    x=data[front];
    return 1;
}

template<typename T>
void Queue<T>::print()
{
    if(empty()) {
        std::cout<<"empty!";
        return;
    }
    int i=front;
    while(i!=rear){
        i=(i+1)%length;
        std::cout<<data[i]<<" ";
    }
    cout<<endl;
    return;
}

template<typename T>
int Queue<T>::len()
{
    return((rear-front+length)%length);
}
#endif