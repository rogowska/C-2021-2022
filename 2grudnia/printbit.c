/*Oliwia Rogowska*/
#include "printbit.h"

char printBit(char c, int n){
    int maska = 1<<n;
    return (c&maska)>>n;
}

char zeroBit(char c, int n){
    int maska = ~(1<<n);
    return (c&maska);
}

char flipBit(char c, int n){
    int maska = (1<<n);
    return (c^maska);
}
char setBit(char c, int n){
     int maska = (1<<n);
     return (c|maska);
}