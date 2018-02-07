from numpy import *;
from random import *;
from matplotlib.pyplot import *;


def Deb():
    k = 0;
    X = 0;
    Y = 1;
    while( X != Y):
        X = randint(0,1);
        Y = randint(0,1);
        k = k+1;
    return X,k;



print Deb();
print Deb();
        

def Average(T):
    sum = 0;
    for i in range(0,len(T)-1):
        sum += T[i];
    return sum/len(T);

        
def test():
    K = array([0])
    for i in range(1,100):
        T = Deb();
        K = append(K, array([T[1]]));
    X = arange(0,100,1)    
    print "Nombre moyen d'appels\n"
    print Average(K);
    plot(X,K);
    show();




print test();    
    
