package tec;

interface Passager {
  public String nom();
  boolean estDehors();
  
  boolean estAssis();
  boolean estDebout();

  void accepterSortie();
  void accepterPlaceAssise();
  void accepterPlaceDebout();

  int nouvelArret(Bus b, int numeroArret);//Le int sert à savoir si on a fait sortir un passager
}
