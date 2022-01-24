/*Oliwia Rogowska*/
#include <stdlib.h>
#include <stdio.h>
#include "count_neighbours.h"

int count_neighbours(int boundary_condition, int row_index, int column_index, int rows, int columns, int **matrix)

{
    int neighbours, k, l;
    int neighbours_row_index[3];
    int neighbours_column_index[3];
    int counter_i, counter_j;

    if (boundary_condition == 1)
    {
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
    }

    if (boundary_condition == 2)
    {
        int over = row_index - 1 >= 0 ? 1 : 0; /* 1 - true, 0 - false*/
        int under = row_index + 1 < rows ? 1 : 0;
        int neighbours_row_amount = 1 + over + under; /*1 is for current cell*/

        int *neighbours_row_index = calloc(neighbours_row_amount, sizeof(int));
        int neighbours_counter = 0;
        if (over)
        {
            neighbours_row_index[neighbours_counter++] = row_index - 1;
        }
        neighbours_row_index[neighbours_counter++] = row_index;
        if (under)
        {
            neighbours_row_index[neighbours_counter++] = row_index + 1;
        }

        counter_i = neighbours_counter;

        int left = column_index - 1 >= 0 ? 1 : 0; /* 1 - true, 0 - false*/
        int right = column_index + 1 < columns ? 1 : 0;
        int neighbours_column_amount = 1 + left + right; /*1 is for current cell*/

        int *neighbours_column_index = calloc(neighbours_column_amount, sizeof(int));
        neighbours_counter = 0;
        if (left)
        {
            neighbours_column_index[neighbours_counter++] = column_index - 1;
        }
        neighbours_column_index[neighbours_counter++] = column_index;
        if (right)
        {
            neighbours_column_index[neighbours_counter++] = column_index + 1;
        }
        counter_j = neighbours_counter;
        neighbours = 0;

        for (k = 0; k < counter_i; k++)
        {
            for (l = 0; l < counter_j; l++)
            {
                neighbours += matrix[neighbours_column_index[l]][neighbours_row_index[k]];
            }
        }
        neighbours -= matrix[column_index][row_index];
    }
    return neighbours;
}
