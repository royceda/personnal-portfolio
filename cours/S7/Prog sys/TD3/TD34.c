#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{

  /*
   * argv[0] = "a";
   * argv[1] = "b";
   * argv[0] = NULL;

   int status;
   utiliser wait(&status) ou waitpid()
   */


  fork();
  int i;
  printf(argv[2], &argv[2]);

  for(i = 3; i<argc; i++)
    {
      printf(" ard %d = %s \n", i, argv[i]);
      execvp(argv[2], argv);
    }


  //Part 3
  int fd;
  fd = open(argv[1], O_RDWR| O_CREAT, 0644);
  if(fd < 0)
    //....error
  else
    if (dup2(fd,1) < 0)
      //...
      execvp(argv[2],&argv[2]);


  //part 4

  int status;
  if(wait(&status) < 0)
    //...
    if( WIFEXITED(status))
      printf("fils ok \n");
    else if(WITSIGNALED(status))
      //...

  /* $ lance toto echo toto */
      //waitpid(pid, &status, 0);

  return 0;
}
