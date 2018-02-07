// Exemple du cours de la partie Encapsulation

class Telecommande {
  private PorteCharniere[] mesPortes;
  private int nbPortes;
  
  public Telecommande(int nbBouton) {
    mesPortes = new PorteCharniere[nbBouton];
    nbPortes = 0;
  }

  public void positionner(PorteCharniere p) {
    if (nbPortes < mesPortes.length) {
	mesPortes[nbPortes] = p;
	nbPortes++;
    }
  }

  public void activer(int numero) {
    mesPortes[numero-1].ouvrir();
  }

  public void desactiver(int numero) {
    mesPortes[numero-1].fermer();
  }

  public void desactiver() {
    for (int i = 1; i <= nbPortes; i++)
      if (!mesPortes[i-1].estFerme())
	mesPortes[i-1].fermer();
  }
}
