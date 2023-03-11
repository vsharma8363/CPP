// Import of standard IO library
#include <stdio.h>

int exit_code = 0;

// Main function - Called at program launch
int main() {
    printf("Hello to the world!");

    // Return an integer, typically exit code (Not required)
    return exit_code;
}

// During program compilation:
//  1. PreProcessor --> Converts files into **translation units**
//  2. Compiler --> Converts **Translation units** into **object files**
//  3. Linker --> Links object files into a single program

// Cpp is **strongly typed**