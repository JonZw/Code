#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define NUM_THREADS 5

void *TaskCode (void *argument)
{
  int tid; tid = *((int *) argument);
  printf("It's me, dude! I am number %d!\n", tid);
  return NULL;
}
int main (int argc, char *argv[])
{
  pthread_t threads [NUM_THREADS];
  int thread_args [NUM_THREADS];
  int rc, i;
  for (i=0; i<NUM_THREADS; ++i) /* create all threads */
  {
    thread_args[i] = i;
    printf("In main: creating thread %d\n", i);
    rc = pthread_create( &threads[i], NULL, TaskCode,
      (void *) &thread_args[i]);
    assert(0 == rc);
  }
  /* wait for all threads to complete */
  for (i=0; i<NUM_THREADS; ++i)
  {
    rc = pthread_join (threads[i], NULL);
    assert (0 == rc);
  }
  exit(EXIT_SUCCESS);
}
