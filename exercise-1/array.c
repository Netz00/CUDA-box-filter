#include "array.h"

int readNumberFromInput()
{
    int number;
    scanf("%d", &number);
    flushStdin;
    return number;
}

int *readArrayFromInput(int *arr_length)
{

    int *array;
    int number_of_elements;

    printf("Enter number of elements: ");
    number_of_elements = readNumberFromInput();

    array = (int *)malloc(number_of_elements * sizeof(int));

    if (array == NULL)
    {
        printf("%sMemory not allocated.%s\n", KRED, KNRM);
        exit(0);
    }

    for (int i = 0; i < number_of_elements; ++i)
    {
        printf("Element[%d] = ", i);
        array[i] = readNumberFromInput();
    }

    *arr_length = number_of_elements;
    return array;
}

void printArray(int *array, int arr_length)
{

    printf("Length = %d\n[", arr_length);

    for (int i = 0; i < arr_length; i++)
        printf(" %d,", array[i]);

    printf("\b ]\n");
}

int *generateArray(int lower, int upper, long count)
{
    srand(time(0));
    int *array = (int *)malloc(count * sizeof(int));
    long i;
    for (i = 0; i < count; i++)
        array[i] = (rand() % (upper - lower + 1)) + lower;

    return array;
}