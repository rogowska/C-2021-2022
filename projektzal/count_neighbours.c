/*Oliwia Rogowska*/
#include <stdlib.h>
#include <stdio.h>
#include "count_neighbours.h"

int count_neighbours(int row_index, int column_index, int rows, int columns, int **matrix)

{
    int neighbours, k, l;
    int neighbours_row_index[3];
    int neighbours_column_index[3];

    /*creating row index array for cell's neighbours*/
    if (row_index - 1 >= 0)
    {
        neighbours_row_index[0] = row_index - 1;
    }
    else
    {
        neighbours_row_index[0] = rows - 1;
    };
    if (row_index + 1 < rows)
    {
        neighbours_row_index[1] = row_index + 1;
    }
    else
    {
        neighbours_row_index[1] = 0;
    };

    neighbours_row_index[2] = row_index;

    /*creating column index array for cell's neighbours*/
    if (column_index - 1 >= 0) 
    {
        neighbours_column_index[0] = column_index - 1;
    }
    else
    {
        neighbours_column_index[0] = columns - 1;
    };
    if (column_index + 1 < columns)
    {
        neighbours_column_index[1] = column_index + 1;
    }
    else
    {
        neighbours_column_index[1] = 0;
    };

    neighbours_column_index[2] = column_index;

    neighbours = 0;

    /*counting the number of living neighbours, living cell - value 1, dead cell - value 0*/
    for (k = 0; k < 3; k++)
    {
        for (l = 0; l < 3; l++)
        {
            neighbours += matrix[neighbours_column_index[l]][neighbours_row_index[k]];
        }
    }
    neighbours -= matrix[column_index][row_index];
    return neighbours;
}
