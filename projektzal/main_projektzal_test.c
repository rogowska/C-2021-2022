#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logika.h"
#include "sasiedzi.h"
#include "drukowanie_macierzy.h"

int main()
{

    int wiersze, i, j, kolumny, liczba_sasiadow;
    wiersze = 4;
    kolumny = 4;

    int **macierz_future = calloc(4, sizeof(int *));
    int **macierz_current = calloc(4, sizeof(int *));
    for (int k = 0; k < 4; k++)
    {
        macierz_future[k] = calloc(4, sizeof(int));
        macierz_current[k] = calloc(4, sizeof(int));
    }

    macierz_current[0][0] = 0;
    macierz_current[0][1] = 0;
    macierz_current[0][2] = 0;
    macierz_current[0][3] = 0;
    macierz_current[1][0] = 1;
    macierz_current[1][1] = 1;
    macierz_current[1][2] = 0;
    macierz_current[1][3] = 1;
    macierz_current[2][0] = 1;
    macierz_current[2][1] = 0;
    macierz_current[2][2] = 0;
    macierz_current[2][3] = 1;
    macierz_current[3][0] = 1;
    macierz_current[3][1] = 1;
    macierz_current[3][2] = 0;
    macierz_current[3][3] = 0;

    /*
    macierz_current[0]={0,1,0,0};
    macierz_current[1]={0,0,0,0};
    macierz_current[2]={0,0,0,0};
    macierz_current[3]={0,0,0,0};
*/

    for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny; j++)
        {
            printf("%i", macierz_current[j][i]);
        }
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny; j++)
        {
            liczba_sasiadow = sasiedzi(i, j, wiersze, kolumny, macierz_current);
            printf("%d\n", liczba_sasiadow);
            macierz_future[j][i] = logika(liczba_sasiadow, i, j, macierz_current);
        }
    }

    drukowanie_macierzy(wiersze, kolumny, macierz_future, j, i);

    return 0;
}