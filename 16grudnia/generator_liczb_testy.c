/*Oliwia Rogowska*/

#define _XOPEN_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

void swap(double *, double *);
void swap(double *first, double *second)
{
    double temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(double *, int);
void bubbleSort(double array[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {

        for (j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

/*na podstawie algorytmu z CLRS*/
int hoarePartition(double *, int, int);
int hoarePartition(double a[], int p, int r)
{
    double x = a[p];
    int i = p - 1, j = r + 1;
    while (1)
    {
        do
            j--;
        while (a[j] > x);
        do
            i++;
        while (a[i] < x);
        if (i < j)
            swap(&a[i], &a[j]);
        else
            return j;
    }
}

void quickSort(double *, int, int);
void quickSort(double arr[], int start, int end)
{
    if (end <= start)
        return;
    int q = hoarePartition(arr, start, end);
    quickSort(arr, start, q);
    quickSort(arr, q + 1, end);
}

int max(int number1, int number2);
int max(int number1, int number2)
{
    if (number1 > number2)
    {
        return number1;
    }
    else
    {
        return number2;
    }
}

int porownywanie(const void *x1, const void *x2);
int porownywanie(const void *x1, const void *x2)
{
    if ((*(double *)x1) == (*(double *)x2))
    {
        return 0;
    }
    if ((*(double *)x1) > (*(double *)x2))
    {
        return 1;
    }
    return -1;
}

int main()
{
    int ktory_przedzial, ilosc_przypadkow, liczba_przedzialow, maximum, i, j;
    double deltai, czas_sortowania;
    float gwiazdka_normalizacja;
    int przedzialy[100] = {0};
    clock_t tp, tk;

    /* obsługa wejścia */

    printf("%s\n", "podaj ilosc liczb na ktorych chcesz przeprowadzic testy:");
    scanf("%i", &ilosc_przypadkow);

    double *przypadki = calloc(ilosc_przypadkow, sizeof(double));
    double *backup = calloc(ilosc_przypadkow, sizeof(double));

    if (przypadki == 0 || backup == 0)
    {
        printf("%s\n", "Podaj mniejsza liczbe przypadkow, brak pamieci");
        return -1;
    }

    printf("%s\n", "podaj liczbe przedzialow:");
    scanf("%i", &liczba_przedzialow);

    if (ilosc_przypadkow < liczba_przedzialow)
    {
        printf("%s\n", "Podaj ilosc liczb wieksza od liczby przedzialow");
        return -1;
    }
    if ((ilosc_przypadkow == 0) || (liczba_przedzialow == 0))
    {
        printf("%s\n", "ilosc liczb i liczba przedzialow musza byc wieksze od 0");
        return -1;
    }

    /* Wypełniane tablicy przypadków*/

    srand48(time(NULL));
    for (i = 0; i < ilosc_przypadkow; i++)
    {
        przypadki[i] = drand48();
        int numer_przedzialu = przypadki[i] * liczba_przedzialow;
        przedzialy[numer_przedzialu]++;
    }

    memcpy(backup, przypadki, sizeof(double) * ilosc_przypadkow);

    /* Szukanie max wartosci przedzialu */

    maximum = przedzialy[0];
    for (i = 1; i < liczba_przedzialow; i++)
    {
        maximum = max(maximum, przedzialy[i]);
    }

    gwiazdka_normalizacja = maximum / 150.0;

    /* Optymalizacja histogramu */
    /* Histogram wylosowanych liczb */

    for (i = 0; i < liczba_przedzialow; i++)
    {
        printf("%i\t", i);
        for (j = 0; j < (przedzialy[i] / gwiazdka_normalizacja); j++)
        {
            printf("%c", '*');
        }
        printf("\n");
    }

    /* Sortowanie i wyznaczanie czasu sortowania dla różnych funkcji sortujących */

    tp = clock();
    qsort(&przypadki[0], ilosc_przypadkow, sizeof(double), porownywanie);
    tk = clock();
    czas_sortowania = (tk - tp) / (double)CLOCKS_PER_SEC;
    printf("%s%lf\n", "Czas sortowania qsort wynosi: (sec)", czas_sortowania);

    memcpy(przypadki, backup, sizeof(double) * ilosc_przypadkow);

    tp = clock();
    quickSort(przypadki, 0, ilosc_przypadkow - 1);
    tk = clock();
    czas_sortowania = (tk - tp) / (double)CLOCKS_PER_SEC;
    printf("%s%lf\n", "Czas sortowania quickSort wynosi: (sec)", czas_sortowania);

    memcpy(przypadki, backup, sizeof(double) * ilosc_przypadkow);

    tp = clock();
    bubbleSort(przypadki, ilosc_przypadkow);
    tk = clock();
    czas_sortowania = (tk - tp) / (double)CLOCKS_PER_SEC;
    printf("%s%lf\n", "Czas sortowania bubblesort wynosi: (sec)", czas_sortowania);

    /* Obliczanie różnic między sąsiadami i lokowanie ich w odpowiednich przedziałach */

    for (i = 0; i < liczba_przedzialow; i++)
    {
        przedzialy[i] = 0;
    }

    for (i = 0; i < ilosc_przypadkow - 1; i++)
    {
        deltai = fabs(przypadki[i + 1] - przypadki[i]);
        ktory_przedzial = deltai * liczba_przedzialow;

        przedzialy[ktory_przedzial]++;
    }

    /* Szukanie max wartosci przedzialu */

    maximum = przedzialy[0];
    for (i = 1; i < liczba_przedzialow; i++)
    {
        maximum = max(maximum, przedzialy[i]);
    }

    gwiazdka_normalizacja = maximum / 150.0;

    /* Drukowanie histogramu różnic wylosowanych liczb */

    for (i = 0; i < liczba_przedzialow; i++)
    {
        if (przedzialy[i] != 0)
        {

            printf("%i\t", i);
            for (j = 0; j < (przedzialy[i] / gwiazdka_normalizacja); j++)
            {
                printf("%c", '*');
            }
            printf("\n");
        }
    }

    return 0;
}
