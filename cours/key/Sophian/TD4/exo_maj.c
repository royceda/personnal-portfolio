#include <unistd.h>

#include <ctype.h>
#include <stdlib.h>       
#include <stdio.h>     
#include <string.h>

#define READ_MAX 500

int main(int argc, char **argv){
  int pipe_fd[2];
  char buffer[READ_MAX];
  size_t i;
  ssize_t r;
  
  if (pipe(pipe_fd)==-1) { perror("creation du tube"); return EXIT_FAILURE;} 

  switch(fork()){
  case -1:
    perror("creation du fils"); return EXIT_FAILURE; 
    break;
  case 0:
    /* FILS */
    close(pipe_fd[1]);
    /* lecture depuis le tube */
    r=1;
    while(r!=0){
      r=read(pipe_fd[0],buffer,READ_MAX);
      if (r==-1) 
	{ perror("fils depuis tube"); return EXIT_FAILURE; }
      if (r>0){
	for(i=0;i<r;i++) buffer[i]=toupper(buffer[i]);
	if (write(1,buffer,r)==-1) /* bof */
	  {perror("fils sur stdout"); return EXIT_FAILURE;}
      }
    }
    return EXIT_SUCCESS;
    break;
  }
  /* pere */
  close(pipe_fd[0]); 
  if (dup2(pipe_fd[1],1)==-1){perror("pere dup2"); return EXIT_FAILURE;}  
  close(pipe_fd[1]); 
  execlp("ps","ps",NULL);
  return EXIT_SUCCESS;
}
