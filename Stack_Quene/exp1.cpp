#include <iostream>
#include <string>
#include "Stack.h"
bool pipei(Stack<char> &s,std::string &x);
int main(){
    std::string x;
    std::cout<<"????????:"<<std::endl;
    std::cin>>x;
    Stack<char> s(x.length());
    if(pipei(s,x)) std::cout<<"???";
    else std::cout<<"?????";
    return 0;
}
bool pipei(Stack<char> &s,std::string &x){
    for(char c:x){
        if(s.empty()) {
            s.push(c);
            continue;
        }
        char d;
        s.getTop(d);
        if (d == '{') {
            if (c == '}') s.pop();
            else if (c == '[' || c == '(' || c == '{') s.push(c);
            else return false;
        }
        else if (d == '[') {
            if (c == ']') s.pop();
            else if (c == '(' || c == '[' || c == '{') s.push(c);
            else return false;
        }
        else if (d == '(') {
            if (c == ')') s.pop();
            else if (c == '(' || c == '[' || c == '{') s.push(c);
            else return false;
        }
        else return false;
    }
    return s.empty();
}

      