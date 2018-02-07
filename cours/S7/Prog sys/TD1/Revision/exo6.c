#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>


#define BUFSIZE 10


int main() {

  char *buffer[BUFSIZE];

  int fd = 0;
  ssize_t rd;
  while(1){
    rd = read(STDIN_FILENO, buffer, BUFSIZE);
    fd = write(STDOUT_FILENO, buffer, rd);
    
    if(fd < 0){
      perror("write1");
      return EXIT_FAILURE;
    }
    if(rd < BUFSIZE);
  } 
    
  
 
  
  
  printf("\n");
  return 0;
}
