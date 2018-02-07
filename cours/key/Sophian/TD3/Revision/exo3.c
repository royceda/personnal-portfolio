#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>





int main(){

  pid_t p = fork();
  switch(p){
  case -1:
    perror("fork() failed");
    break;
    
  case 0:
    printf("_on est dans le  pere de PID:%d\n", getpid());
    break;

  default:
    printf("_on est dans le fils de PID:%d \n et dont le pere est PID:%d\n",p, getppid());
    break;
  }

  return 0;
}
