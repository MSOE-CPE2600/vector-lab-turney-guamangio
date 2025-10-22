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
    initVectorStorage();
    atexit(cleanupVectors); // ensures memory freed on exit
    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
        printHelp();
        return 0;
    }
    commandInput();
    return 0;
}
