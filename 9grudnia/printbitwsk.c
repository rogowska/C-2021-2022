/*Oliwia Rogowska*/
#include "printbitwsk.h"

int printBit(int *c, int n){
    int maska = 1<<n;
    return abs((*c&maska)>>n);
}

int zeroBit(int *c, int n){
    int maska = ~(1<<n);
    return abs((*c&maska));
}

int flipBit(int *c, int n){
    int maska = (1<<n);
    return (*c^maska);
}
int setBit(int *c, int n){
     int maska = (1<<n);
     return abs((*c|maska));
}