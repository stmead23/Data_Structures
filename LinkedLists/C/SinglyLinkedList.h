#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct SinglyLinkedList {
    int key;
    struct SinglyLinkedList * next;
};

struct SinglyLinkedList * head;

void insertAtFront(int k);
void insertAtRear(int k);
void insertInMiddle(int k, int p);
void removeKey(int k);
void printList();

#endif