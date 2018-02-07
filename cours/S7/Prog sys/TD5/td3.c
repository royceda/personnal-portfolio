#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>

#include <fcntl.h>



int main()
{
  int *p = mamp(NULL, sizeof(int), PROT, MAP_PRIVATE|MAP_ANON,-1,0); //gcc -DPROT
  fprintf(stderr,"%p\n", p);
  fprintf(stderr, "%d \n", *p);
  *p = 42;
  fprintf(stderr, "%d \n", *p);
  return 0;
}
