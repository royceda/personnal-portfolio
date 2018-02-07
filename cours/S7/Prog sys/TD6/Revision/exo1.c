#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>


#define SIZE 4

int main(){

  key_t key = ftok("/etc/bash.bashrc",7);
  if(key == -1){
    perror("ftok()");
    exit(1);
  }

  int id = shmget(key, SIZE, IPC_CREAT|0644);
  if(id == -1){
    perror("shmget");
    exit(1);
  }

  int *A = shmat(id, NULL, 0);
  if(A == (int*)-1){
    perror("shmat");
    exit(1);
  }

  A[0]++;
  printf("A: %d\n", *A);
  shmdt(A);

  int t = shmctl(id, IPC_RMID, NULL);
  if(t == -1){
    perror("shmctl");
    exit(1);
 }


  return 0;
}
