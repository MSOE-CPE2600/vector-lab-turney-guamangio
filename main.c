/**
 * Author: Giovanni Guaman
 * Filename: vector.h
 * Date: 10/01/25
 * Description: Declaring the variables for the vector function
 * To compile: gcc -o mini_matlab vector.c main.c
 */

#include <string.h>
#include "vector.h"

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
        printHelp();
        return 0;
    }
    commandInput();
    return 0;
}