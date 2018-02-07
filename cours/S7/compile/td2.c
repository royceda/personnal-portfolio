#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int Parse_A();
int Parse_B();
int Parse_S();


int Parse_S()
{
  switch(getchar() /*nextchar()*/)
    {
    case 'a':
      //      getchar();
      if( Parse_A() && Parse_B() && getchar() == 'b')
	return 1;
      break;
    case 'b':
      //      getchar();
      if( Parse_B() && getchar() == 'b')
	return 1;
    }
  return 0;
}

int Parse_A()
{
  switch( getchar() /*nextchar()*/)
    {
    case 'c':
      //      getchar();
      if( Parse_B() && getchar() == 'c')
	return 1;
    case 'd':
      //      getchar();
      if( getchar() == 'a')
	return 1;
    }
  return 0;
}

int Parse_B()
{
  switch( getchar() /*nextchar()*/)
    {
    case 'a':
      //      getchar();
      if( getchar() == 'a' && Parse_A() && getchar() == 'a')
	return 1;
    case 'd':
      //      getchar();
      if( Parse_A() && getchar() == 'd')
	return 1;
    }
  return 0;
}
