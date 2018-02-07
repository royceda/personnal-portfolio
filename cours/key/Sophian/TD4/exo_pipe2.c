#include <unistd.h>

#include <stdlib.h>       
#include <stdio.h>     
#include <string.h>

#define READ_MAX 500
#define NB_WRITE 100000

int main(int argc, char **argv){
  int pipe_fd[2],n;
  char buffer[READ_MAX];
  const char *message="Hello World";
  size_t msg_len=strlen(message),c;
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
    r=read(pipe_fd[0],buffer,READ_MAX);
    if (r==-1) 
      { perror("fils depuis tube"); return EXIT_FAILURE; }
    if (r>0)
      if (write(1,buffer,r)==-1)
	{perror("fils sur stdout"); return EXIT_FAILURE;}
    return EXIT_SUCCESS;
    break;
  }
  /* pere */
  close(pipe_fd[0]); /* MODIF ICI */
  for(n=0;n<NB_WRITE;n++){
    c=0;
    while(c<msg_len){
      r=write(pipe_fd[1],message+c,msg_len-c);
      if (r==-1){ perror("pere sur pipe"); return EXIT_FAILURE;}
      c+=r;
    }
  }
  return EXIT_SUCCESS;
}
