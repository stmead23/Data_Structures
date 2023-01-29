#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

int * queue;
int size;

void setup();
void enqueue(int element);
int dequeue();
int first();
int getSize();
void incSize();
void decSize();
bool isEmpty();
void printQueue();
#endif