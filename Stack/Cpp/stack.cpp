#include "stack.hpp"
#include <iostream>

void Stack::incSize() {size++;}
void Stack::decSize() {size--;}
int Stack::getSize() {return size;}
bool Stack::isEmpty() {
    if (!size) {
        return true;
    }
    return false;
}
int Stack::top() {
    if (isEmpty()) {
        std::cout << "Stack is empty. No element to return." << std::endl;
        return 0;
    }
    return stack[getSize()-1];
}
void Stack::push(int element) {
    if(getSize() == max_size) {
        std::cout << "Stack is full. New element wasn't added." << std::endl;
        return;
    }
    stack[getSize()] = element;
    incSize();
}
int Stack::pop() {
    int element;
    if (isEmpty()) {
        std::cout << "Stack is empty. No element to return." << std::endl;
        return 0;
    }
    element = top();
    stack[getSize()-1] = 0;
    decSize();
    return element;
}
void Stack::printStack() { //Prints the entire stack
    if (isEmpty()) { //Nothing to print if empty
        std::cout << "Empty." << std::endl;
        return;
    }
    for (int i = 0; i < size; i++) { //Iterates and prints list
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}
