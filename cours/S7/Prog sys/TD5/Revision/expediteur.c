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




int main(){

  int fd = open("myfile.txt", O_RDWR);
  char* buffer =  mmap(NULL, 256, PROT_READ| PROT_WRITE,MAP_SHARED, fd, 0);
  char b[12];

  read(fd, b,6);

  printf("char: %s \n", b);


  munmap(buffer,256);
  close(fd);
  return 0;
}
