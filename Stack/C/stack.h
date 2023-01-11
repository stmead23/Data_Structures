#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

int * stack;
int size;
int max_size;

int getSize();
int incSize();
int decSize();
bool isEmpty();
int top();
void push(int data);
int pop();

#endif