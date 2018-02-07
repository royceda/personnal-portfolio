#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>


int count_signal = 0;

void count(int signum){
  count_signal++;
  printf("signum: %d\n", signum);
}



int main() {

  printf("pid: %d\n", getpid());
  struct sigaction sa;
  sa.sa_handler = count;
  
  sigemptyset(&sa.sa_mask);
  sa.sa_flags=0;
  sigaction(SIGUSR1, &sa, NULL);
  while(1){
    printf("count signal: %d \n", count_signal);
    if(pause() == -1)
      perror("pause()");
  }

  return 0;
}
