#include "logika.h"

int logika(int sasiedzi, int i, int j, int **macierz_current)
{
    if (macierz_current[j][i] == 0)
    {
        if (sasiedzi == 3)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (macierz_current[j][i] == 1)
    {
        if (sasiedzi == 2 || sasiedzi == 3)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
