#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

class SinglyLinkedList {
private:
    class Node {
    private:
        int key;
        Node * next;
    public:
        Node(int k);
        ~Node();
        int getKey();
        void setKey(int k);
        Node * getNext();
        void setNext(Node * n);
    };
    Node * head;
    Node * tail;
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    void addAtFront(int k);
    void addAtRear(int k);
    void addInMiddle(int k, int p);
    void removeKey(int k);
    void printList();
};
#endif