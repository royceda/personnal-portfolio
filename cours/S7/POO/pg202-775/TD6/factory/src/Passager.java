package tec;

interface Passager {
  public String nom();
  boolean estDehors();
  
  boolean estAssis();
  boolean estDebout();

  void accepterSortie();
  void accepterPlaceAssise();
  void accepterPlaceDebout();

  void nouvelArret(Bus b, int numeroArret);
}
