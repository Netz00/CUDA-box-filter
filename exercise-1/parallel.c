#include "parallel.h"

int sum_parallel(int *array, long arr_length)
{
   pthread_t threads[NUM_THREADS];
   // pthread_attr_t attr;
   int rc;
   long t;
   void *status;

   thread_data tdata[NUM_THREADS];
   int result = 0;

   long batch_size = arr_length / NUM_THREADS;
   int batch_reminder = arr_length % NUM_THREADS;

   long offset = 0, reminder = 0;

   // Initialize and set thread joinable
   // pthread_attr_init(&attr);
   // pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

   // printf("main(): creating threads:\n");
   for (t = 0; t < NUM_THREADS; t++)
   {
      if (batch_reminder-- > 0)
         reminder = 1;
      else
         reminder = 0;

      // printf("\tNo.%ld - range: [%d, %d>", t, offset, offset + batch_size + reminder);

      tdata[t].thread_id = t;
      tdata[t].arr_length = batch_size + reminder;
      tdata[t].array = array + offset;

      rc = pthread_create(&threads[t], NULL, thread_task, (void *)&tdata[t]);
      if (rc)
      {
         printf("\nError: unable to create thread, %d\n", rc);
         exit(-1);
      }

      offset += batch_size + reminder;
   }

   // printf("\n");

   // free attribute and wait for the other threads to finish
   // pthread_attr_destroy(&attr);
   for (t = 0; t < NUM_THREADS; t++)
   {
      rc = pthread_join(threads[t], &status);
      if (rc)
      {
         printf("Error: unable to join, %d \n", rc);
         exit(-1);
      }
      // printf("main(): completed thread id : %ld \t", t);
      // printf("exiting with status %p \t", status);
      // printf("exiting with reult %d \n", tdata[t].result);

      // Sum the batch results in the main thread
      result += tdata[t].result;
   }

   // printf("Resulting sum: %d \n", result);

   // printf("main(): completed thread id : %ld \n", t);
   /* Last thing that main() should do */
   // pthread_exit(NULL);
   return result;
}

void *thread_task(void *arg)
{
   thread_data *tdata = (thread_data *)arg;

   long sum = 0;
   for (long i = 0; i < tdata->arr_length; i++)
      sum += tdata->array[i];

   tdata->result = sum;

   // tdata->result = sum_sequental(tdata->array, tdata->arr_length);
   // printf("thread %ld exited\n", tdata->thread_id);
   pthread_exit(NULL);
}
