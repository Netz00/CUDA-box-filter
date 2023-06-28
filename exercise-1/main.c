#include "sequential.h"
#include "parallel.h"

int testArray()
{
    // Adding elements manualy
    int arr_length;
    int *array_d = readArrayFromInput(&arr_length);
    printArray(array_d, arr_length);
    free(array_d);

    // Generating elements randomly
    arr_length = 7;
    array_d = generateArray(-100, 100, arr_length);
    printArray(array_d, arr_length);
    return 0;
}

int testSequental()
{
    int arr_length = 7;
    int *array_d = generateArray(-100, 100, arr_length);

    int sum = sum_sequental(array_d, arr_length);

    printf("Sum of elements = %d\n", sum);
    free(array_d);
    return 0;
}

int testParallel()
{
    int arr_length = 7;
    int *array_d = generateArray(-100, 100, arr_length);

    int sum = sum_parallel(array_d, arr_length);

    printf("Sum of elements = %d\n", sum);
    free(array_d);
    return 0;
}

int testBenchmark(long arr_length)
{
    int *array_d = generateArray(-1000, 1000, arr_length);

    clock_t begin, end;
    double time_spent;

    // PARALLEL
    begin = clock();
    int sum_par = sum_sequental(array_d, arr_length);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed PARALLEL:\t%f seconds\n", time_spent);

    // SEQUENTAL
    begin = clock();
    int sum_seq = sum_sequental(array_d, arr_length);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Elapsed SEQUENTAL:\t%f seconds\n", time_spent);

    if (sum_seq != sum_par)
        printf("%sError: Sum miscalculation!%s\n", KRED, KNRM);

    free(array_d);
    return 0;
}

// TEST
int main()
{
    for (long i = 1; i < 10000000000; i *= 10)
    {
        printf("Array length: %ld\n", i);
        testBenchmark(i);
    }
}