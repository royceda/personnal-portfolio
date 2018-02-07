#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <sys/types.h>



#define SIZE  4

int main() {
 
  key_t k = ftok("/etc/bashrc",1);
  int n = shmget(k, SIZE, 0644|IPC_CREAT );
  
  if (n<0) {
    perror("shmget");
    exit(EXIT_FAILURE);
  }

  int *A = shmat(n, NULL, 0);
  if(A == (int*)-1) {
    perror("shmat");
    exit(EXIT_FAILURE);
  }
  
  A[0]++;
  printf("%d \n", A[0]);
  shmdt(A);
  shmctl(n, IPC_RMID, NULL);
  
  
  return EXIT_SUCCESS;
}




