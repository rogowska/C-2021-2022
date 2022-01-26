/*Oliwia Rogowska*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

/* Check count coulumn and compare in each row */
int check_geometry(int *row_count, int *column_count, char filename[])
{

    FILE *fh;
    char row_array[BOARD_SIDE_MAX];
    char *state;

    int row_index, column_index, column_size_check;

    fh = fopen(filename, "r");
    if (fh == NULL)
    {
        printf("Error opening file\n");
        return 0;
    }

    row_index = 0;
    column_index = 0;
    while (feof(fh) != true)
    {
        /* check for row counts in file - BOARD_SIDE_MAX*/
        if (fgets(row_array, BOARD_SIDE_MAX, fh) != NULL)
        {
            state = strtok(row_array, ",");
            row_index++;
            column_index = 0;
            while (state != NULL)
            {
                char *endptr;
                long result = strtol(state, &endptr, 10);
                /* nothing parsed from the string, handle errors and exit */
                if (endptr == state)
                {
                    printf("Input file should contains coma seperate lines with '0' or '1' only values\n");
                    fclose(fh);
                    return 0;
                }
                /* unexpected values after conversion */
                if (result != 1.0 && result != 0.0)
                {
                    printf("Input file should contains coma seperate lines with '0' or '1' only values\n");
                    fclose(fh);
                    return 0;
                }

                state = strtok(NULL, ",");
                column_index++;
                /* check for column columns count size */
                if (column_index > BOARD_SIDE_MAX)
                {
                    printf("%s%i\n", "Error reading input file, please make sure that row number is lower than: ", BOARD_SIDE_MAX);
                    fclose(fh);
                    return 0;
                }
            }

            /* check if following columns are the same size */
            if ((row_index > 2) && (column_index != column_size_check))
            {
                printf("%s %i %s\n", "In the input file, in row", row_index, "the number of columns is different from the previous row");
                fclose(fh);
                return 0;
            }
            column_size_check = column_index;
        }
        else{
            printf("%s%i\n", "Error reading input file, please make sure that row number is lower than: ", BOARD_SIDE_MAX);
            fclose(fh);
            return 0;
        }
    }
    fclose(fh);
    printf("%i,%i\n", row_index, column_index);
    *column_count = column_index;
    *row_count = row_index;
    return 1;
}