#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main() {

  long essai = 5;
  int fd = 0;
  fd = write(STDOUT_FILENO, &essai, sizeof(essai));
    
  if(fd < 0){
    perror("write1");
    return EXIT_FAILURE;
  }
  
  int ret = write(STDOUT_FILENO, &fd, sizeof(fd));
  
  if(ret < 0){
    perror("write1");
    return EXIT_FAILURE;
  }   
  
  printf("\n");
  return 0;
}
