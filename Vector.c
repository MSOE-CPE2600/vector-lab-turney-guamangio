/**
 * Author: Giovanni Guaman
 * Filename: vector.c
 * Date: 10/01/25
 * Description: Defining the variables for the vector function
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 
#include "vector.h"

Vector vectors[MAX_VECTORS];

// Tokenizer function
int tokenize(char *input, char *tokens[]) {
    int count = 0;
    char *token = strtok(input, " ");
    while (token != NULL && count < MAX_TOKENS) {
        tokens[count++] = token;
        token = strtok(NULL, " ");
    }
    tokens[count] = NULL;
    return count;
}


// Vector math operations 
Vector add(Vector a, Vector b) {
    Vector result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    result.valid = 1;
    return result;
}

Vector subtract(Vector a, Vector b) {
    Vector result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.valid = 1;
    return result;
}

Vector sMult(Vector a, double s) {
    Vector result;
    result.x = a.x * s;
    result.y = a.y * s;
    result.z = a.z * s;
    result.valid = 1;
    return result;
}

double dotProd(Vector a, Vector b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vector crossProd(Vector a, Vector b) {
    Vector result = {0};
    result.x = (a.y * b.z) - (a.z * b.y);
    result.y = (a.z * b.x) - (a.x * b.z);
    result.z = (a.x * b.y) - (a.y * b.x);
    result.valid = 1;
    return result;
}


// Vector storage
int findVector(char name) {
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (vectors[i].valid && vectors[i].name == name) {
            return i;
        }
    }
    return -1;
}

void addVector(char name, double x, double y, double z) {
    int index = findVector(name);
    if (index == -1) {
        for (int i = 0; i < MAX_VECTORS; i++) {
            if (!vectors[i].valid) {
                vectors[i].name = name;
                vectors[i].x = x;
                vectors[i].y = y;
                vectors[i].z = z;
                vectors[i].valid = 1;
                printf("%c = %.2f %.2f %.2f\n", name, x, y, z);
                return;
            }
        }
        printf("Vector array is full\n");
    } else {
        vectors[index].x = x;
        vectors[index].y = y;
        vectors[index].z = z;
        printf("%c updated = %.2f %.2f %.2f\n", name, x, y, z);
    }
}

void listVectors() {
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (vectors[i].valid) {
            printf("%c = %.2f %.2f %.2f\n", vectors[i].name, vectors[i].x, vectors[i].y, vectors[i].z);
        }
    }
}

void clearVectors() {
    for (int i = 0; i < MAX_VECTORS; i++) {
        vectors[i].valid = 0;
    }
    printf("All vectors cleared.\n");
}

// Char Remover for the ','
void char_remover(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ',') s[i] = ' ';
    }
}

//Call for help on what to do.
void printHelp() 
{
    printf("\n=== MiniMat Vector Calculator Help ===\n");
    printf("a = 1 2 3 | Create vector a with values (1, 2, 3)\n");
    printf("list | List all stored vectors\n");
    printf("clear | Clear all vectors\n");
    printf("a + b  | Add vectors a and b (prints result) and creates a vector\n");
    printf("a - b  | Subtract vector b from a (prints result) and creates a vector\n");
    printf("a * 3 or 3 * a | Multiply vector a by scalar 3 (prints result) and creates a vector\n");
    printf("a . b  | Compute dot product of a and b and prints result.\n");
    printf("a x b  | Compute cross product of a and b (prints result) and creates a vector\n");
    printf("c = a + b | Store result of a + b into new vector c\n");
    printf("c = a - b | Subtracts vectors a and b (prints result) and create vector c\n");
    printf("c = a * b  | multiplies vectors a and b (prints result) and create vector c\n");
    printf("c = a . b  | Uses vectors a and b (prints result) of the dot product and create vector c\n");
    printf("c = a x b  | Uses vectors a and b (prints result) of the cross product and create vector c\n");
    printf("a | Display single vectors current values\n");
    printf("help       | Show this help menu\n");
    printf("quit       | Exit the program\n");
    printf("Hello from step 8");
}



// Command interface 
void commandInput() {
    char input[100];
    char *tokens[MAX_TOKENS];


    printf("Welcome to the mini MatLab Vector Calculator\n");

    while (1) {
    
        printf("Minimat> ");

        //sourced from stack Overflow
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // remove newline


        int tokenCount = tokenize(input, tokens);
        if (tokenCount == 0) {
            continue;
        }


        // Quit
        if (strcmp(tokens[0], "quit") == 0) { 
            break;
        }
        // List
        else if (strcmp(tokens[0], "list") == 0){ 
            listVectors();
        }
        // Clear
        else if (strcmp(tokens[0], "clear") == 0){ 
            clearVectors();
        }

        
        // c = a + b
        else if (tokenCount == 5 && strcmp(tokens[1], "=") == 0 && strcmp(tokens[3], "+") == 0 ) {
            char name = tokens[0][0];
            char v1 = tokens[2][0];
            char v2 = tokens[4][0];
            int i = findVector(v1);
            int j = findVector(v2);
            if (i == -1 || j == -1)
            { 
                printf("Vector not found\n");
            }
            else {
                Vector result = add(vectors[i], vectors[j]);
                printf("%c = %.2f %.2f %.2f\n", name, result.x, result.y, result.z);
                addVector(name, result.x, result.y, result.z);
                
            }
        }

        // a + b
        else if (tokenCount == 3 && strcmp(tokens[1], "+") == 0) {
            // for The sum
            char rename = 't';
            char v1 = tokens[0][0];
            char v2 = tokens[2][0];
            int i = findVector(v1);
            int j = findVector(v2);
            if (i == -1 || j == -1) 
            {
                printf("Vector not found\n");
            }
            else {
                Vector result = add(vectors[i], vectors[j]);
                printf("%c = %.2f %.2f %.2f\n", rename, result.x, result.y, result.z);
                addVector(rename, result.x, result.y, result.z);
            }
        }

        // c = a - b
        else if (tokenCount == 5 && strcmp(tokens[1], "=") == 0 && strcmp(tokens[3], "-") == 0 ) {
            char name = tokens[0][0];
            char v1 = tokens[2][0];
            char v2 = tokens[4][0];
            int i = findVector(v1);
            int j = findVector(v2);
            if (i == -1 || j == -1)
            { 
                printf("Vector not found\n");
            }
            else {
                Vector result = subtract(vectors[i], vectors[j]);
                printf("%c = %.2f %.2f %.2f\n", name, result.x, result.y, result.z);
                addVector(name, result.x, result.y, result.z);
                
            }
        }

        // a - b
        else if (tokenCount == 3 && strcmp(tokens[1], "-") == 0) {
            // for minus
            char rename = 'm';
            char v1 = tokens[0][0];
            char v2 = tokens[2][0];
            int i = findVector(v1);
            int j = findVector(v2);
            if (i == -1 || j == -1)
            {
                printf("Vector not found\n");
            }
            else {
                Vector result = subtract(vectors[i], vectors[j]);
                printf("ans = %.1f %.1f %.1f\n", result.x, result.y, result.z);
                addVector(rename, result.x, result.y, result.z);
            }
        }
                
        // c = 3 * b or c = b * 3
        else if (tokenCount == 5 && strcmp(tokens[1], "=") == 0 && strcmp(tokens[3], "*") == 0 ) {
            char name = tokens[0][0];
            if(isdigit((tokens[2][0]))){
                double scalar = atof(tokens[2]);
                char v1 = tokens[4][0];
                int i = findVector(v1);
            if (i == -1)
            {
                printf("Vector not found\n");
            }
            else {
                Vector result = sMult(vectors[i], scalar);
                printf("ans = %.2f %.2f %.2f\n", result.x, result.y, result.z);
                addVector(name, result.x, result.y, result.z);
            }
            } else {
                char v1 = tokens[2][0];
                double scalar = atof(tokens[4]);
                int i = findVector(v1);
            if (i == -1)
            {
                printf("Vector not found\n");
            }
            else {
                Vector result = sMult(vectors[i], scalar);
                printf("ans = %.2f %.2f %.2f\n", result.x, result.y, result.z);
                addVector(name, result.x, result.y, result.z);
            }
            }

            
        }
        // a * 3 or 3 * a
        else if (tokenCount == 3 && strcmp(tokens[1], "*") == 0) {
            // for scalar multiplication
            char rename = 's';
            if(isdigit((tokens[0][0]))){
                double scalar = atof(tokens[0]);
                char v1 = tokens[2][0];
                int i = findVector(v1);
            if (i == -1)
            {
                printf("Vector not found\n");
            }
            else {
                Vector result = sMult(vectors[i], scalar);
                printf("ans = %.2f %.2f %.2f\n", result.x, result.y, result.z);
                addVector(rename, result.x, result.y, result.z);
            }
            } else {
                char v1 = tokens[0][0];
                double scalar = atof(tokens[2]);
                int i = findVector(v1);
            if (i == -1)
            {
                printf("Vector not found\n");
            }
            else {
                Vector result = sMult(vectors[i], scalar);
                printf("ans = %.2f %.2f %.2f\n", result.x, result.y, result.z);
                addVector(rename, result.x, result.y, result.z);
            }
            }

            
        }

        // c = a . b
        else if (tokenCount == 5 && strcmp(tokens[1], "=") == 0 && strcmp(tokens[3], ".") == 0 ) {
            char v1 = tokens[2][0];
            char v2 = tokens[4][0];
            int i = findVector(v1);
            int j = findVector(v2);
            if (i == -1 || j == -1)
            { 
                printf("Vector not found\n");
            }
            else {
                double d = dotProd(vectors[i], vectors[j]);
                printf("ans = %.2f\n", d);
            }
        }

        
        // a . b
        else if (tokenCount == 3 && strcmp(tokens[1], ".") == 0) {
            char v1 = tokens[0][0];
            char v2 = tokens[2][0];
            int i = findVector(v1);
            int j = findVector(v2);
            if (i == -1 || j == -1)
            { 
                printf("Vector not found\n");
            }
            else {
                double d = dotProd(vectors[i], vectors[j]);
                printf("ans = %.2f\n", d);
            }
        }

        // c = a x b
        else if (tokenCount == 5 && strcmp(tokens[1], "=") == 0 && strcmp(tokens[3], "x") == 0 ) {
            char name = tokens[0][0];
            char v1 = tokens[2][0];
            char v2 = tokens[4][0];
            int i = findVector(v1);
            int j = findVector(v2);
            if (i == -1 || j == -1)
            { 
                printf("Vector not found\n");
            }
            else {
                Vector result = crossProd(vectors[i], vectors[j]);
                printf("%c = %.2f %.2f %.2f\n", name, result.x, result.y, result.z);
                addVector(name, result.x, result.y, result.z);
                
            }
        }

        // a x b
        else if (tokenCount == 3 && strcmp(tokens[1], "x") == 0) {
            // for the cross product
            char rename  = 'c';
            char v1 = tokens[0][0];
            char v2 = tokens[2][0];
            int i = findVector(v1);
            int j = findVector(v2);
            if (i == -1 || j == -1) 
            {
                printf("Vector not found\n");
            }
            else {
                Vector result = crossProd(vectors[i], vectors[j]);
                printf("ans = %.2f %.2f %.2f\n", result.x, result.y, result.z);
                addVector(rename, result.x, result.y, result.z);

            }
        }

        // a = 1 2 3
        else if (tokenCount == 5 && strcmp(tokens[1], "=") == 0) {
            char name = tokens[0][0];
            double x = atof(tokens[2]);
            double y = atof(tokens[3]);
            double z = atof(tokens[4]);
        
            addVector(name, x, y, z);
        }

        // Single vector (e.g. "a")
        else if (tokenCount == 1 && strlen(tokens[0]) == 1) {
            char name = tokens[0][0];
            int i = findVector(name);
            if (i == -1) 
            {
                printf("Vector not found\n");
            }
            else printf("%c = %.2f %.2f %.2f\n", vectors[i].name, vectors[i].x, vectors[i].y, vectors[i].z);
        }

        //Help functions
        else if (strcmp(tokens[0], "help") == 0) {
            printHelp();
        }

        else {
            printf("Invalid command.\n");
        }
    }

    printf("Goodbye!\n");
}
