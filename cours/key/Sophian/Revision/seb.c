#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#define READ_MAX 1024

int verif(char *ligne){
  char verif[7];
  verif[6] = '\0';
  int i =0;
  while (i != (strlen(ligne)-6)){
    for(int j = 0; j<6; j++)
      verif[j] = ligne[i+j];
    if (strcmp(verif,"coucou") == 0)
      return 1;
    i++;
  }
  return 0;
}


int main(int argc, char **argv)
{
  FILE *fd = fopen("toto.txt","r");
  char *buf = malloc(READ_MAX);
  int compteur=0;
  int c;
  while(fgets(buf,READ_MAX,fd) != '\0')
    {
      c = 0;
      if(verif(buf)){
	compteur++;
	while(buf[c] != '\0'){
	  if ((buf[c] == ' ') && (buf[c+1] != ' '))
	    compteur++;
	  c++;
	}
      }
      
    }
  printf("%d\n",compteur);
  return EXIT_SUCCESS;
}
	 
