/*Oliwia Rogowska*/

#include <stdio.h>
#include "printbit.h"

void bin(char c);

void bin(char c)
{
    int n, w;

    for (n = 7; n >= 0; n--)
    {
        w = printBit(c, n);
        printf("%d", w);
    }
}

int main()
{
    char c[3], d;
    int n, i, j;
    union typy
    {
        double d;
        float f[2];
        int i[4];
        long int il[2];
        char c[8];
    } typ;

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
    bin(c[0]);

    printf("\n%s", "Podaj numer bitu (0-7) do wykonania operacji bitowych:");
    scanf("%i", &n);

    d = zeroBit(c[0], n);
    printf("%s %i\t\t", "Uzycie funkcji zerujacej bit", n);
    bin(d);

    d = flipBit(c[0], n);
    printf("\n%s %i\t\t", "Uzycie funkcji negujacej bit", n);
    bin(d);

    d = setBit(c[0], n);
    printf("\n%s %i\t", "Uzycie funkcji ustawiajacej na 1 bit", n);
    bin(d);

    const int sizeInt = 7;
    int intArray[] = {0, -0, 1, -1, 2, 4, 1024};
    printf("\n%s\n", "Zapis liczb calkowitych binarnie:");
    for (i = 0; i < sizeInt; i++)
    {
        typ.i[0] = intArray[i];
        printf("%i\t", intArray[i]);
        bin(typ.c[1]);
        bin(typ.c[0]);
        printf("\n");
    }

    const float sizeFloat = 7;
    float floatArray[] = {0., -0., 0.75, 1., 2., 4., 1024.};
    printf("\n%s\n", "Reprezentacja binarna liczb zmiennoprzecinkowych (float):");
    for (i = 0; i < sizeFloat; i++)
    {
        typ.f[0] = floatArray[i];
        printf("%f\t", floatArray[i]);
        bin(typ.c[3]);
        bin(typ.c[2]);
        bin(typ.c[1]);
        bin(typ.c[0]);
        printf("\n");
    }

    const double sizeDouble = 2;
    double doubleArray[] = {1.25e22, -1.375e-12};
    printf("\n%s\n", "Reprezentacja binarna liczb zmiennoprzecinkowych (double):");
    for (i = 0; i < sizeDouble; i++)
    {
        typ.d = doubleArray[i];
        printf("%lf\t", doubleArray[i]);
        bin(typ.c[7]);
        bin(typ.c[6]);
        bin(typ.c[5]);
        bin(typ.c[4]);
        bin(typ.c[3]);
        bin(typ.c[2]);
        bin(typ.c[1]);
        bin(typ.c[0]);
        printf("\n");
    }

    const int sizeBit = 4;
    int bit;
    int bitArray[] = {10, 2, 4, 1};
    for (i = 0; i < sizeBit; i++)
    {
        bit = bitArray[i];
        printf("%s %i\n", "Operacje na bicie:", bit);
        for (j = 0; j < sizeFloat; j++)
        {
            typ.f[0] = floatArray[j];
            if ((bit > 7) && (bit < 16))
            {
                typ.c[1] = flipBit(typ.c[1], bit-8);
            }
            else
            {
                typ.c[0] = flipBit(typ.c[0], bit);
            }
            printf("%s %f %s %f\n", "Zmieniona wartosc liczby", floatArray[j], "to", typ.f[0]);
        }
    }

    return 0;
}