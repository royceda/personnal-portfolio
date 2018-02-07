#include <stdio.h>
#include <omp.h>


int main(){

  omp_set_num_threads(14);

#pragma omp parallel
  {
    printf("bonjour: %d\n", omp_get_thread_num());
  }

  printf("au revoir\n");

  return 0;
}
