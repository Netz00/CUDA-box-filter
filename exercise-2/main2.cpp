#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
// size of array
#define MAX 16

// maximum number of threads
#define MAX_THREAD 12

using namespace std;

int a[] = {1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220};
int sum[MAX_THREAD] = {0};
int part = 0;

void *sum_array(void *arg)
{

    // Each thread computes sum of 1/4th of array
    int thread_part = part++;

    for (int i = thread_part * (MAX / MAX_THREAD); i < (thread_part + 1) * (MAX / MAX_THREAD); i++)
        sum[thread_part] += a[i];

    pthread_exit(NULL);
}

// Driver Code
int main()
{

    auto start = high_resolution_clock::now(),
         stop = high_resolution_clock::now();
    chrono::microseconds duration_par, duration_seq;
    int total_sum;
    pthread_t threads[MAX_THREAD];

    // -------------- PARALLEL --------------

    start = high_resolution_clock::now();

    // Creating 4 threads
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_create(&threads[i], NULL, sum_array, (void *)NULL);
    // joining 4 threads i.e. waiting for all 4 threads to complete
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);

    // // adding sum of all 4 parts
    // total_sum = 0;
    // for (int i = 0; i < MAX_THREAD; i++)
    //     total_sum += sum[i];
    stop = high_resolution_clock::now();
    duration_par = duration_cast<microseconds>(stop - start);

    cout << "Time parallel: " << duration_par.count() << " ms" << endl;

    // -------------- SEQUENTIAL --------------

    start = high_resolution_clock::now();

    // Creating 4 threads
    for (int i = 0; i < MAX_THREAD; i++)
    {
        pthread_create(&threads[i], NULL, sum_array, (void *)NULL);
        pthread_join(threads[i], NULL);
    }

    // adding sum of all 4 parts
    stop = high_resolution_clock::now();
    duration_seq = duration_cast<microseconds>(stop - start);

    cout << "Time sequential: " << duration_seq.count() << " ms" << endl;
    cout << "sequential - parallel: " << ((duration_seq.count() - duration_par.count() < 0) ? "": "+") << duration_seq.count() - duration_par.count() << " ms" << endl;

    return 0;
}