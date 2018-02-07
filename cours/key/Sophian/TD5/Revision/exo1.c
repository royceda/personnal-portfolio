#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

void nothin(int a){
  printf("signum: %d\n", a);
}



int main(){

  pid_t PID = getpid();
  sig_t S = signal(SIGALRM, nothin);
  printf("PID: %d \nSignal: %d", PID,S);
  
  alarm(10);
  if(  pause() == -1){
    perror("pause()");
    exit(1);
  }

  signal(SIGUSR1, SIG_DFL);
  



  return 0;
}
