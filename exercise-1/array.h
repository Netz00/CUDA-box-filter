#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define KRED "\x1B[31m"
#define KNRM "\x1B[0m"
#define flushStdin                                  \
    {                                               \
        char c;                                     \
        while ((c = getchar()) != '\n' && c != EOF) \
            ;                                       \
    }

int readNumberFromInput();
int *readArrayFromInput(int *);

int *generateArray(int, int, long);

void printArray(int *, int);