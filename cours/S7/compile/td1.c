#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int is_char(char c)
{
  if( isdigit(c) || c == '+' || c == '*')
    return 0;
  else
    return 1;
}


char read_float (char c)
{
  char buffer[1024];
  buffer[0] = c;
  int k = 1;
  c = getchar();

  while(c != EOF && k<1024 && isdigit(c) && c !='\n')
    {
      buffer[k++] = c;
      c = getchar();
    }

  if( !isdigit(c) && c!='.')
    {
      printf("TOKEN_INT %s \n", buffer);
      return c;
    }

  if( c == '.');
    {
      buffer[k++] = c;
      c = getchar();
      while(c != EOF && k <1024 && isdigit(c))
	{
	  buffer[k++] = c;
	  c = getchar();
	}
    }

  buffer[k] = '\0';
  printf("TOKEN_FLOAT %s \n", buffer);  
  return c;
}


char read_var (char c)
{
  char buffer[1024];
  buffer[0] = c;
  int k = 1;

  if(c == 'p')
    {
      c = getchar();
      if( c == 'i')
	{
	  buffer[k++] = c;
	  c = getchar();
	  if( c == '+' || c == '*' || c == '\n')
	    {
	      printf("TOKEN_PI\n");
	      return c;
	    }
	}
    }

  
  while(c != EOF && k<1024 && c != '+' && c != '-'  && c!='\n')
    {
      buffer[k++] = c;
      c = getchar();
    }

  buffer[k] = '\0';
  printf("TOKEN_VARIABLE %s \n", buffer);
  return c;
}


char read_plus(char c)
{
  printf("TOKEN_PLUS \n");
  c = getchar();
  return c;
}


char read_mul(char c)
{
  printf("TOKEN_MUL \n");
  c = getchar();
  return c;
}






int main()
{
  char c = getchar();
 
  while(c != EOF || c != '\n')
    {
      if (c == '+') 
	c = read_plus(c);
      else if( c =='*')
	c = read_mul(c);      
      
      else if( isdigit(c))
	c = read_float(c);
      else if ( !(isdigit(c)) || c != '+' || c != '*')
	{
	  c = read_var(c);
	}
      if(c == '\n')
	exit(2);
    }

  return 0;
}
