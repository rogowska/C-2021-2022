#include <stdlib.h>
#include <stdio.h>
#include "sasiedzi.h"

int sasiedzi(int i, int j, int wiersze, int kolumny, int **macierz)
{
    int counter_i, counter_j, neighbours, k, l;
    
    int over = i - 1 >= 0 ? 1 : 0; /* 1 - true, 0 - false*/
    int under = i + 1 < wiersze ? 1 : 0;
    int neighbours_row_amount = 1 + over + under; /*1 is for current cell*/

    int *neighbours_row_index = calloc(neighbours_row_amount, sizeof(int));
    int neighbours_counter = 0;
    if (over)
    {
        neighbours_row_index[neighbours_counter++] = i - 1;
    }
    neighbours_row_index[neighbours_counter++] = i;
    if (under)
    {
        neighbours_row_index[neighbours_counter++] = i + 1;
    }

    counter_i=neighbours_counter;

    int left = j - 1 >= 0 ? 1 : 0; /* 1 - true, 0 - false*/
    int right = j + 1 < kolumny ? 1 : 0;
    int neighbours_column_amount = 1 + left + right; /*1 is for current cell*/

    int *neighbours_column_index = calloc(neighbours_column_amount, sizeof(int));
    neighbours_counter = 0;
    if (left)
    {
        neighbours_column_index[neighbours_counter++] = j - 1;
    }
    neighbours_column_index[neighbours_counter++] = j;
    if (right)
    {
        neighbours_column_index[neighbours_counter++] = j + 1;
    }
    counter_j=neighbours_counter;
    neighbours = 0;

    for (k = 0; k < counter_i; k++)
    {
        for (l = 0; l < counter_j; l++)
        {
            neighbours += macierz[neighbours_column_index[l]][neighbours_row_index[k]];
        }
    }
    neighbours -= macierz[j][i];
    return neighbours;
}