#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

int main(int argc, char *argv[]){
  ssize_t retour;
  int i;
  size_t len;
  
  for(i = 1;i <argc; i++)
    {
      len = strlen(argv[i]);
      retour = write(STDOUT_FILENO, argc[i],len);
      if(retour == -1){
	perror("write");
	return EXIT_FAILURE;
      }
      else if (retour != len ){
	frpintf(stderr, "²s n'a pas ete ecrit en entier \n",argv[i]);
	return EXIT_FAILURE;
      }
    }
  return EXIT_SUCCESS;
}




/*
int main(int argc, char **argv)
{
  int i = 1;
  const void *buf = argv[i];
  int count = strlen(buf);
  while(argc > 1)
    {
      write(STDOUT_FILENO, buf,count);
      argc--;
      i++;
      buf = argv[i];
      count = strlen(buf);
    }
  return EXIT_SUCCESS;
}
