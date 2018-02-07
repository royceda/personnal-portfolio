#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>


void readfile(const char *pathname, int count, char *buf)
{
  int fd, byte, length = count;
  fd = open(pathname, O_RDONLY);
  if(fd == -1)
    {
      perror("open() failed");
      exit(1);
    }
  /* Read count bytes from the file */
  while ((byte = read(fd, buf, length)) != 0)
    {
      if(byte == -1)
	{
	  perror("read() failed");
	  exit(1);
	}
      length = length - byte;
      buf = buf+length;
    }
  close(fd);
}
 


int main(int argc, char *argv[])
{

  //test d'acces
  printf("acces à fichier inconnu: %d \n", access("./td89.c",F_OK));
  printf("acces à fichier existant: %d \n\n", access("./td1.c",F_OK));
  
  //creation de lien
  int res =  link("./touch1.r", "./");
  printf("link = %d\n", res);
  //suppresion de lien
  res = unlink("./touch1.r");  
  printf("unlink = %d\n", res);

  //creation de fichier
  res = creat("./touch1.r", O_CREAT);
  printf("creat = %d\n",res);
  if(res != -1)
    printf(" ->success creating\n");
  //ouverture de fichier
  res = open("touch1.r", O_RDONLY);  
  printf("open = %d\n",res);
  //fermeture d'un descripteur de fichier
  res = close(res);
  printf("close = %d\n",res);
  
  
  char *buf = malloc(25*sizeof(char*));
  readfile("./td1", 10, buf);  
  free(buf);

  return 0;
}
