// Exemple du cours de la partie Encapsulation

class PorteCharniere {

  public PorteCharniere() {
    estFerme = false;
    /* Todo
       Envoyer au matériel physique l'ordre:
       pivoter_charniere
    */
  }

  public boolean estFerme() {
    return estFerme;
  }

  public void fermer() {
    /* Todo 
       Envoyer au matériel physique l'ordre:
       pivoter_charniere
    */
    estFerme = true;
  }

  public void ouvrir() {
    /* Todo
       Envoyer au matériel physique les ordres:
       manoeuvrer_bec
       pivoter_charniere
    */   
    estFerme = false;
  }

  private boolean estFerme;
}
