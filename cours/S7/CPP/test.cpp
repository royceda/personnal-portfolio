#include <cstdio>

//using std;

int main(){

  int n =99;
  try{
    if (n>3 && n<100)
      throw 2;
    else if (n>100)
      throw 1;
    else 
      throw 1.123;
    
  }
  catch(int a ){
    if (a == 1)
      printf("catché !!!!\n");
    else if (a == 2)
      {
	printf("on a catch une pute\n"); 
	try{
	  throw 'a';
	}
	catch(...){
	  printf("ta catch une salope\n");
	}
      }
  }
  catch(...){
    printf("default\n");
  }
  return 0;
}
