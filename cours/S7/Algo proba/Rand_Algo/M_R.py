from numpy import *;
from random import *;



def Miller_Rabin(n):
    r = n;
    s = 0;
    while( n%2 != 0):
        r = r/2;
        s = s+1;
    a = randint(1,n-1);
    x = pow(a,n)%n;
    if (n == 1 || x == n-1):
        return T;
    j = 1;
    while( j<s && y != n-1):
        y = y*y%n;
        j = j+1;
        if y = 1:
            return composer;
    return Premier;
        
    
    
    
