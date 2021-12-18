/*Oliwia Rogowska*/

#include <stdio.h>
#include "printbitwsk.h"

void bin_char(char c);

void bin_char(char c)
{
    int n, w;

    for (n = 7; n >= 0; n--)
    {
        w = printBit(&c, n);
        printf("%d", w);
    }
}

void bin_int(int i);

void bin_int(int i)
{
    int n, w;

    for (n = 31; n >= 0; n--)
    {
        w = printBit(&i, n);
        printf("%d", w);
    }
}

void bin_float(float f);

void bin_float(float f)
{
    int n, w;

    for (n = 31; n >= 0; n--)
    {
        w = printBit(&f, n);
        printf("%d", w);
    }
}
void bin_double(double *d);

void bin_double(double *d)
{
    int n, w;

    for (n = 31; n >= 0; n--)
    {
        w = printBit(d, n);
        printf("%d", w);
    }
}

int main()
{
    char c[3], d;
    int n, i, j, *wsk;

    printf("%s", "Podaj znak:");
    if (fgets(c, 3, stdin) == NULL)
    {
        printf("%s\n", "Oczekiwano pojedynczego znaku");
        return 1;
    }
    if (c[1] != '\n')
    {
        printf("%s\n", "Oczekiwano pojedynczego znaku");
        return 1;
    }
    printf("%s\t\t", "Reprezentacja dziesietna:");
    printf("%i\n", c[0]);
    printf("%s\t\t\t", "Reprezentacja binarna:");
    bin_char(c[0]);

    printf("\n%s", "Podaj numer bitu (0-7) do wykonania operacji bitowych:");
    scanf("%i", &n);

    d = zeroBit(&c[0], n);
    printf("%s %i\t\t", "Uzycie funkcji zerujacej bit", n);
    bin_char(d);

    d = flipBit(&c[0], n);
    printf("\n%s %i\t\t", "Uzycie funkcji negujacej bit", n);
    bin_char(d);

    d = setBit(&c[0], n);
    printf("\n%s %i\t", "Uzycie funkcji ustawiajacej na 1 bit", n);
    bin_char(d);

    const int sizeInt = 7;
    int intArray[] = {0, -0, 1, -1, 2, 4, 1024};
    printf("\n%s\n", "Zapis liczb calkowitych binarnie:");
    for (i = 0; i < sizeInt; i++)
    {
        printf("%i\t", intArray[i]);
        bin_int(intArray[i]);
        printf("\n");
    }

    const float sizeFloat = 7;
    float floatArray[] = {0., -0., 0.75, 1., 2., 4., 1024.};
    printf("\n%s\n", "Reprezentacja binarna liczb zmiennoprzecinkowych (float):");
    for (i = 0; i < sizeFloat; i++)
    {
        printf("%f\t", floatArray[i]);
        bin_float(floatArray[i]);
        printf("\n");
    }

    const double sizeDouble = 2;
    double doubleArray[] = {1.25e22, -1.375e-12};
    printf("\n%s\n", "Reprezentacja binarna liczb zmiennoprzecinkowych (double):");
    for (i = 0; i < sizeDouble; i++)
    {
        wsk = &doubleArray[i];
        wsk++;
        printf("%lf\t", doubleArray[i]);
        bin_double(wsk);
        wsk--;
        bin_double(wsk);
        printf("\n");
    }

    const int sizeBit = 4;
    int bit, w;
    float *conversion;
    int bitArray[] = {10, 2, 4, 1};
    for (i = 0; i < sizeBit; i++)
    {
        bit = bitArray[i];
        printf("\n\n%s %i\n", "Operacje na bicie:", bit);
        for (j = 0; j < sizeFloat; j++)
        {
            w = flipBit(&floatArray[j], bit);
            conversion=&w;
            printf("\n%s %f %s %f\t", "Zmieniona wartosc liczby", floatArray[j], "to ", *conversion);
        }
    }
    return 0;
}