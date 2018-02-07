#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define BUFSIZE 200

int main(int argc, char *argv[]) {
  while(1) {
    char buf[BUFSIZE];
    size_t wrote;
    ssize_t read = read(STDIN_FILENO, &buf, BUFSIZE);

    wrote = write(STDOUT_FILENO, &buf, read);
    if(read<BUFSIZE)
      break;
  }

  return EXIT_SUCCESS;
}
    
