#include <stdlib.h>
#include <stdio.h>
#include "sasiedzi.h"

int sasiedzi(int i, int j, int wiersze, int kolumny, int **macierz)
{
    int neighbours, k, l;
    int neighbours_row_index[3];
    int neighbours_column_index[3];

    if (i - 1 >= 0)
    {
        neighbours_row_index[0] = i - 1;
    }
    else
    {
        neighbours_row_index[0] = wiersze - 1;
    };
    if (i + 1 < wiersze)
    {
        neighbours_row_index[1] = i + 1;
    }
    else
    {
        neighbours_row_index[1] = 0;
    };

    neighbours_row_index[2] = i;

    if (j - 1 >= 0)
    {
        neighbours_column_index[0] = j - 1;
    }
    else
    {
        neighbours_column_index[0] = kolumny - 1;
    };
    if (j + 1 < kolumny)
    {
        neighbours_column_index[1] = j + 1;
    }
    else
    {
        neighbours_column_index[1] = 0;
    };

    neighbours_column_index[2] = j;
 
    neighbours = 0;

    for (k = 0; k < 3; k++)
    {
        for (l = 0; l < 3; l++)
        {
            neighbours += macierz[neighbours_column_index[l]][neighbours_row_index[k]];
        }
    }
    neighbours -= macierz[j][i];
    return neighbours;
}