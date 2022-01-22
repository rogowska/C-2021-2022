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
    int random_value, init_density, rows, row_index, column_index, columns, neighbours_amount, steps, population, delay, copy_index;
    /*Initial value for program arguments that are used to validate user input*/
    delay = 1;
    rows = -1;
    columns = -1;
    steps = -1;
    init_density = 50;

    if (validate_user_input(&init_density, &rows, &columns, &steps, &delay, argc, argv) == 0)
    {
        return 0;
    }

    char file_name[50] = "sinc.csv";
    if (check_geometry(&rows, &columns, file_name) == 0)
    {
        return 0;
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
    if (fill_matrix(matrix_current, &population, file_name) == 0)
    {
        return 0;
    }

    /*generating initial board with random values
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
*/

    save_matrix(rows, columns, matrix_current, "out.csv");
    
    /*printing on console generated board*/
    printf("\e[1;1H\e[2J"); /*clear terminal*/
    printf("Generated board:\n");
    printf("%s %i\n", "Population:", population);
    print_matrix(rows, columns, matrix_current);
    printf("\n");
    sleep(2);
    
    /*calculating the future state of cells on board*/
    while (steps > 0)
    {
        population = 0;
        for (row_index = 0; row_index < rows; row_index++)
        {
            for (column_index = 0; column_index < columns; column_index++)
            {
                neighbours_amount = count_neighbours(row_index, column_index, rows, columns, matrix_current);
                matrix_future[column_index][row_index] = generate_next_state(neighbours_amount, row_index, column_index, matrix_current);
                if (matrix_future[column_index][row_index] == 1)
                {
                    population++;
                }
            }
        }

        /*clearing terminal and printing on console the results*/
        printf("\e[1;1H\e[2J");
        sleep(delay);
        printf("%s %d\n", "Iteration:", steps);
        printf("%s %i\n", "Population:", population);
        print_matrix(rows, columns, matrix_future);

        for (copy_index = 0; copy_index < columns; copy_index++)
        {
            /*copying data from matrix_future to matrix_current*/
            memcpy(matrix_current[copy_index], matrix_future[copy_index], sizeof(int) * rows);
        }
        steps--;
    }

    return 0;
}
