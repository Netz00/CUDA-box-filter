#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "array.h"

#define NUM_THREADS 4

typedef struct thread_data
{
   long thread_id;
   int *array;
   long arr_length;
   long result;
} thread_data;

void *thread_task(void *);
int sum_parallel(int *, long);