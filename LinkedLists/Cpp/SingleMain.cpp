#include <iostream>
#include "SinglyLinkedList.hpp"

int main(int argc, char ** argv) {
    int key = 0, position = 0, run = 1;
    char instruction;
    SinglyLinkedList list;
    while (run == 1) {
        std::cout << "Enter the command you want to run:\n\tf to insert at front\n\tb to insert at back\n\tm to insert at a position\n\tr to remove key\n\tp to print list\n\tand q to quit: ";
        std::cin >> instruction;
        switch (instruction) {
        case 'f':
            std::cout << "Enter the key value: ";
            std::cin >> key;
            list.addAtFront(key);
            break;
        case 'b':
            std::cout << "Enter the key value: ";
            std::cin >> key;
            list.addAtRear(key);
            break;
        case 'm':
            std::cout << "Enter the key value: ";
            std::cin >> key;
            std::cout << "Enter the location to insert item (0 is at front): ";
            std::cin >> position;
            list.addInMiddle(key, position);
            break;
        case 'r':
            std::cout << "Enter the key value to remove: ";
            std::cin >> key;
            list.removeKey(key);
            break;
        case 'p':
            list.printList();
            break;
        case 'q':
            std::cout << "Quitting\n";
            run = 0;
            break;
        default:
            std::cout << "Invalid instruction\n";
            break;
        }
    }
    
    return 0;
}