#include "Queue.hpp"
#include <iostream>

Queue::Queue() {
    size = 0;
    first_position = 0;
}
int Queue::decSize() {return size--;}
int Queue::incSize() {return size++;}
int Queue::getSize() {return size;}
bool Queue::isEmpty() {
    if (getSize() == 0) {
        return true;
    }
    return false;
}
int Queue::first() {
    if (isEmpty()) {
        std::cout << "The queue is empty.\n";
        return 0;
    }
    return queue[first_position];
}

void Queue::enqueue(int element) {
    if (getSize() == 100) {
        std::cout << "The queue is full. Won't add elements.\n";
        return;
    }
    int position = (first_position + incSize()) % 100;
    queue[position] = element;
}

int Queue::dequeue() {
    int element = first();
    if(element == 0) {
        return element;
    }
    queue[first_position] = 0;
    first_position = (first_position + 1) % 100;
    decSize();
    return element;
}

void Queue::printQueue() {
    if (isEmpty()) {
        std::cout << "Empty.\n";
        return;
    }
    for (int i = first_position; i < (first_position+getSize()); i++) {
        std::cout << queue[i%100] << " ";
    }
    putchar('\n');
}
