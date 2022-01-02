/*Oliwia Rogowska*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "logika.h"
#include "sasiedzi.h"
#include "drukowanie_macierzy.h"
#include "zabezpieczenia.h"

int main( int argc, char *argv[] )
{
    int wiersze, i, j, kolumny, liczba_sasiadow, kroki, populacja;

    if(argc==1){
    }
    else if(strcmp(argv[1],"--help")==0 || strcmp(argv[1],"-h")==0){
        printf("Program jest sylumatorem gry w zycie,\nktory dla podawanej (po uruchomieniu) przez uzytkownika wielkosci planszy i liczby krokow\ngeneruje losowy automat komorkowy dzialajacy wedlug reguły 23/3 Johna Conwaya.\nUruchomienie programu nie wymaga podania jakichkolwiek argumentow.\n");
        return 0;
    }
    else{
        return 0;
    }

    printf("%s\n", "Podaj liczbę wierszy planszy(1-50):");
    if ((scanf("%i", &wiersze))!= 1){
        printf("Należy podac wartosci typu int\n");
        return 0;
    };
    printf("%s\n", "Podaj liczbę kolumn planszy(1-200):");
    if(scanf("%i", &kolumny)!=1){
        printf("Należy podac wartosci typu int\n");
        return 0;
    };
    printf("%s\n", "Podaj liczbę krokow symualacji:");
    if(scanf("%i", &kroki)!=1){
        printf("Należy podac wartosci typu int\n");
        return 0;
    };

    if (zabezpieczenia(wiersze, kolumny, kroki) == 0)
    {
        return 0;
    }

/*tworzenie macierzy*/
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
/*generowanie pseudolosowej macierzy*/
    srand(time(NULL));

    for (i = 0; i < wiersze; i++)
    {
        for (j = 0; j < kolumny; j++)
        {
            macierz_current[j][i] = rand() % 2;
        }
    }
/*drukowanie tej macierzy na ekranie*/
    printf("\e[1;1H\e[2J");
    printf("Wygenerowana macierz to:\n");
    drukowanie_macierzy(wiersze, kolumny, macierz_current);
    printf("\n");
    sleep(2);

/*petle w ktorych wyliczane sa wartosci kolejnych komorek nastepnej macierzy na podstawie logiki*/
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
/*drukowanie numeru iteracji, populacji i kolejnej macierzy*/
        printf("\e[1;1H\e[2J");
        sleep(1);
        printf("%s %d\n", "Numer iteracji:", kroki);
        printf("%s %i\n", "Populacja w danym kroku wynosi:", populacja);
        drukowanie_macierzy(wiersze, kolumny, macierz_future);
        for (int k = 0; k < kolumny; k++)
        {
            memcpy(macierz_current[k], macierz_future[k], sizeof(int) * wiersze); /*kopiowanie macierzy future do macierzy current*/
        }
        kroki--;
    }

    return 0;
}