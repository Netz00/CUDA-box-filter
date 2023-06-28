#include "sequential.h"

int sum_sequental(int *array, int arr_length)
{
    int sum = 0;
    for (int i = 0; i < arr_length; i++)
        sum += array[i];

    return sum;
}
