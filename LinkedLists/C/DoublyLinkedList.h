#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct DoublyLinkedList {
    int key;
    struct DoublyLinkedList * next;
    struct DoublyLinkedList * prev;    
};

struct DoublyLinkedList * head;    //Pointer to the front of the list
struct DoublyLinkedList * tail;    //Pointer to the end of the list


void insertAtFront(int k);         //Insert item at front of list
void insertAtRear(int k);          //Insert item at end of list
void insertInMiddle(int k, int p); //Insert item at point p in list, if the list is that long
void removeKey(int k);             //Removes item in list, if exists
void printList();                  //Iterates and prints list

#endif