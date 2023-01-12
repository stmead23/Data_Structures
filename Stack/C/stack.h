#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

int * stack;
int size;
int max_size;

void setup(int s);
int getSize();
void incSize();
void decSize();
bool isEmpty();
int top();
void push(int data);
int pop();

#endif