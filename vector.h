/**
 * Author: Giovanni Guaman
 * Filename: Vector.h
 * Date: 10/01/25
 * Description: Declaring the variables for the vector function
 */

#ifndef VECTOR_H 
#define VECTOR_H

#define MAX_VECTORS 10
#define MAX_TOKENS 100

typedef struct 
{
    char name;
    float x, y, z;
    int valid;
} Vector;




Vector add(Vector a, Vector b);
Vector subtract(Vector a, Vector b);
Vector sMult(Vector a, double s);
double dotProd(Vector a, Vector b);
Vector crossProd(Vector a, Vector b);



//Vector Management
int findVector(char name);
void addVector(char name, double x, double y, double z);
void listVectors();
void clearVectors();
void printHelp();

//interface
void commandInput();





#endif //VECTOR_H
