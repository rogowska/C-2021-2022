#include "swap.h"

void swap(double *first, double *second)
{
    double temp;
    temp = *first;
    *first = *second;
    *second = temp;
}