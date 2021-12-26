#include <stdio.h>
#include <stdlib.h>

int sasiedzi(int i, int j, int wiersze, int kolumny)
{
    int licznik, ile_i, ile_j, sasiedzi, k, l;
    licznik = 1;
    if (i - 1 >= 0)
    {
        licznik++;
    }
    if (i + 1 <= wiersze)
    {
        licznik++;
    }

    ile_i = licznik;

    int *tab_i = calloc(ile_i, sizeof(int));

    while (licznik > 0)
    {
        tab_i[licznik] = i + 1;
        i--;
        licznik--;
    }

    licznik = 1;
    if (j - 1 >= 0)
    {
        licznik++;
    }
    if (j + 1 <= kolumny)
    {
        licznik++;
    }

    ile_j = licznik;

    int *tab_j = calloc(ile_j, sizeof(int));

    while (licznik > 0)
    {
        tab_j[licznik] = j + 1;
        j--;
        licznik--;
    }

    sasiedzi = 0;

    for (k = 0; k < ile_i; k++)
    {
        for (l = 0; l < ile_j; l++)
        {
            sasiedzi+=macierz[tab_j[l]][tab_i[k]]];
        }
    }
    sasiedzi -= macierz[j][i];
    return sasiedzi;
}