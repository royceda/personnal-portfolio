#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define READ_MAX 4000

int main(int argc, char **argv){
  
  //int fdf = open("FIFO",O_WRONLY);
  int fdo = open("output",O_WRONLY);
  int size;
  char *buf = malloc(4000);
  read(0,buf,READ_MAX);
  size = strlen(buf);
  write(fdo,buf,size);
  //write(fdf,buf,size);
  close(fdo);
  free(buf);
  return EXIT_SUCCESS;
}
