#include "DoublyLinkedList.hpp"
#include <iostream>

DoublyLinkedList::Node::Node(int k) {
    key = k;
    next = NULL;
    prev = NULL;
}

int DoublyLinkedList::Node::getKey() {return key;}
void DoublyLinkedList::Node::setKey(int k) {key = k;}
DoublyLinkedList::Node * DoublyLinkedList::Node::getNext() {return next;}
DoublyLinkedList::Node * DoublyLinkedList::Node::getPrev() {return prev;}
void DoublyLinkedList::Node::setNext(Node * n) {next = n;}
void DoublyLinkedList::Node::setPrev(Node * p) {prev = p;}
DoublyLinkedList::Node::~Node() {
    next = NULL;
    prev = NULL;
}

DoublyLinkedList::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
}

void DoublyLinkedList::addAtFront(int k) {
    Node * newNode = new Node(k);
    newNode->setNext(head);
    if (head != NULL) {
        head->setPrev(newNode);
    }
    head = newNode;
    if (tail == NULL) {
        tail = newNode;
    }
}

void DoublyLinkedList::addAtRear(int k) {
    Node * newNode = new Node(k);
    if (head == NULL) {
        head = newNode;
    }
    if (tail != NULL) {
        tail->setNext(newNode);
        newNode->setPrev(tail);
    }
    tail = newNode;
}

void DoublyLinkedList::addInMiddle(int k, int p) {
    Node * newNode = new Node(k);
    Node * current = head;
    if (p == 0) {
        newNode->setNext(head);
        head = newNode;
        if (newNode->getNext() == NULL) {
            tail = newNode;
        } else {
            newNode->getNext()->setPrev(newNode);
        }
        return;
    }
    for (int i = 1; i < p; i++) {
        if (current == NULL) {
            std::cout << "Error, the list does't have that many elements. Item not added.\n";
            return;
        }
        current = current->getNext();
    }
    newNode->setNext(current->getNext());
    current->setNext(newNode);
    newNode->setPrev(current);
    //If it doesn't exist, then the new item is now at end
    if (newNode->getNext() == NULL) {
        tail = newNode;
    } else {
        newNode->getNext()->setPrev(newNode);
    }
}

void DoublyLinkedList::removeKey(int k) {
    Node * current = head;
    if(head->getKey() == k) {
        head = head->getNext();
        head->setPrev(NULL);
        delete current;
    }
    while (current != NULL) {
        if (current->getKey() == k) {
            current->getPrev()->setNext(current->getNext());
            if (tail == current) {
                tail = current->getPrev();
            } else {
                current->getNext()->setPrev(current->getPrev());
            }
            delete current;
            return;
        }
        current = current->getNext();
    }
    std::cout << "Key not in list\n";
}

void DoublyLinkedList::printListForward() {
    Node * current = head;
    while (current != NULL) {
        std::cout << current->getKey() << "<->";
        current = current->getNext();
    }
    std::cout << "\n";
}

void DoublyLinkedList::printListReverse() {
    Node * current = tail;
    while (current != NULL) {
        std::cout << current->getKey() << "<->";
        current = current->getPrev();
    }
    std::cout << "\n";
}

DoublyLinkedList::~DoublyLinkedList() {
    std::cout << "Goodbye!" << std::endl;
}