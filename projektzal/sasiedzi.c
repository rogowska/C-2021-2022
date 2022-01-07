/*Oliwia Rogowska*/
#include <stdlib.h>
#include <stdio.h>
#include "sasiedzi.h"

int sasiedzi(int i, int j, int wiersze, int kolumny, int **macierz) 
// nazwa funkcji: sasiedzi - count_neighbours
// i - row_index
// wiersze - rows
// j - column index
// columns (albo columns_amount)
{
    int neighbours, k, l;
    int neighbours_row_index[3]; /*tworzenie tablic dla indeksow i oraz j sasiadow danej komorki*/
    int neighbours_column_index[3];

    if (i - 1 >= 0) // do każdego tego ifa mógłby iść opis jakiś, czym się zajmujemy, jaką częścią)
    {
        neighbours_row_index[0] = i - 1;
    }
    else
    {
        neighbours_row_index[0] = wiersze - 1;
    };
    if (i + 1 < wiersze)
    {
        neighbours_row_index[1] = i + 1;
    }
    else
    {
        neighbours_row_index[1] = 0;
    };

    neighbours_row_index[2] = i;

    if (j - 1 >= 0)
    {
        neighbours_column_index[0] = j - 1;
    }
    else
    {
        neighbours_column_index[0] = kolumny - 1;
    };
    if (j + 1 < kolumny)
    {
        neighbours_column_index[1] = j + 1;
    }
    else
    {
        neighbours_column_index[1] = 0;
    };

    neighbours_column_index[2] = j;
 
    neighbours = 0;

/*laczenie dwoch tablic aby uzyskac indeksy kolnretnych sasiadow branej pod uwage komorki*/
    // mze tutaj dodać komentarz, że patrzymy na komórkę i otaczających sąsiadów czyli tablicę 3x3 
    // i że wcześniej ją tak wypełniliśmy (tutaj dobrze by było w tych ifach mieć opis wypełniania!)
    // że mamy konkretnie w obu tablicach poprawne indeksy jak chodzi o to 3x3 i sumujemy, bo możemy, bo 0 oznacza komórkę martwą - co oznacza brak sąsiada w danej komórce
    // a 1 oznacza komórkę żywą, co znaczy dla nas obecność sąsiada
    for (k = 0; k < 3; k++)
    {
        for (l = 0; l < 3; l++)
        {
            neighbours += macierz[neighbours_column_index[l]][neighbours_row_index[k]];
        }
    }
    neighbours -= macierz[j][i];
    return neighbours;
}
