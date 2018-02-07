#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char *argv[]){

           struct stat sb;
           if (fstat(STDIN_FILENO, &sb) == -1) {
               perror("fstat");
               exit(EXIT_FAILURE);
           }

           printf("Type de fichier :                  ");
	   int m = sb.st_mode;

	   if(S_ISREG(m))
	     printf("fichier ordinaire \n");
	   else if(S_ISDIR(m))
	     printf("repertoire \n");
	   else if(S_ISCHR(m))
	     printf("peripherique caractere \n");
	   else if(S_ISBLK(m))
	     printf("peripherique bloc \n");
	   else if(S_ISFIFO(m))
	     printf("fifo \n");
	   else if(S_ISLNK(m))
	     printf("lien symbolique \n");
	   else if(S_ISSOCK(m))
	     printf("socket \n");

  return EXIT_SUCCESS;
}

