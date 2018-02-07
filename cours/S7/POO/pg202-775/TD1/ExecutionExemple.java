
/*
 * Compilation et Exécution d'un programme java.
 * 
 * Cette classe permet de vérifier son environnement. Elle affiche une
 * chaîne de caractères sur la sortie standard.
 */
class ExecutionExemple {
  /*
   * La méthode main() sert de point d'entrée a l'exécution.
   * Chaque classe peut contenir une méthode main.
   * 
   * Pour servir de point d'entrée, elle doit respecter le
   * prototype suivant :
   */
  public static void main (String[] args) {
   /* Le mot-clé static est abordé dans le chapitre sur les classes.
    *
    * args est une variable de type référence. 
    * Elle contient la référence (l'adresse) d'un objet. 
    * Cet objet est un tableau contenant des références à des instances 
    * de la classe String (Noter la différence de syntaxe avec la déclaration 
    * d'un tableau en C).
    *
    * Comme le paramètre argv de la fonction main du langage C, 
    * les instances contenues dans ce tableau correspondent aux arguments 
    * de la ligne de commande.
    * 
    * Par contre pas de paramètre argc, un objet tableau  possède une variable 
    * publique length indiquant sa taille.
    */

    // Comme l'indique la documentation de la classe String, toutes les chaînes
    // de caractères littétales sont des instances de la classe String.
    String chaîne = "\t\t Youpi";
    final String EXCLAMATION =  " !!!!!!! ";

    System.out.println(chaîne + EXCLAMATION + "Cela marche héhé" + EXCLAMATION);
  }
}
