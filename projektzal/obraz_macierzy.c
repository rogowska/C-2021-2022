#include <stdio.h>
#include <stdlib.h>
#include "obraz_macierzy.h"

int obraz_macierzy(int wiersze, int kolumny, int **macierz)
{
    int i, j;
    for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny; j++)
        {
            if (macierz[j][i] == 1)
            {
                printf("%c", '█');
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}