package tec;
/*
 * Classe faussaire pour les
 * tests unitaires du code
 * ecrits dans la classe PassagerStandard.
 */
class FauxBus implements Bus, Transport{    
    int placesAssises;
    int placesDebout;
    final Messages messages = new Messages();
    
    FauxBus(int nbPlaceAssise, int nbPlaceDebout) {
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

    public void demanderChangerEnAssis(Passager p) {
	messages.add("changeAssis");
    }

    public void demanderChangerEnDebout(Passager p) {
	messages.add("changeDebout");
    }

    public void demanderPlaceAssise(Passager p) {
	messages.add("entreAssis");
    }

    public void demanderPlaceDebout(Passager p) {
	messages.add("entreDebout");
    }

    public void demanderSortie(Passager p) {
	messages.add("sortir");
    }
}
