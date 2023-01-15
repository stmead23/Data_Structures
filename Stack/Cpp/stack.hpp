#ifndef STACK_HPP
#define STACK_HPP

class Stack {
private:
    int * stack;
    int size;
    int max_size;
    void incSize();
    void decSize();
    bool isEmpty();
public:
    Stack(int s) {
        max_size = s;
        size = 0;
        stack = new int[max_size];
    }
    void push(int element);
    int pop();
    int top();
    int getSize();
    void printStack();
};

#endif