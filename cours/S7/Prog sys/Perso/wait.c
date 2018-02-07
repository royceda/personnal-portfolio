#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(){

  int status;

  int  p = fork();
  switch(p){
  case -1:
    perror("fork() failed");
    exit(1);
    break;

  case 0:
    pause();
    break;
    
  default:
    if( waitpid(p, &status,WUNTRACED| WCONTINUED|WNOHANG)==-1){
      perror("waitpid() failed");
      exit(1);
    }

    if( WIFEXITED(status))
      printf("valeur de sortie %d\n", WEXITSTATUS(status));
    else if(WIFCONTINUED(status))
      printf("continued \n");
    else if (WIFSTOPPED(status))
      printf("stooped by signal %d\n", WSTOPSIG(status));
    else if(WIFSIGNALED(status))
      printf("tué par signal %d\n", WTERMSIG(status));
    break;
  }


  return 0;
}
