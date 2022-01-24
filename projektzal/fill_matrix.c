/*Oliwia Rogowska*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

int fill_matrix(int **matrix, int *population, char file_name[])
{

    FILE *fh;
    char row[BOARD_SIDE_MAX];
    char *state;

    int row_index, column_index;

    fh = fopen(file_name, "r");
    if (fh == NULL)
    {
        printf("Error opening file\n");
        return 0;
    }

    row_index = 0;
    while (feof(fh) != true)
    {
        if (fgets(row, BOARD_SIDE_MAX, fh) != NULL)
        {
            state = strtok(row, ",");
            column_index = 0;
            while (state != NULL)
            {
                char *endptr;
                long result = strtol(state, &endptr, 10);
                *population += result;
                matrix[column_index][row_index] = result;
                state = strtok(NULL, ",");
                column_index++;
            }
            row_index++;
        }
        else
        {
            printf("Error reading file\n");
            fclose(fh);
            return 0;
        }
    }
    fclose(fh);
    return 1;
}