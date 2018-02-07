#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  struct timeval tv[2];
  unsigned long us;
  unsigned i;
  long s_us = 0;


#pragma omp parallel
  {
  while(1){
    gettimeofday(&tv[0], NULL);



    for(i=0; i<1000000; i++) {
      gettimeofday(&tv[1], NULL);
    }
    us = (tv[1].tv_sec-tv[0].tv_sec)*1000000+(tv[1].tv_usec-tv[0].tv_usec);

    s_us += us;
    if(s_us > 4000000){
      sleep(4);
      s_us = 0;
      //break;
    }
    printf("1000000 gettimeofday took %ldus\n", us);
    //int us2 = (int)us/1000000;
    //printf("\n en sec: %d\n", us2);
    
    //sleep((int)us*40/100);
  }
  }
  return 0;
}
