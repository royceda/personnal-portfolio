#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>



#define HELLO "hello world '_'\n"
#define MAX 10000

int main(){

  
  int pipefd[2];
  pid_t cpid;
  char buf;

  
  /*
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <string>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  */


  if (pipe(pipefd) == -1) {// creation du tube
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  //Le processus  
  cpid = fork();

  if (cpid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  
  if (cpid == 0) {    /* Child reads from pipe */
    close(pipefd[1]);          /* Close unused write end */
    
    while ( read(pipefd[0], &buf, 1) > 0)
      write(STDOUT_FILENO, &buf, 1);
    
    write(STDOUT_FILENO, "\n", 1);
    close(pipefd[0]);
    _exit(EXIT_SUCCESS);
    
  } else {            /* Parent writes argv[1] to pipe */
    close(pipefd[0]);          /* Close unused read end */
    for(int i = 0; i<MAX; ++i)
      write(pipefd[1], HELLO, strlen(HELLO));
    close(pipefd[1]);          /* Reader will see EOF */
    wait(NULL);                /* Wait for child */
    exit(EXIT_SUCCESS);
  }
  
  
  


  return 0;
}
