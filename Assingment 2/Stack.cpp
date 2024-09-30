#include "Stack.h"
#include <iostream>
using namespace std;

//push element to top of stack
void Stack::push(int value) {
    stack.push_back(value);
}

//pop top element from stack
void Stack::pop() {
    stack.pop_back();
}
//check if stack is empty
bool Stack::empty() const {
    return stack.empty();
}
//check top of stack without removing it
int Stack::top() const {
    return stack.back();
}

//calculate average of stack elements
double Stack::average() const {
    if (stack.empty()) { //if stack is empty return 0
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < stack.size(); i++) {
        sum += stack[i]; //sum all elements in stack
    }
    return sum / stack.size();
}
