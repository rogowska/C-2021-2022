/*Oliwia Rogowska*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int save_matrix(int row_max, int column_max, int **matrix, char file_name[])
{
    FILE *fp1;
    int matrix_colit, matrix_rowit;

    fp1 = fopen(file_name, "w");
    if (fp1 == NULL)
    {
        printf("Error while opening the file.\n");
        return 0;
    }

    for (matrix_rowit = 0; matrix_rowit < row_max; matrix_rowit++)
    {
        for (matrix_colit = 0; matrix_colit < column_max; matrix_colit++)
        {
            fprintf(fp1, "%i%s", matrix[matrix_colit][matrix_rowit],
                    (matrix_colit < column_max - 1 ? "," : ""));
        }
        fprintf(fp1,"%s", (matrix_rowit < row_max - 1 ? "\n" : ""));
    }
    fclose(fp1);
    return 1;
}
