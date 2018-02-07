package tec;

abstract class Passager {
  abstract public String nom();

  abstract protected boolean estDehors();  
  abstract protected boolean estAssis();
  abstract protected boolean estDebout();

  abstract protected void accepterSortie();
  abstract protected void accepterPlaceAssise();
  abstract protected void accepterPlaceDebout();

  abstract protected void nouvelArret(Bus b, int numeroArret);
}
