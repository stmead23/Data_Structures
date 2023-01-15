/*This program implemnts a stack. There are two options for input: either a provided 
text file, or a file that the user creates. There are 4 command options: number.push
to insert the number, pop to remove the number, top to view the most recently added
number, and size to check the current size of the stack. Make sure the first element
is the planned size of the stack.
To compile: g++ stack_main.cpp stack.cpp -o stack_main
To execute: ./stack_main to use the included file, or ./stack_main your_file.txt to
use your own */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "stack.hpp"

int main(int argc, char * argv[]) {
    std::string command;
    int key_value = 0;
    int s = 0;
    std::ifstream MyFile;
    
    if (argc > 1) {
        MyFile.open(argv[1]);
    } else {
        MyFile.open("OperationStack.txt");
    }
    

    if(!MyFile.is_open()) {
        std::cout << "Error opening file.\n";
        return -1;
    }

    MyFile >> s;
    Stack TheStack(s);

    while (!MyFile.eof()) {
        MyFile >> command;
        std::cout << "Instruction: " << command << std::endl;
        std::stringstream ss(command);
        ss >> key_value >> command;
        if (command.find("push") != std::string::npos) {
            std::cout << "Stack before push: ";
            TheStack.printStack();
            TheStack.push(key_value);
            std::cout << "Stack after push: ";
            TheStack.printStack();
        } else if(command == "pop") {
            std::cout << "Stack before pop: ";
            TheStack.printStack();
            TheStack.pop();
            std::cout << "Stack after pop: ";
            TheStack.printStack();
        } else if(command == "top") {
            std::cout << "Top of stack: " << TheStack.top() << std::endl;
        } else if(command == "size") {
            std::cout << "Size of stack: " << TheStack.getSize() << std::endl;
        } else {
            std::cout << "Invalid instruction!" << std::endl;
        }
        std::cout << std::endl;
    }
    
    MyFile.close();
    return 0;
}