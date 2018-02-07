#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/wait.h>
#include <unistd.h>

int
main(int argc, char *argv[]) {
    int fds[2];
    int in_next = STDIN_FILENO;
    pid_t pid_enfant;
    pid_t pid;
    int status,i;

    
    char *ls[]={"ls","-l",NULL};
    char *tr[]={"tr","-d","[:blank:]",NULL};    
    char **commandes[]={ls,tr};
    int nb_commandes=sizeof commandes/sizeof(char*);

    for (i=0;i<nb_commandes;i++) {
      fds[0]=fds[1]=-1;

      if (i<nb_commandes-1) {
	/* On n'est pas le dernier processus du pipeline */
	if (pipe(fds) == -1) {
	  perror("pipe");
	  exit(EXIT_FAILURE);
	}
      }
      
      pid_enfant = fork();
      switch (pid_enfant) {
      case -1:
	perror("fork");
	exit(EXIT_FAILURE);
      case 0:
	/* enfant */
	if (in_next != STDIN_FILENO) {
	  /* On n'est pas le premier processus du pipeline */
	  dup2(in_next,STDIN_FILENO);
	  close(in_next);
	}

	if (fds[0]!=-1){
	  /* On n'est pas le dernier processus du pipeline */
	  dup2(fds[1],STDOUT_FILENO);
	  close(fds[0]);
	  close(fds[1]);
	}	
	execvp(commandes[i][0],commandes[i]);
	perror("execvp");
	exit(EXIT_FAILURE);
      }
      /* parent */
      if (in_next != STDIN_FILENO)
	close(in_next);
      if (fds[0]!=-1){
	close(fds[1]);
	in_next = fds[0];
      }
    }
    
    /* On attend le bon enfant */
    do {
      pid = wait(&status);
      if (pid == -1) {
	perror("wait");
	exit(EXIT_FAILURE);
      }
    } while (pid != pid_enfant);
    
    if (WIFEXITED(status))
      return WEXITSTATUS(status);
    else {
      if (WIFSIGNALED(status))
	fprintf(stderr, "Signal %d\n", WTERMSIG(status));
      
      return EXIT_FAILURE;
    }
}
