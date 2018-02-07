from numpy import *;
from random import *;


def echange(T, i, j):
    k = T[i];
    T[i] = T[j];
    T[j] = k;



def Partition( T, a, b, k):
    p = T[k];
    echange(T, k, b);
    start = a;
    for i in range(a, b):
        if T[i] < p:
            echange(T, i, start);
            start += 1;
    echange(T, start, b);
    return start;



def QuickSort( T, a, b):
    if a<b:
        k = Partition(T, a, b, a);
        QuickSort(T, a, k-1);
        QuickSort(T, k+1, b);
    

def QuickSortRandom( T, a, b):
    if a<b:
        k = Partition(T, a, b, randint(a,b));
        QuickSort(T, a, k-1);
        QuickSort(T, k+1, b);
    

def ProdArrayRandom( n):
    T = array([randint(0,n)]);
    
    for i in range(1,n):
        T = append(T, array([randint(0,n)]));
    return T;





#test

T = array([1,3,2,7,8,98,76,33]);

print T;

QuickSortRandom( T, 0, 7);

print T;

print ProdArrayRandom(15);
