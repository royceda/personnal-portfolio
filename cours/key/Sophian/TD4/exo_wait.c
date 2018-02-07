#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>       


#include <stdlib.h>       
#include <stdio.h>


int main(int argc, char **argv){
  int status;
  switch(fork()){
  case -1:
    perror("creation du processus");
    return EXIT_FAILURE;
    break;
  case 0:
    /* ((char *)0)[10]=0; */
    return EXIT_SUCCESS;
    break;
  }
  wait(&status);
  /* sleep(1000);*/
  if (WIFEXITED(status)) {
    printf("exited, status=%d\n", WEXITSTATUS(status));
  } else if (WIFSIGNALED(status)) {
    printf("killed by signal %d\n", WTERMSIG(status));
  } else if (WIFSTOPPED(status)) {
    printf("stopped by signal %d\n", WSTOPSIG(status));
  } else if (WIFCONTINUED(status)) {
    printf("continued\n");
  }

  return EXIT_SUCCESS;
}
