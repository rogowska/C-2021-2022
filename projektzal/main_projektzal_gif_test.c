#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "logika.h"
#include "sasiedzi.h"
#include "drukowanie_macierzy.h"
#include "gifenc.h"

int main()
{

    int wiersze, i, j, kolumny, liczba_sasiadow, kroki;

    printf("%s\n", "Podaj liczbę wierszy macierzy:");
    scanf("%i", &wiersze);
    printf("%s\n", "Podaj liczbę kolumn macierzy:");
    scanf("%i", &kolumny);
    printf("%s\n", "Podaj liczbę krokow:");
    scanf("%i", &kroki);

    ge_GIF *gif_from_array = ge_new_gif("GameOfLife.gif", kolumny, wiersze,
                                        (uint8_t[]){
                                            /* palette */
                                            0x00, 0x00, 0x00, /* 0 -> black */
                                            0x00, 0xFF, 0x00, /* 2 -> green */
                                        },
                                        2, -1, 0);
    gif_from_array->nframes = kroki+1;

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
        for (i = 0; i < wiersze; i++)
        {
            for (j = 0; j < kolumny; j++)
            {
                liczba_sasiadow = sasiedzi(i, j, wiersze, kolumny, macierz_current);
                macierz_future[j][i] = logika(liczba_sasiadow, i, j, macierz_current);
            }
        }
       /* memcpy(gif_from_array->frame, macierz_current, sizeof(macierz_current));
        ge_add_frame(gif_from_array, 100);*/
        drukowanie_macierzy(wiersze, kolumny, macierz_future, j, i);
        macierz_current = macierz_future;
        kroki--;
    }

    ge_close_gif(gif_from_array);

    return 0;
}