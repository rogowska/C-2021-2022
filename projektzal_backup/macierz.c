#include <stdio.h>
#include <stdlib.h>

int macierz()
{
    int wiersze, i, j, kolumny;

    printf("%s\n", "Podaj liczbę wierszy macierzy:");
    scanf("%i", &wiersze);
    printf("%s\n", "Podaj liczbę kolumn macierzy:");
    scanf("%i", &kolumny);

    int **macierz = calloc(kolumny, sizeof(int*));
    for (i = 0; i < kolumny; i++)
    {
        macierz[i] = calloc(wiersze, sizeof(int));
    }


    for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny; j++)
        {
            printf("%i", macierz[j][i]);
        }
        printf("\n");
    }

    return 0;
}