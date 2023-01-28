#include "SinglyLinkedList.hpp"
#include <iostream>

SinglyLinkedList::Node::Node(int k) {
    key = k;
    next = NULL;
}

int SinglyLinkedList::Node::getKey() {return key;}
void SinglyLinkedList::Node::setKey(int k) {key = k;}
SinglyLinkedList::Node * SinglyLinkedList::Node::getNext() {return next;}
void SinglyLinkedList::Node::setNext(Node * n) {next = n;}
SinglyLinkedList::Node::~Node() {next = NULL;}

SinglyLinkedList::SinglyLinkedList() {
    head = NULL;
    tail = NULL;
}

void SinglyLinkedList::addAtFront(int k) {
    Node * newNode = new Node(k);
    newNode->setNext(head);
    head = newNode;
    if (tail == NULL) {
        tail = newNode;
    }
}

void SinglyLinkedList::addAtRear(int k) {
    Node * newNode = new Node(k);
    if (head == NULL) {
        head = newNode;
    }
    if (tail != NULL) {
        tail->setNext(newNode);
    }
    tail = newNode;
}

void SinglyLinkedList::addInMiddle(int k, int p) {
    Node * newNode = new Node(k);
    Node * current = head;
    if (p == 0) {
        newNode->setNext(head);
        head = newNode;
        if (newNode->getNext() == NULL) {
            tail = newNode;
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
    //If it doesn't exist, then the new item is now at end
    if (newNode->getNext() == NULL) {
        tail = newNode;
    }
}

void SinglyLinkedList::removeKey(int k) {
    Node * current = head;
    Node * removeElement = NULL;
    if(head->getKey() == k) {
        head = head->getNext();
        delete current;
    }
    while (current->getNext() != NULL) {
        if (current->getNext()->getKey() == k) {
            removeElement = current->getNext();
            current->setNext(removeElement->getNext());
            if (tail == removeElement) {
                tail = current;
            }
            delete removeElement;
            return;
        }
        current = current->getNext();
    }
    std::cout << "Key not in list\n";
}

void SinglyLinkedList::printList() {
    Node * current = head;
    while (current != NULL) {
        std::cout << current->getKey() << "->";
        current = current->getNext();
    }
    std::cout << "\n";
}

SinglyLinkedList::~SinglyLinkedList() {
    std::cout << "Goodbye!" << std::endl;
}