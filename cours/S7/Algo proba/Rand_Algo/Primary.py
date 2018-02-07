from numpy import *;
from random import *;

def impaire(n):
    if n%2 == 0:
        return 0;
    return 1;


def binary_rep(n):
    d = n;

    if impaire(d):
        T = array(1);
    else:
        T = array(0);
    i = 1;
    while(d != 1):
        d = d/2;
        if impaire(d):
            T = append(T,1);
        else:
            T = append(T,0);
        i = i+1;
    return T;    
    
            
print binary_rep(250);    

def exp_modulaire(a, b, n):
    c = 0;
    d = 1;
    B = binary_rep(b);
    k = len(B)-1;
    while k >= 0:
        c = 2*c;
        d = d*d % n;
        if B[k] == 1:
            c = c+1;
            d = d*a % n;
        k = k-1;
    return d;

print exp_modulaire(5,3,13);
print exp_modulaire(4,13,497);

def pseudo_premier(n):
    assert n >= 2
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    if exp_modulaire(2, n-1, n) != 1:
        return False;
    else:
        return True;

print pseudo_premier(3);
print pseudo_premier(257);
print pseudo_premier(18);



def try_composite(a,n):
    if pow(a, n-1, n) == 1:
        return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n-1:
                return False
    return True # n is definitely composite
                
print try_composite(257, 2);
print try_composite(255, 2);

def temoin(a, n):
    x = exp_modulaire(a, u, n);
    #la decompo
    P = array(x);
    for i in range (1,t):
        x = x**2%n;
        P = append(P,x);
        if P[i] == 1 & P[i-1] != 1 & P[i-1] != n-1:
            return True;
    if P[i] != 1:
        return True;
    return False;

    

def Miller_Rabin(n, s):
    assert n >= 2
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    for i in range(1, s):
        a = randint(1, n-1);
        if temoin(a, n) == 1:
            return False;
        else:
            return True;
    
