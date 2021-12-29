#include <stdio.h>
#include <stdlib.h>
#include "drukowanie_macierzy.h"

int drukowanie_macierzy(int wiersze, int kolumny, int **macierz){
    int i,j;
        for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny; j++)
        {
            printf("%i", macierz[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}