#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv){
  struct stat infos;

  if (fstat(STDIN_FILENO,&infos)==-1){
    perror("fstat");
    return EXIT_FAILURE;
  }
  if (S_ISREG(infos.st_mode))
    printf("regular file\n");
  else if (S_ISDIR(infos.st_mode))
    printf("directory\n");
  else if (S_ISCHR(infos.st_mode))
    printf("character device\n");
  else if (S_ISBLK(infos.st_mode))
    printf("block device\n");
  else if (S_ISFIFO(infos.st_mode))
    printf("FIFO (named pipe)\n");
  else if (S_ISLNK(infos.st_mode))  
    printf("symbolic link\n");
  // else if (S_ISSOCK(infos.st_mode)) 
  //printf("socket\n");
  return EXIT_SUCCESS;
}


