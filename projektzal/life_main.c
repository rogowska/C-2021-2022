/*Oliwia Rogowska*/
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "generate_next_state.h"
#include "count_neighbours.h"
#include "print_matrix.h"
#include "validate_user_input.h"
#include "check_geometry.h"
#include "fill_matrix.h"
#include "save_matrix.h"
#include "header.h"
const int BOARD_SIDE_MAX = 10000;

int main(int argc, char *argv[])
{
    int random_value, init_density, rows, row_index, column_index, columns, neighbours_amount, step_max, step_min, population, delay, copy_index;
    int borning_rule, surviving_rule;
    char input_file[FILENAME_MAX] = "", output_file[FILENAME_MAX] = "";
    /*Initial value for program arguments that are used to validate user input*/
    delay = 1;
    rows = -1;
    columns = -1;
    init_density = 50;
    borning_rule = 3;
    surviving_rule = 23;
    step_min = -1;
    step_max = -1;

    if (validate_user_input(input_file, output_file, &borning_rule, &surviving_rule, &init_density, &rows, &columns, &step_max, &step_min, &delay, argc, argv) == 0)
    {
        return 0;
    }

    if (strcmp(input_file, "") != 0)
    {

        if (check_geometry(&rows, &columns, input_file) == 0)
        {
            return 0;
        }
    }

    int **matrix_current = calloc(columns, sizeof(int *));
    for (row_index = 0; row_index < columns; row_index++)
    {
        matrix_current[row_index] = calloc(rows, sizeof(int));
    }

    int **matrix_future = calloc(columns, sizeof(int *));
    for (row_index = 0; row_index < columns; row_index++)
    {
        matrix_future[row_index] = calloc(rows, sizeof(int));
    }

    population = 0;
    if (strcmp(input_file, "") != 0)
    {
        if (fill_matrix(matrix_current, &population, input_file) == 0)
        {
            return 0;
        }
    }
    else
    {
        /* generating initial board with random values */
        srand(time(NULL));
        for (row_index = 0; row_index < rows; row_index++)
        {
            for (column_index = 0; column_index < columns; column_index++)
            {
                random_value = rand() % 101;
                if (random_value > init_density || init_density == 0)
                {
                    matrix_current[column_index][row_index] = 0;
                }
                else
                {
                    matrix_current[column_index][row_index] = 1;
                    population++;
                }
            }
        }
    }

    /*printing on console generated board*/
    printf("\e[1;1H\e[2J"); /*clear terminal*/
    printf("Generated board:\n");
    printf("%s %i\n", "Population:", population);
    print_matrix(rows, columns, matrix_current);
    printf("\n");
    sleep(2);

    int i;
    i = 0;
    /*calculating the future state of cells on board*/
    while (i <= step_max)
    {
        population = 0;
        for (row_index = 0; row_index < rows; row_index++)
        {
            for (column_index = 0; column_index < columns; column_index++)
            {
                neighbours_amount = count_neighbours(row_index, column_index, rows, columns, matrix_current);
                matrix_future[column_index][row_index] = generate_next_state(borning_rule, surviving_rule, neighbours_amount, row_index, column_index, matrix_current);
                if (matrix_future[column_index][row_index] == 1)
                {
                    population++;
                }
            }
        }

        if (step_min <= i && i <= step_max)
        {
            /*clearing terminal and printing on console the results*/
            printf("\e[1;1H\e[2J");
            sleep(delay);
            printf("%s %d\n", "Iteration:", i);
            printf("%s %i\n", "Population:", population);
            print_matrix(rows, columns, matrix_future);
            if (strcmp(output_file, "") != 0)
            {
                save_matrix(step_max, step_min, i, population, rows, columns, matrix_current, output_file);
            }
        }

        for (copy_index = 0; copy_index < columns; copy_index++)
        {
            /*copying data from matrix_future to matrix_current*/
            memcpy(matrix_current[copy_index], matrix_future[copy_index], sizeof(int) * rows);
        }
        i++;
    }

    return 0;
}
