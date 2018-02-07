Version en langage C du projet "tec". 

1) Compilation
  dans le répertoire racine:
  % make

  Cette commande lance la compilation dans le repertoire tec 
  si nécessaire.

2) Execution
  dans le répertoire racine:
  % ./simple

  Un scénario simple qui sert de test de recette.


3) Source
  Dans le répertoire tec,  vous trouverez 
   - deux fichiers sources : autobus.c et ps_standard.c 
     ps_standard correspond au comportement d'un passager lambda. 
     C'est ce comportement qu'il faut pouvoir modifier.
     
   - trois fichiers en-tête :
     + autobus.h et ps_standard.h déclarent les fonctions "publiques" 
       de tec utilisées par le client (ici simple).
     + __fonctions_internes.h déclare les fonctions "privées" de tec 
       que le client n'a pas à connaître et à utiliser.

  
