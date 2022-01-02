/*Oliwia Rogowska*/
#include <stdio.h>
#include "drukowanie_macierzy.h"

int drukowanie_macierzy(int wiersze, int kolumny, int **macierz)
/*funkcja drukujaca macierz na ekranie terminalu*/
{
    int i, j;
    for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny; j++)
        {
            if (macierz[j][i]==1)
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