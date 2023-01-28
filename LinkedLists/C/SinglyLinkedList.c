#include "SinglyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void insertAtFront(int k) {
    struct SinglyLinkedList * newItem = malloc(sizeof(struct SinglyLinkedList));
    newItem->key = k;
    newItem->next = head;
    head = newItem;
}

void insertAtRear(int k) {
    struct SinglyLinkedList * newItem = malloc(sizeof(struct SinglyLinkedList));
    struct SinglyLinkedList * current = head;
    newItem->key = k;
    newItem->next = NULL;
    if (head == NULL) {
        head = newItem;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newItem;
}

void insertInMiddle(int k, int p) {
    struct SinglyLinkedList * newItem = malloc(sizeof(struct SinglyLinkedList));
    struct SinglyLinkedList * current = head;
    newItem->key = k;
    if (p == 0) {
        newItem->next = head;
        head = newItem;
        return;
    }
    
    for (int i = 1; i < p; i++) {
        if (current == NULL) {
            printf("Error, the list does't have that many elements. Item not added.\n");
            return;
        }
        current = current->next;
    }
    newItem->next = current->next;
    current->next = newItem;
}

void removeKey(int k) {
    struct SinglyLinkedList * current = head;
    struct SinglyLinkedList * remove = NULL;
    
    if (head->key == k) {
        head = head->next;
        free(current);
        return;
    }

    while (current->next != NULL) {
        if (current->next->key == k) {
            remove = current->next;
            current->next = remove->next;
            remove->next = NULL;
            free(remove);
            return;
        }
        current = current->next;
    }
    printf("Key not in list.\n");
}

void printList() {
    struct SinglyLinkedList * current = head;
    while (current != NULL) {
        printf("%d->", current->key);
        current = current->next;
    }
    putchar('\n');
}

