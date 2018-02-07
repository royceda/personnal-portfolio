package tec;

class PassagerStandard implements Passager, Usager{

    private String nom;
    private int destination;
    private EtatPassager etat;

    public PassagerStandard(String nom, int destination) {
	this.nom = nom;
	this.destination = destination;
	etat = EtatPassager.construct();
    }

    public String nom() {
	return nom;
    }

    public boolean estDehors() {
	return etat.estExterieur();
    }

    public boolean estAssis() {
	return etat.estAssis();
    }

    public boolean estDebout() {
	return etat.estDebout();
    }

    public void accepterSortie() {
	etat = etat.dehors();
    }

    public void accepterPlaceAssise() {
	etat = etat.assis();
    }

    public void accepterPlaceDebout() {
	etat = etat.debout();
    }

    public void nouvelArret(Bus bus, int numeroArret) {
	if( destination == numeroArret )
	    bus.demanderSortie(this);
    }

    public void monterDans(Transport t) { 
	Bus b = (Bus) t;
	if( b.aPlaceAssise() )
	    b.demanderPlaceAssise(this);
	else if( b.aPlaceDebout() )
	    b.demanderPlaceDebout(this);
    }

    @Override
    public String toString() {
        return nom + " " + etat.toString();
    }
}
