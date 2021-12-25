#include <stdio.h>
#include <stdlib.h>

int main(){
    int wiersze, i, j, kolumny;

    printf("%s\n", "Podaj liczbę wierszy macierzy:");
    scanf("%i\n", &wiersze);
    printf("%s\n", "Podaj liczbę kolumn macierzy:");
    scanf("%i\n", &kolumny);

    double **macierz=calloc(kolumny, sizeof(int));
    for(i=0; i<kolumny; i++){
    *macierz[i]=calloc(wiersze, sizeof(int));}

    for(i=0; i<wiersze; i++){
        for(j=0; j<kolumny; j++){
            printf("%i", /*macierz(j)*/0);
            printf("\n");
        }
    }

    return 0;
}