#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int fd = 0;
  
  if(argc>1){
    for(int i = 1; i<argc; ++i){
      size_t len = strlen(argv[i]);
      fd = write(STDOUT_FILENO, argv[i], len);
      if(fd < 0){
	perror("write1");
	return EXIT_FAILURE;
      }

      fd = write(STDOUT_FILENO, "\n", strlen("\n"));
      if(fd < 0){
	perror("write2");
	return EXIT_FAILURE;
      }
    }
  }
  else
    fd = write(STDOUT_FILENO, "pas d'argument", strlen("pas d'argument"));

  if(fd < 0){
    perror("write");
    return EXIT_FAILURE;
  }

  printf("\n");
  return 0;
}
