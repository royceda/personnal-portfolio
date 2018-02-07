#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>


#define HELLO "Hello World\n"

#define NB_MAX 10000
int main(int argc, char *argv[])
{
  int taille = 0;
  int pipefd[2];
  pid_t cpid;
  char buf[500];

  /*  if (argc != 2) {
      fprintf(stderr, "Usage: %s <string>\n", argv[0]);
      exit(EXIT_FAILURE);
      }
  */
  if (pipe(pipefd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  cpid = fork();
  if (cpid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (cpid == 0) {    /* Le fils lit dans le tube */
    close(pipefd[1]); /* Fermeture du descripteur en écriture inutilisé */

    if( (taille = read(pipefd[0], &buf, 500)) > 0)
      {
	//	buf = toupper(buf);
	write(STDOUT_FILENO, &buf, taille);
      }
    write(STDOUT_FILENO, "\n", 1);
    close(pipefd[0]);
    _exit(EXIT_SUCCESS);

  } else {            /* Le père écrit argv[1] dans le tube */
    close(pipefd[0]); /* Fermeture du descripteur en lecture inutilisé*/
    for(int i =0; i<NB_MAX;i++)
      write(pipefd[1],HELLO, strlen(HELLO));
    close(pipefd[1]);          /* Le lecteur verra EOF */
    wait(NULL);                /* Attente du fils */
    exit(EXIT_SUCCESS);
  }
}
