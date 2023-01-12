#include "stack.h"
#include <stdio.h>
#include <stdlib.h> //Adds support for calloc
#include <stdbool.h> //Includes the bool values

void setup(int s) { //Initializes the stack, and sets max_value and current size to 0
    max_size = s;
    stack = calloc(max_size, sizeof(stack)); //Allocates memory for the stack
    size = 0;
}
int getSize() {return size;} //returns the current size of the stack
void incSize() {size++;} //increments the size of the stack by 1
void decSize() {size--;} //decrements the size of the stack by 1
bool isEmpty() { //Returns true if there's no elements in the stack
    if (!size) { //Run if the stack is empty
        return true;
    } else { //Run if there is an element in the stack
        return false;
    }
}
int top() { //Returns the first value of the stack
    if (isEmpty()) { //Checks if there is an element present
        printf("Stack is empty. No element to return.\n");
        return 0;
    }
    return stack[getSize() - 1]; //Returns the most recent element
}
void push(int data) { //If the stack is full, nothing happens. Otherwise, it adds the element to the stack and increments size
    if(getSize() == max_size) { //Check if there is room in the stack
        printf("Stack is full. New element wasn't added.\n");
        return;
    }
    stack[getSize()] = data; //Adds the new element
    incSize(); //Updates the current size
}
int pop() { //If the stack is empty, nothing is done. Otherwise, it removes the most recent element and returns it
    int data = 0; //Holder for the return value
    if(isEmpty()) { //Checks if empty
        printf("Stack is empty. No element to return.\n");
        return data;
    }
    data = stack[getSize() - 1]; //Assigns the most recent element to be returned
    stack[getSize()-1] = 0; //Eleminates the most recent element
    decSize(); //Updates the current size
    return data; //Returns the element
}
