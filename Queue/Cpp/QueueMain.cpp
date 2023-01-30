#include <iostream>
#include "Queue.hpp"

int main(int argc, char ** argv) {
    int key, run = 1;
    char instruction;
    Queue q;
    /*while (run) {
        std::cout << "Enter the command you want to run\n\te to add an item,\n\td to remove an item,\n\tf to find the first item,\n\tand p to print: ";
        std::cin >> instruction;
        switch (instruction) {
        case 'e':
            std::cout << "Enter the key: ";
            std::cin >> key;
            q.enqueue(key);
            break;
        case 'd':
            q.dequeue();
            break;
        case 'f':
            key = q.first();
            std::cout << "The first element is " << key << "\n";
            break;
        case 'p':
            q.printQueue();
            break;
        case 'q':
            std::cout << "Quitting.\n";
            run = 0;
            break;
        default:
            std::cout << "Invalid instruction.\n";
            break;
        }
    }*/
    for (int i = 0; i <= 100; i++) {
        q.enqueue(i+1);
    }
    q.printQueue();
    q.dequeue();
    q.printQueue();
    q.enqueue(101);
    q.printQueue();
    
    return 0;
}