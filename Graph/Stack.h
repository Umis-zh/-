#ifndef STACK_H
#define STACK_H
template<typename T>
class Stack {
private:
    T* data;
    int top;
    int length;
public:
    Stack(int x);
    ~Stack();
    Stack<T>& operator=(const Stack<T>&other);
    bool empty();
    bool full();
    bool getTop(T& x);
    bool push(const T& x);
    bool pop();
    bool pop(T& x);
    bool print();
};

template<typename T>
Stack<T>::Stack(int x) {
    length = x;
    data = new T[x];
    top = -1;
}

template<typename T>
Stack<T>::~Stack() {
    delete[] data;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>&other) {
    if(this==&other) return*this;
    delete []data;

    top=other.top;
    length=other.length;
    data=new T[other.length];
    for(int i=0;i<length;i++) data[i]=other.data[i];
    return *this;  
}

template<typename T>
bool Stack<T>::empty() {
    return top == -1;
}

template<typename T>
bool Stack<T>::full() {
    return top == length - 1;
}

template<typename T>
bool Stack<T>::getTop(T& x) {
    if (top == -1) return false;
    x = data[top];
    return true;
}

template<typename T>
bool Stack<T>::push(const T& x) {
    if (top == length - 1) return false;
    data[++top] = x;
    return true;
}

template<typename T>
bool Stack<T>::pop() {
    if (top == -1) return false;
    top--;
    return true;
}

template<typename T>
bool Stack<T>::pop(T& x) {
    if (top == -1) return false;
    x = data[top--];
    return true;
}

template<typename T>
bool Stack<T>::print() {
    if (top == -1) {
        return false;
    }
    int i=0;
    while(i<=top){
        std::cout<<data[i]<<" ";
        i++;
    }
    return true;
}

#endif