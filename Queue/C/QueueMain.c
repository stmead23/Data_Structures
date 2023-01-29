#include <stdio.h>
#include "Queue.h"

int main(int argc, char * argv[]) {
    char instruction;
    int key, run = 1;
    while (run) {
        printf("Enter the instruction you wish to run\n\te to add item,\n\td to remove item,\n\tf to check the first item,\n\ts to view the current size,\n\tp to print list,\n\tand q to quit: ");
        instruction = getchar();
        getchar();
        switch (instruction) {
        case 'e':
            printf("Enter the value of the key: ");
            scanf("%d", &key);
            getchar();
            enqueue(key);
            break;
        case 'd':
            dequeue();
            break;
        case 'f':
            key = first();
            if(key != 0) {
                printf("First value: %d\n", key);
            }
            break;
        case 's':
            printf("Size of the current queue: %d\n", size);
            break;
        case 'p':
            printQueue();
            break;
        case 'q':
            printf("Quitting.\n");
            run = 0;
            break;
        default:
            break;
        }
    }
    

    return 0;
}