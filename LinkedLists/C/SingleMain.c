#include <stdio.h>
#include "SinglyLinkedList.h"

int main(int argc, char ** argv) {
    int key = 0, position = 0, run = 1;
    char instruction;
    head = NULL;
    while (run) {
        printf("Enter the command you want to run:\n\tf to insert at front\n\tb to insert at back\n\tm to insert at a position\n\tr to remove key\n\tp to print list\n\tand q to quit: ");
        instruction = getchar();
        getchar();
        switch (instruction) {
        case 'f':
            printf("Enter the key value: ");
            scanf("%d", &key);
            getchar();
            insertAtFront(key);
            break;
        case 'b':
            printf("Enter the key value: ");
            scanf("%d", &key);
            getchar();
            insertAtRear(key);
            break;
        case 'm':
            printf("Enter the key value: ");
            scanf("%d", &key);
            getchar();
            printf("Enter the location to insert item (0 is at front): ");
            scanf("%d", &position);
            getchar();
            insertInMiddle(key, position);
            break;
        case 'r':
            printf("Enter the key value to remove: ");
            scanf("%d", &key);
            getchar();
            removeKey(key);
            break;
        case 'p':
            printList();
            break;
        case 'q':
            printf("Quitting\n");
            run = 0;
            break;
        default:
            printf("Invalid instruction.\n");
            break;
        }
    }
    

    return 0;
}