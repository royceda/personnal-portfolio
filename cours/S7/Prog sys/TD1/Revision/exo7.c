#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>



#define BUFSIZE 10


int main() {
  struct stat *buf = malloc(sizeof(struct stat));  
  int stat = fstat( STDIN_FILENO, buf);
  
  switch(stat) {
  case -1:
    perror("stat");
    return EXIT_FAILURE;
    break;
    
  case EACCES:
    printf("probleme de permission\n");
    break;
    
  case ENOENT:
    printf("chemin inexistant\n");
    break;

  case ELOOP:
    printf("trop de lien symbolique");
    break;
  }
  
  mode_t m = buf->st_mode;

  if(S_ISREG(m))
    printf("fichier normal");
  else if(S_ISDIR(m))
    printf("repertoire");
  else if(S_ISCHR(m))
    printf("device de type caractere");
  else if(S_ISBLK(m))
    printf("device de type bloc");
  else if(S_ISFIFO(m))
    printf("fifo");
  /*
  else if(S_ISLNK(m))
    printf("link: lin symbolique");
  else if(S_ISSOCK(m))
    printf("socket");
  */
  free(buf);
  printf("\n");
  return 0;
}
