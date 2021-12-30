#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logika.h"
#include "sasiedzi.h"
#include "drukowanie_macierzy.h"
#include "zabezpieczenia.h"

int main()
{

    int wiersze, i, j, kolumny, liczba_sasiadow, kroki;

    printf("%s\n", "Podaj liczbę wierszy macierzy:");
    scanf("%i", &wiersze);
    printf("%s\n", "Podaj liczbę kolumn macierzy:");
    scanf("%i", &kolumny);
    printf("%s\n", "Podaj liczbę krokow:");
    scanf("%i", &kroki);

    if(zabezpieczenia(wiersze, kolumny, kroki) == 0){
        return 0;
    }

    int **macierz_current = calloc(kolumny, sizeof(int *));
    for (i = 0; i < kolumny; i++)
    {
        macierz_current[i] = calloc(wiersze, sizeof(int));
    }

    int **macierz_future = calloc(kolumny, sizeof(int *));
    for (i = 0; i < kolumny; i++)
    {
        macierz_future[i] = calloc(wiersze, sizeof(int));
    }

    srand(time(NULL));

    for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny; j++)
        {
            printf("%i", macierz_current[j][i] = rand() % 2);
        }
        printf("\n");
    }
    printf("\n");

    while (kroki > 0)
    {
        printf("%s %d\n", "Numer iteracji", kroki);
        drukowanie_macierzy(wiersze, kolumny, macierz_current);
        for (i = 0; i < wiersze; i++)
        {
            for (j = 0; j < kolumny; j++)
            {
                liczba_sasiadow = sasiedzi(i, j, wiersze, kolumny, macierz_current);
                macierz_future[j][i] = logika(liczba_sasiadow, i, j, macierz_current);
            }
        }
        drukowanie_macierzy(wiersze, kolumny, macierz_future);
        for (int k = 0; k < kolumny; k++)
        {
            macierz_current[k] = macierz_future[k];
        }
        kroki--;
    }

    return 0;
}