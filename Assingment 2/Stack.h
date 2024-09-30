#pragma once
#ifndef STACK_H
#define STACK_H

#include <vector>

using namespace std;

class Stack {
private:
    vector<int> stack; //vectore to store stack elements

public:
    void push(int value); //push value onto stack
    void pop(); //pop top element off stack
    bool empty() const; //check if stack is empty
    int top() const; //get top element without popping it
    double average() const; //calc average of elements in the stack
};
#endif
