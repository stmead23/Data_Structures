#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

//Insert item at front of list
void insertAtFront(int k) {
    //Creates new value with key. Because it's in front, prev is set to null
    struct DoublyLinkedList * newItem = malloc(sizeof(struct DoublyLinkedList));
    newItem->key = k;
    newItem->prev = NULL;
    //Next value points to the old first value
    newItem->next = head;
    //Updates where the head is
    head = newItem;
    //If this is the only item in list, update tail to point to it 
    if (tail == NULL) {
        tail = newItem;
    }
}

//Insert item at end of list
void insertAtRear(int k) {
    //Creates new value with key. Because it's in rear, next is set to null
    struct DoublyLinkedList * newItem = malloc(sizeof(struct DoublyLinkedList));
    newItem->key = k;
    newItem->next = NULL;
    //If the list is empty, update head to point to the new element
    if (head == NULL) {
        head = newItem;
    }
    //If there's an item, have it point to the new item
    if (tail != NULL) {
        tail->next = newItem;
    }
    //Have new item point to prev item, and update tail pointer
    newItem->prev = tail;
    tail = newItem;
}

//Insert item at point p in list, if the list is that long
void insertInMiddle(int k, int p) {
    //Create new item, and create iterator pointer
    struct DoublyLinkedList * newItem = malloc(sizeof(struct DoublyLinkedList));
    struct DoublyLinkedList * current = head;
    newItem->key = k;
    //If the location to insert is in front, update and return
    if (p == 0) {
        newItem->next = head;
        newItem->prev = NULL;
        head = newItem;
        if (newItem->next == NULL) {
            tail = newItem;
        }
        return;
    }
    //Iterate the list, and insert if the position exists. Else, return that it's not there
    for (int i = 1; i < p; i++) {
        if (current == NULL) {
            printf("Error, the list does't have that many elements. Item not added.\n");
            return;
        }
        current = current->next;
    }
    //Insert the new item between the current and the next item, and update neccesary pointers
    newItem->next = current->next;
    current->next = newItem;
    newItem->prev = current;
    //Ensure's the next item exists, to avoid a segmentation error
    if (newItem->next != NULL) {
        newItem->next->prev = newItem;
    } else {
        //If it doesn't exist, then the new item is now at end
        tail = newItem;
    }
}

//Removes item in list, if exists
void removeKey(int k) {
    //Create iterable item
    struct DoublyLinkedList * current = head;
    //If at head, update the next to be head and remove the element
    if (head->key == k) {
        head = head->next;
        head->prev = NULL;
        free(current);
        return;
    }
    //Iterate through list
    while (current->next != NULL) {
        //Found element
        if (current->key == k) {
            //Update necessary items
            current->prev->next = current->next;
            //If there's a next element, have it point to the current's previous item
            if (current->next != NULL) { 
                current->next->prev = current->next;
            } else { //If the element being removed is the last, have tail point to the previous element
                tail = current->prev;
            }
            //Remove element
            current->next = NULL;
            current->prev = NULL;
            free(current);
            return;
        }
        current = current->next;
    }
    //The key is not in list. Nothing to be done
    printf("Key not in list.\n");
}

//Iterates and prints list
void printList() {
    struct DoublyLinkedList * current = head;
    while (current != NULL) {
        printf("%d->", current->key);
        current = current->next;
    }
    putchar('\n');
}