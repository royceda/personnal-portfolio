/*Classe faussaire PassagerStandard
 *pour le fichier
 *Autobus.java
 */

package tec;

class FauxPassager implements Passager, Usager{
    static final int ASSIS = 0;
    static final int DEBOUT = 1;
    static final int DEHORS = 2;
    int status = DEHORS;

    final Messages messages = new Messages();

    public FauxPassager() {
    }
    
    public FauxPassager(int initEtat) {
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

    public int nouvelArret(Bus bus, int numeroArret) {
	messages.add("nouvelArret");
	return 0;
    }

    public void monterDans(Transport bus) {
	messages.add("monterDans");
    }
}
