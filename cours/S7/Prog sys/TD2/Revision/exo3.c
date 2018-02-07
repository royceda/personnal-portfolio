#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <dirent.h>

#define SIZE 10



int main(){

  char buf[256];
  DIR *rep = opendir("../../");
  
  struct dirrent *cont = NULL;
  cont = readdir(rep);
  while(cont != NULL){
    strcpy(buf, cont->d_name);
    printf("%s \n", buf);
    cont = readdir(rep);

  }


  /*
  struct stat *buf;
  stat("./", buf);
    
  mode_t m = buf->st_mode;
  if(S_ISDIR(m))
    //d
  else if(S_ISREG(m))
    //.
  else if(S_ISLNK(m))
    //l
    */


  closedir(rep);

  return 0;
}
