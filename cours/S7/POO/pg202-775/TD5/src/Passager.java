package tec;

interface Passager extends Usager{
  public String nom();
  boolean estDehors();
  
  boolean estAssis();
  boolean estDebout();

  void accepterSortie();
  void accepterPlaceAssise();
  void accepterPlaceDebout();

  void nouvelArret(Bus b, int numeroArret);
}
