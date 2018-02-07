#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>

#include <fcntl.h>

#define SIZE 128


int main() {
  
  char *buffer;
  int fd;
  fd = open("toto", O_RDWR);
  if(fd<0)
    {
      perror("open");
      return EXIT_FAILURE;
    }
  buffer = mmap(NULL, 128,  PROT_READ|PROT_WRITE, MAP_SHARED,fd,0);
  
  if(buffer == MAP_FAILED)
    {
      perror("mmap");
      exit(EXIT_FAILURE);
    }
  buffer[0] = 'a';
  buffer[127] = 'b';
  munmap(buffer, SIZE);
  close(fd);
  

  //2eme partie

  pid_t pid = getpid();
  memcpy(buffer, &pid, sizeof(pid));
  
  struct sigaction sa;
  sa.sa_handler = handler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  sigaction(SIGUSR1, &sa, NULL);
  sigset_t set;
  sigfill set(&set);
  sigdelset(&set, sigusr1);
  sigsuspend(&set);
  printf("buffer %s \n", buffer);


  fd= ;
  buffer=;
  pid_t pid;
  memcpy(&pid, buffer, sizeof(pid));
  ssize_t linesize;
  char line[128];
  size_t offset = 0;
  while((linesizerend(STDIN_FILENO, line,sizeof(line))>0)
	memcpy(buffer+offset, line,  linesize);
	offset += linesize;
	buffer[linesize] = '\0';
	

  kill(pid,SIGUSR1);

}

