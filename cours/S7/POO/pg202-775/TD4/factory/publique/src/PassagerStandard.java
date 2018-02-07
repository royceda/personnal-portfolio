package tec;

public class PassagerStandard extends Passager implements Usager{

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

    protected boolean estDehors() {
	return etat.estExterieur();
    }

    protected boolean estAssis() {
	return etat.estAssis();
    }

    protected boolean estDebout() {
	return etat.estDebout();
    }

    protected void accepterSortie() {
	etat = etat.dehors();
    }

    protected void accepterPlaceAssise() {
	etat = etat.assis();
    }

    protected void accepterPlaceDebout() {
	etat = etat.debout();
    }

    protected void nouvelArret(Bus bus, int numeroArret) {
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
