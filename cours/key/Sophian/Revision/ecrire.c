#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char **argv){
  int i, fd;
  fd=open(argv[1],O_WRONLY);
  for(i=atoi(argv[2]);i<10;i+=2){
    lseek(fd,i*sizeof(int),SEEK_SET);
    write(fd,&i,sizeof(int));
  }
  close(fd);
  exit(EXIT_SUCCESS);
}
