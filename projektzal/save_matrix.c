/*Oliwia Rogowska*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int save_matrix(int step_max, int step_min, int iteration, int population, int row_max, int column_max, int **matrix, char file_name[])
{
    FILE *fp1;
    int matrix_colit, matrix_rowit;

    fp1 = fopen(file_name, "a");
    if (fp1 == NULL)
    {
        printf("Error while opening the file.\n");
        return 0;
    }

    if(step_max!=step_min){
    fprintf(fp1, "\n%s%i\n%s%i\n", "Iteration:", iteration, "Population:", population);
    }
    for (matrix_rowit = 0; matrix_rowit < row_max; matrix_rowit++)
    {
        for (matrix_colit = 0; matrix_colit < column_max; matrix_colit++)
        {
            fprintf(fp1, "%i%s", matrix[matrix_colit][matrix_rowit],
                    (matrix_colit < column_max - 1 ? "," : ""));
        }
        fprintf(fp1, "%s", (matrix_rowit < row_max - 1 ? "\n" : ""));
    }
    fclose(fp1);
    return 1;
}
