/**
 * Author: Giovanni Guaman
 * Filename: main.c
 * Date: 10/01/25
 * Description: The main source file to run the program
 * To compile: gcc -o Lab5 vector.c main.c
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
        printHelp();
        return 0;
    }
    initVectorStorage();
    commandInput();
    cleanupVectors();
    return 0;
}
