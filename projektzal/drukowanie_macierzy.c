#include <stdio.h>
#include <stdlib.h>
#include "drukowanie_macierzy.h"

int drukowanie_macierzy(int wiersze, int kolumny, int **macierz_current, int j, int i){
        for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny; j++)
        {
            printf("%i", macierz_current[j][i]);
        }
        printf("\n");
    }
    return 0;
}