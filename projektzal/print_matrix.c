/*Oliwia Rogowska*/
#include <stdio.h>
#include "print_matrix.h"

int print_matrix(int rows, int columns, int **matrix)

{
    int row_index, column_index;
    for (row_index = 0; row_index < rows; row_index++)
    {
        for (column_index = 0; column_index < columns; column_index++)
        {
            if (matrix[column_index][row_index] == 1)
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
