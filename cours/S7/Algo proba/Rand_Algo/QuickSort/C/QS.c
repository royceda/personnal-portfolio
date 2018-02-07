#include <stdio.h>
#include <stdlib.h>


int rand_int(int a, int b)
{

  return rand()%(b-a) + a;

}




void echange(int T[], int i, int j)
{
  int k = T[j];
  T[j] = T[i];
  T[i] = k;
}


int Partition(int T[], int a, int b, int k)
{
  int p = T[k];
  echange(T, k, b);
  int start = a;
  for(int i = a; i<b; i++)
    {
      if (T[i]<p)
	{
	  echange(T,i,start);
	  start++;
	}
    }
  echange(T, start, b);
  return start;
}



void QuickSort(int T[], int a, int b)
{
  if(a<b)
    {
      int k = Partition(T, a, b, a);
      QuickSort(T,a,k-1);
      QuickSort(T,k+1,b);
    }
	
}


void RandomQuickSort(int T[], int a, int b)
{
  if(a<b)
    {
      int p = rand_int(a,b);
      int k = Partition(T, a, b, p);
      QuickSort(T,a,k-1);
      QuickSort(T,k+1,b);
    }
}

int main()
{
  int T[12] = {3, 4, 1, 4, 5, 6, 7, 8, 76, 9, 54, 13};
  
  //QuickSort(T,0,11);
  RandomQuickSort(T,0,11);

 
  return 0;
}
