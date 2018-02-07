#include <stdio.h>
#include <stdlib.h>

//#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>

#define SIZE 255
#define CUR "./"


int main (int argc, char** argv) 
{
  struct dirent * dcontent;
  DIR* d = NULL; 
  ino_t ino;
  d = opendir(CUR);
  if(d != NULL){
    dcontent = readdir(d);
    while(dcontent != NULL)
      {
	printf("%s\n", dcontent->d_name);
	dcontent = dcontent->d_off;
      }
    closedir(CUR);
  }
  else
    return EXIT_FAILURE;
      
  return EXIT_SUCCESS;
}
