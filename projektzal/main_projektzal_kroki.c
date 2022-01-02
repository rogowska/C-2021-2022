#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "logika.h"
#include "sasiedzi.h"
#include "drukowanie_macierzy.h"
#include "zabezpieczenia.h"

int main()
{

    int wiersze, i, j, kolumny, liczba_sasiadow, kroki, populacja;

    printf("%s\n", "Podaj liczbę wierszy macierzy:");
    scanf("%i", &wiersze);
    printf("%s\n", "Podaj liczbę kolumn macierzy:");
    scanf("%i", &kolumny);
    printf("%s\n", "Podaj liczbę krokow:");
    scanf("%i", &kroki);

    if (zabezpieczenia(wiersze, kolumny, kroki) == 0)
    {
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
            macierz_current[j][i] = rand() % 2;
        }
    }
    printf("\e[1;1H\e[2J");
    printf("wygenerowana macierz to:\n");
    drukowanie_macierzy(wiersze, kolumny, macierz_current);
    printf("\n");
    sleep(2);

    while (kroki > 0)
    {
        populacja = 0;
        for (i = 0; i < wiersze; i++)
        {
            for (j = 0; j < kolumny; j++)
            {
                liczba_sasiadow = sasiedzi(i, j, wiersze, kolumny, macierz_current);
                macierz_future[j][i] = logika(liczba_sasiadow, i, j, macierz_current);
                if (macierz_future[j][i] == 1)
                {
                    populacja++;
                }
            }
        }
        printf("\e[1;1H\e[2J");
        sleep(1);
        printf("%s %d\n", "Numer iteracji:", kroki);
        printf("%s %i\n", "Populacja w danym kroku wynosi:", populacja);
        drukowanie_macierzy(wiersze, kolumny, macierz_future);
        for (int k = 0; k < kolumny; k++)
        {
            memcpy(macierz_current[k], macierz_future[k], sizeof(int) * wiersze);
        }
        kroki--;
    }

    return 0;
}