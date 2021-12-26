#include <stdio.h>
#include <stdlib.h>

int logika(int sasiedzi, int i, int j)
{
    if (macierz[j][i] == 0)
    {
        if (sasiedzi == 3)
        {
            return macierz[j][i] = 1;
        }
    }
    if (macierz[j][i] == 1)
    {
        if (sasiedzi == 2 || sasiedzi == 3)
        {
            return macierz[j][i] = 1;
        }
        else
        {
            return macierz[j][i] = 0;
        }
    }
}