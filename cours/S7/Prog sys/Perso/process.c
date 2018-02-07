#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>


pid_t create_pid() {
  
  pid_t P;
  do{
    P = fork();
    
  }while( (P == -1) && (errno = EAGAIN));
  
  printf("PID de create_pid(): %d \n", (int)getpid());
  return P;
}


int main() {

  pid_t P = create_pid();
  getpid();

  switch(P){
  default:
    printf("processus pere. fils de pid %d\n", (int)P);
    if( wait(NULL) == -1) {
      perror("wait()");
      exit(1);
    }
    break;

  case -1:
    perror("creation de processus \n");
    exit(1);
    break;

  case 0:
    printf("processus fils: %d de parent: %d \n", (int)getpid(), (int)getppid());
    break;
    
  }

  return 0;

}
