#include "swap.h"

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

void quickSort(double arr[], int start, int end)
{
    if (end <= start)
        return;
    int q = hoarePartition(arr, start, end);
    quickSort(arr, start, q);
    quickSort(arr, q + 1, end);
}