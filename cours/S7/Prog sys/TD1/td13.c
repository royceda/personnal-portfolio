#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main (int argc, char *argv[]) 
{  
  
  for(int i=0; i<argc; i++) {
    size_t len = strlen(argv[i]);
    size_t ret = write(STDOUT_FILENO ,argv[i], len);
    
    if(ret == -1) {
      perror("write");
      return EXIT_FAILURE;
    }
    else if(ret<len){
      fprintf(stderr,"%s pas ecrit en entier \n", argv[i]);
      return EXIT_FAILURE;
    }
        
  }
  return EXIT_SUCCESS;
}

    


//  test avec  ./td13 abc < . 1>&0
