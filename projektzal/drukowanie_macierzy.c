/*Oliwia Rogowska*/
#include <stdio.h>
#include "drukowanie_macierzy.h"

int drukowanie_macierzy(int wiersze, int kolumny, int **macierz) // drukowanie_macierzy --> print_matrix
/*funkcja drukujaca macierz na ekranie terminalu*/
{
    int i, j; // i --> row_index, j --> column_index
    for (i = 0; i < wiersze; i++) // wiersze --> rows
    {
        for (j = 0; j < kolumny; j++) // kolumny --> columns
        {
            if (macierz[j][i]==1) // macierz --> matrix
                {
                    printf("*");
                }
            else
            {
                printf("\u2591");
            }
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
