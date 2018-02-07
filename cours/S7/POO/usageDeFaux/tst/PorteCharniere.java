
/*
 * Classe faussaire pour les
 * tests unitaires du code
 * ecrit dans la classe Telecommande.
 */
class PorteCharniere {
  static final byte FERMEE   = 0;
  static final byte OUVERTE  = 1;
  byte status = FERMEE;

  final Messages messages = new Messages();

  PorteCharniere() {
  }

  PorteCharniere(byte initEtat) {
    status = initEtat;
  }

  public boolean estFerme() {
    return status == FERMEE;
  }

  public void fermer() {
    messages.add("fermer");
  }

  public void ouvrir() {
    messages.add("ouvrir");
  }
}
