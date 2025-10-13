/**
 * Author: Giovanni Guaman
 * Filename: vector.c
 * Date: 10/01/25
 * Description: Defining the variables for the vector function
 */

#include <stdio.h>
#include <string.h>
#include "vector.h"

Vector vectors[MAX_VECTORS];

Vector add(Vector a, Vector b)
{
    Vector result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;

}

Vector subtract(Vector a, Vector b)
{
    Vector result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

Vector sMult(Vector a, double s)
{
    Vector result;
    result.x = a.x * s;
    result.y = a.y * s;
    result.z = a.z * s;
    return result;
}


//Storage of the Vectors

int findVector(char name) {
    // searches for an vector named array
    for (int i = 0; i < MAX_VECTORS; i++) {
        if(vectors[i].valid && strcmp(vectors[i].name, name) == 0) {
        return i;
        }
    } 
    //vectors wasn't found
    return -1;
}

void addVector(Char name, double x, double y, double z){
    int index = findVector(name);
    if(index == -1){
        for ( int i = 0; i < MAX_VECTORS; i++){
            if(!vectors[i].valid){
                vectors[i].name = name, vectors[i].x = x ,vectors[i].y = y ,vectors[i].z = z, vectors[i].valid = 1;
                printf("%c = %f %f %f\n", name, x, y, z);
                return;
            }
        }
        printf("Vector array is full");
    } else{
        vectors[index].x = x;
        vectors[index].y = y;
        vectors[index].z = z;
        printf("%c updated = %f %f %f\n", name, x, y, z);
    }
}

void listVector(){
    //prints out all the vectors in the code.
    for(int i = 0; i < MAX_VECTORS; i++){
        printf("%s = %f %f %f\n", vectors[i].name, vectors[i].x, vectors[i].y, vectors[i].z);
    }
}

void clearVectors(){
     for (int i = 0; i < MAX_VECTORS; i++)
        vectors[i].valid = 0;
    printf("All vectors cleared.\n");
}


// The Command interface for the inputs
void commandInput() {
    char input[100];
    char name1, name2
    double x, y, z, scalar;

    printf("Welcome to the mini MatLab Vector Calculator\n");
    printf("Commands for the vector calculator:\n");
    printf(" a = 1 2 3  -> create or update vector\n");
    printf(" a + b -> add two vectors\n");
    printf(" a - b -> subtract two vectors\n");
    printf(" a * 2  -> multiply vector by scalar\n");
    printf(" list -> lists all vectors you have stored\n");
    printf(" quit -> quits program\n");
    printf(" clear -> clears all vectors\n");


    while (1)
    {
        printf("Minimat> ");
        fgets(input, sizeof(input), stdin);
        //sourced from Stack Overflow
        input[strcspn(input, "\n")] = 0; // removes the \n from the fgets line.

        if(strcmp(input, "quit") == 0){
            break;
        } else if(strcmp(input, "list") == 0){
            listVectors();
        } else if (strcmp(input, "clear") == 0 ) {
            clearVectors();
        } else if(sscanf(input, " %c = %lf %lf %lf", &name1, &x, &y, &z) == 4) {
            addVector(name1, x, y, z);
        } else if(sscanf(input, "%c + %c", &name1, &name2) == 2) {
            int i = findVector(name1);
            int j = findVector(name2);
            if(i == -1 || j == -1){
                printf("Vector not found");
            } else {
                Vector add = add(vectors[i], vectors[j]);
                printf("answer = %f %f %f", add.x, add.y, add.z);
            }
        } else if(sscanf(input, "%c - %c", &name1, &name2) == 2) {
            int i = findVector(name1);
            int j = findVector(name2);
            if(i == -1 || j == -1){
                printf("Vector not found");
            } else {
                Vector sub = subtract(vectors[i], vectors[j]);
                printf("answer = %f %f %f", sub.x, sub.y, sub.z);
            }
        } else if(sscanf(input, "%c * %f", &name1, %scalar ) == 2) {
            int i = findVector(name1);
            if(i == -1){
                printf("Vector not found");
            } else {
                Vector sc = sMult(vectors[i], scalar);
                printf("answer = %f %f %f", sc.x, sc.y, sc.z);
            }
        } else if (sscanf(input, " %c", &name1) == 1) {
            int i = findVector(name1);
            if (i == -1){
                printf("Error: vector not found.\n");
            }else{
                printf("%c = %.2f %.2f %.2f\n", vectors[i].name, vectors[i].x, vectors[i].y, vectors[i].z);
            }
        }else {
            printf("Invalid Command.\n");
        }
    }

    printf("Goodbye!\n");
}

