#ifndef QUEUE_HPP
#define QUEUE_HPP
class Queue {
private:
    int queue[100];
    int size;
    int first_position;
    int decSize();
    int incSize();
public:
    Queue();
    int getSize();
    bool isEmpty();
    int first();
    void enqueue(int element);
    int dequeue();
    void printQueue();
};

#endif