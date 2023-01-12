#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void setup(int s) {
    stack = calloc(s, sizeof(stack));
}
int getSize() {return size;}
void incSize() {size++;}
void decSize() {size--;}
bool isEmpty() {
    if (!size) {
        return true;
    } else {
        return false;
    }
}
int top() {
    if (isEmpty()) {
        printf("Stack is empty. No element to return.\n");
        return 0;
    }
    return stack[getSize() - 1];
}
void push(int data) {
    if(getSize() == max_size) {
        printf("Stack is full. New element wasn't added.\n");
        return;
    }
    stack[getSize()] = data;
    incSize();
}
int pop() {
    int data = 0;
    if(isEmpty()) {
        printf("Stack is empty. No element to return.\n");
        return data;
    }
    data = stack[getSize() - 1];
    stack[getSize()-1] = 0;
    decSize();
    return data;
}