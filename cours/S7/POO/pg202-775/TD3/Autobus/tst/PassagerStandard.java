/*Classe faussaire PassagerStandard
 *pour le fichier
 *Autobus.java
 */

package tec;

public class PassagerStandard {
    static final int ASSIS = 0;
    static final int DEBOUT = 1;
    static final int DEHORS = 2;
    int status = DEHORS;

    final Messages messages = new Messages();

  public PassagerStandard() {
  }
    
  public PassagerStandard(int initEtat) {
      status = initEtat;
  }

  public String nom() {
    return null;
  }

  public boolean estDehors() {
    return status == DEHORS;
  }

  public boolean estAssis() {
      return status == ASSIS;
  }

  public boolean estDebout() {
    return status == DEBOUT;
  }

  public void accepterSortie() {
      messages.add("accepterSortie");
  }

  public void accepterPlaceAssise() {
      messages.add("accepterPlaceAssise");
  }

  public void accepterPlaceDebout() {
      messages.add("accepterPlaceDebout");
  }

  public void nouvelArret(Autobus bus, int numeroArret) {
      messages.add("nouvelArret");
  }

  public void monterDans(Autobus t) {
      messages.add("monterDans");
  }
}
