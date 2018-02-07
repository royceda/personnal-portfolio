#include <stdio.h>
#include <semaphore.h>
#include <errno.h>



#define BUFFSIZE 200

char *buff[BUFFSIZE];

int pipefd[2];
pipe( pipefd);



/*le socket deviens un pipe et received_count est le nombre d'octet qu'on consomme par etape     */

void wakeup(int length)
{
  irq_disable();

  received_count += length;

  while (sleepq && length > 0) {
    struct proc * myproc = sleepq;
    sleepq = myproc->p_next;
    myproc->p_stat = STATUS_READY;
    myproc->p_next = runq;
    int given = min(length, myproc->p_waitlength)
    length -= given;
    runq = myproc;
  }
  irq_enable();
}


void wait(int length)
{
  while (length) {
    irq_disable();
    /* tant qu'on peut lire, on lit */
    if (receive_count) {
      int consumed = min(received_count, length);
      /* on lit ce qu'on peut */
      received_count -= consumed;
      irq_enable();
      consume(consumed);
      length -= consumed;
    } else {
      /* plus rien a lire, il faut dormir */
      current->p_stat = STATUS_BLOCKED;
      current->p_next = sleepq;
      sleepq = current;
      irq_enable();
      switch();
      /* quelqu'un nous a reveille, mais on s'est peut-etre fait piquer notre paquet par un autre processus entre temps */
    }
  }
}



void consume(int length){

  close( pipefd[0]);
  read(pipefd[1], buff, length);

}


int main(){





  sem_t *S;
  int r = sem_init(S, 0, 0);
  if(r < 0)
    perror("sem_init");
  r = sem_post(S);
  r = sem_wait(S);


  return 0;
}

