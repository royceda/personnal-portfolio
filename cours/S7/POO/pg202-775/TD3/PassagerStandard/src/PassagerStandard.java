package tec;

public class PassagerStandard {

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

    public void nouvelArret(Autobus bus, int numeroArret) {
	if( destination == numeroArret )
	    bus.demanderSortie(this);
    }

    public void monterDans(Autobus t) { 
	if( t.aPlaceAssise() )
	    t.demanderPlaceAssise(this);
	else if( t.aPlaceDebout() )
	    t.demanderPlaceDebout(this);
    }
}
