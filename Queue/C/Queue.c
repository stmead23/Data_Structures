#include "Queue.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void setup() {
    queue = calloc(1,sizeof(int));
    size = 0;
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
int first() {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to return.\n");
        return 0;
    }
    return queue[0];
}
void enqueue(int element) {
    queue = realloc(queue, sizeof(int)*(size+2));
    queue[getSize()] = element;
    incSize();
}
int dequeue() {
    int element = first();
    if (!element) {
        return element;
    }
    for (int i = 1; i < getSize(); i++) {
        queue[i-1] = queue[i];
    }
    queue = realloc(queue, sizeof(int)*(size));
    decSize();
    return element;
}
void printQueue() {
    if (isEmpty()) {
        printf("Empty.\n");
        return;
    }
    
    for (int i = 0; i < getSize(); i++) {
        printf("%d ", queue[i]);
    }
    putchar('\n');
}