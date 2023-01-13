/*This program implemnts a stack. There are two options for input: either a provided 
text file, or a file that the user creates. There are 4 command options: number.push
to insert the number, pop to remove the number, top to view the most recently added
number, and size to check the current size of the stack. Make sure the first element
is the planned size of the stack.
To compile: gcc stack_main.c stack.c -o stack_main
To execute: ./stack_main to use the included file, or ./stack_main your_file.txt to
use your own */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char * argv[]) {
    char command[10]; //buffer for command input
    int key_value = 0; //For keys to be inserted
    FILE * fptr; //to open file
    if (argc > 1) { //If a file name was inserted, use it to open
        fptr = fopen(argv[1], "r");
    } else { //Otherwise use the default
        fptr = fopen("OperationStack.txt", "r");
    }
    
    if (fptr == NULL) { //If the file doesn't open
        printf("Error opening file.\n");
        return -1;
    }
    fscanf(fptr, "%d", &max_size); //Find the size of the stack
    setup(); //Run setup for the stack
    while (fscanf(fptr, "%s", command) != EOF) { //While there are commands left
        printf("Instruction: %s\n", command);
        sscanf(command, "%d.%s", &key_value, command); //If it's push, separate the key and command
        if (strcmp(command, "push") == 0) { //Runs the push command
            printf("Stack before push: ");
			printStack();
            push(key_value);
            printf("Stack after push: ");
			printStack();
        } else if (strcmp(command, "pop") == 0) { //Runs the pop command
            printf("Stack before pop: ");
			printStack();
            pop();
			printf("Stack after pop: ");
			printStack();
        } else if(strcmp(command, "top") == 0) { //Runs the top command
            printf("Top of stack: %d.\n", top());
        } else if(strcmp(command, "size") == 0) { //Runs the size command
            printf("Size of stack: %d.\n", getSize());
        } else { //If the instruction is not in a good form
            printf("Invalid instruction!\n");
        }
        putchar('\n');
    }
    fclose(fptr); //Close the file
    return 0;
}