#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv){

  int proj_id = 1;
  const char *pathname = "/etc/bash.bashrc";
  key_t key = ftok(pathname, proj_id);
  if(key == -1)
    {
    perror("ftok ");
    exit(1);
    }
  size_t size = sizeof(int);
  int id =  shmget(key,size,IPC_CREAT | 0644);

  int *t = shmat(id, NULL, 0);
  if( t ==  -1)
    {
    perror("shmat ");
    exit(1);
    }
  t[0]++;
  printf(" t[0] = %d \n", t[0]);
 
  shmdt(t);
  
  if(argc > 1)
  shmctl( id, IPC_RMID , NULL);
 
  return EXIT_SUCCESS;
}
