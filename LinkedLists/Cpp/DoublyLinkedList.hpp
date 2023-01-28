#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

class DoublyLinkedList {
private:
    class Node {
    private:
        int key;
        Node * next;
        Node * prev;
    public:
        Node(int k);
        ~Node();
        int getKey();
        void setKey(int k);
        Node * getNext();
        Node * getPrev();
        void setNext(Node * n);
        void setPrev(Node * p);
    };
    Node * head;
    Node * tail;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void addAtFront(int k);
    void addAtRear(int k);
    void addInMiddle(int k, int p);
    void removeKey(int k);
    void printListForward();
    void printListReverse();
};
#endif