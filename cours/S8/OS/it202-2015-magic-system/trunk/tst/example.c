#include "thread.h"
#include <stdio.h>
#include <assert.h>

//faire des get time of date dans les tests

static void * threadfunc(void * arg)
{
  char *name = arg;
  fprintf(stderr, "je suis le thread %p, lancé avec l'argument %s\n",
	 (void*) thread_self(), name);
  thread_yield();
  fprintf(stderr, "je suis encore le thread %p, lancé avec l'argument %s\n",
	 (void*) thread_self(), name);
  thread_exit(arg);
}

int main()
{
  thread_t thread1, thread2;
  void *retval1, *retval2;
  int err;

  fprintf(stderr, "le main lance 2 threads...\n");
  err = thread_create(&thread1, threadfunc, "thread1");
  assert(!err);
  fprintf(stderr, "le main lance le 2eme threads...\n");
  err = thread_create(&thread2, threadfunc, "thread2");
  assert(!err);
  printf("le main a lancé les threads %p et %p\n",
	 (void*) thread1, (void*) thread2);

  printf("le main attend les threads\n");
  err = thread_join(thread2, &retval2);
  assert(!err);
  fprintf(stderr, "le main lance le 2eme threads...\n");
  err = thread_join(thread1, &retval1);
  assert(!err);
  printf("les threads ont terminé en renvoyant '%s' and '%s'\n",
	 (char *) retval1, (char *) retval2);

  return 0;
}

