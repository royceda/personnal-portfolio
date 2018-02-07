#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include<stdlib.h>

int main(int argc, char**argv){
  int fd,status;
  if (argc<2) return EXIT_FAILURE;

  switch(fork()){
  case -1:
    perror("fork");
    return EXIT_FAILURE;
    break;
  case 0:    
    fd=open("sortie",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if (fd==-1){ perror("sortie"); return EXIT_FAILURE;}
    if (dup2(fd,1)==-1) {perror("dup2"); return EXIT_FAILURE;}
    execvp(argv[1],argv+1);
    perror(argv[1]);
    return EXIT_FAILURE;
    break;
  }
  if (wait(&status)==-1){ perror("wait"); return EXIT_FAILURE;}
  if (WIFEXITED(status))
    printf("fils termine normalement, code de retour: %d\n",WEXITSTATUS(status));
  else{
    if (WIFSIGNALED(status))
      printf("fils termine par signal, numero de signal: %d\n",WTERMSIG(status));      
  }
  return EXIT_SUCCESS;
  
}
