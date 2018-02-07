#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/mman.h>



void handler(int signum){

  printf("signum: %d\n", signum);
}


int main(){

  // 1ere partie
  printf("PID: %d \n", getpid());

  int fd = open("myfile.txt", O_RDWR);
  char* buffer =  mmap(NULL, 256, PROT_READ| PROT_WRITE,MAP_SHARED, fd, 0);
 
  if( buffer == MAP_FAILED){
    perror("mmap() failed");
    exit(1);
  }

  sprintf(buffer, "%d\n", (int)getpid());
  printf("buffer: %s\n", buffer);

  //2eme partie
  
  /*
  sig_t S = signal(SIGALRM, handler);
  pause();
  signal(SIGUSR1, SIG_DFL);
  */

  struct sigaction my_action, old_action;
  my_action.sa_handler = handler;
  sigemptyset(&my_action.sa_mask);
  my_action.sa_flags = 0;

  sigaction(SIGUSR1, &my_action, &old_action);
  pause();

  sigaction(SIGUSR1, &old_action, NULL);

  munmap(buffer, 256);
  close(fd);
  return 0;
}
