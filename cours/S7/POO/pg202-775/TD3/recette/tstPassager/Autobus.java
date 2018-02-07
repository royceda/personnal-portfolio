package tec;
/*
 * Classe faussaire pour les
 * tests unitaires du code
 * ecrits dans la classe PassagerStandard.
 */
public class Autobus {    
    int placesAssises;
    int placesDebout;
    final Messages messages = new Messages();
    
    Autobus(int nbPlaceAssise, int nbPlaceDebout) {
	placesAssises = nbPlaceAssise;
	placesDebout = nbPlaceDebout;
    }

    public boolean aPlaceAssise() {
	if ( placesAssises == 0 )
	    return false;
	else
	    return true;
    }

    public boolean aPlaceDebout() {
	if ( placesDebout == 0 )
	    return false;
	else
	    return true;
    }

    public void allerArretSuivant() {
	messages.add("arretSuivant");
    }

    public void demanderChangerEnAssis(PassagerStandard p) {
	messages.add("changeAssis");
    }

    public void demanderChangerEnDebout(PassagerStandard p) {
	messages.add("changeDebout");
    }

    public void demanderPlaceAssise(PassagerStandard p) {
	messages.add("entreAssis");
    }

    public void demanderPlaceDebout(PassagerStandard p) {
	messages.add("entreDebout");
    }

    public void demanderSortie(PassagerStandard p) {
	messages.add("sortir");
    }
}
