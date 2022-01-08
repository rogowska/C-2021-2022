/*Oliwia Rogowska*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "generate_next_state.h"
#include "count_neighbours.h"
#include "print_matrix.h"
#include "validate_user_input.h"

int main(int argc, char *argv[])
{
    int rows, row_index, column_index, columns, neighbours_amount, steps, population, delay;
    delay = 1;

    if (argc == 4)
    {
        columns = argv[1];
        rows = argv[2];
        steps = argv[3];
    }
    else if (argc == 5)
    {
        columns = argv[1]; // jak sprawdzic czy jest to int? ? ? jak do funkcji wewnetrzej ? ? ?
        rows = argv[2];
        steps = argv[3];
        delay = argv[4];
    }
    else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
    {
        printf("usage:  life --columns --rows --steps [--delay]
    or
        life --tryout

Symulator game of 'Life' based on 23/3 John Conway rule with pseudo-random initial conditions.

Mandatory arguments to long options are mandatory for short options too.

       -c, --columns=n
              column size of board as positive value in range <1-10000>

       -d, --delay=n
              delay in seconds between printing current board (default 1)

       -h, --help
              display this help and exit

       -r, --rows=n
              rows size of board as positive value in range <1-10000>

       -s, --steps=n
              number of simulation steps, positive natural number

       -t, --tryout
              run demo, predifine usaged arguments: -c 40 -r 20 -s 100");
        return 0;
    }
    else if (strcmp(argv[1], "--tryout") == 0)
    {
        columns = 40;
        rows = 20;
        steps = 100;
    }
    else
    {
        return 0;
    }

    // getting input values from the user, validating value type
    printf("%s\n", "Set row amount for a board(1-10000):");
    if ((scanf("%i", &rows)) != 1)
    {
        printf("The value should be an integer. Exiting...\n");
        return 0;
    };
    printf("%s\n", "Set column amount for a board(1-10000):");
    if (scanf("%i", &columns) != 1)
    {
        printf("The value should be an integer. Exiting...\n");
        return 0;
    };
    printf("%s\n", "Set step amount for simulation:");
    if (scanf("%i", &steps) != 1)
    {
        printf("The value should be an integer. Exiting...\n");
        return 0;
    };

    if (validate_user_input(rows, columns, steps) == 0)
    {
        return 0;
    }

    /*creating a matrix*/
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

    /*generating initial board with random values*/
    srand(time(NULL));

    for (row_index = 0; row_index < rows; row_index++)
    {
        for (column_index = 0; column_index < columns; column_index++)
        {
            matrix_current[column_index][row_index] = rand() % 2;
        }
    }

    /*printing generated board*/
    printf("\e[1;1H\e[2J");
    printf("Generated board:\n");
    print_matrix(rows, columns, matrix_current);
    printf("\n");
    sleep(2);

    /*counting the future state of cells*/
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

        /*printing the results*/
        printf("\e[1;1H\e[2J");
        sleep(delay);
        printf("%s %d\n", "Iteration:", steps);
        printf("%s %i\n", "Population:", population);
        print_matrix(rows, columns, matrix_future);
        for (int copy_index = 0; copy_index < columns; copy_index++)
        {
            memcpy(matrix_current[copy_index], matrix_future[copy_index], sizeof(int) * rows);
            /*copying data from matrix_future to matrix_current*/
        }
        steps--;
    }

    return 0;
}
