#ifndef STACK_H
#define STACK_H
#include <stdbool.h> //Includes the bool values

int * stack; //Holds the stack elements
int size; //Current size of the stack
int max_size; //Sets the max size from the input

void setup(); //Initializes the stack, and sets current size to 0
int getSize(); //returns the current size of the stack
void incSize(); //increments the size of the stack by 1
void decSize(); //decrements the size of the stack by 1
bool isEmpty(); //Returns true if there's no elements in the stack
int top(); //Returns the first value of the stack
void push(int data); //If the stack is full, nothing happens. Otherwise, it adds the element to the stack and increments size
int pop(); //If the stack is empty, nothing is done. Otherwise, it removes the most recent element and returns it
void printStack(); //Prints the entire stack

#endif
