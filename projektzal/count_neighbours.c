/*Oliwia Rogowska*/
#include <stdlib.h>
#include <stdio.h>
#include "count_neighbours.h"

int count_neighbours(int row_index, int column_index, int rows, int columns, int **matrix) 

{
    int neighbours, k, l;
    int neighbours_row_index[3]; /*creating arrays for row_index and column_index of the cell's neighbours*/
    int neighbours_column_index[3];

    if (row_index - 1 >= 0) /*checking the cell neighbours' row index and filling row index array with data*/
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

    if (column_index - 1 >= 0) /*checking the cell neighbours' column index and filling column index array with data*/
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

/*laczenie dwoch tablic aby uzyskac indeksy kolnretnych sasiadow branej pod uwage komorki*/
    // mze tutaj dodać komentarz, że patrzymy na komórkę i otaczających sąsiadów czyli tablicę 3x3 
    // i że wcześniej ją tak wypełniliśmy (tutaj dobrze by było w tych ifach mieć opis wypełniania!)
    // że mamy konkretnie w obu tablicach poprawne indeksy jak chodzi o to 3x3 i sumujemy, bo możemy, bo 0 oznacza komórkę martwą - co oznacza brak sąsiada w danej komórce
    // a 1 oznacza komórkę żywą, co znaczy dla nas obecność sąsiada
    /*merging two arrays to get the cell neighbours' exact index*/
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
