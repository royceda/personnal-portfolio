package tec;

abstract class PassagerAbstrait extends Passager implements Usager{

    private String nom;
    private int destination;
    private EtatPassager etat;
    private Caractere caractere;

    PassagerAbstrait(String nom, int destination, Caractere caractere) {
	this.nom = nom;
	this.destination = destination;
	etat = EtatPassager.construct();
	this.caractere = caractere;
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

    int nbRestantArret(int arret) {
	return destination - arret;
    }

    abstract void choixPlaceMontee(Bus b); 	    
    
    final public void nouvelArret(Bus bus, int numeroArret) {
	if( destination == numeroArret )
	    bus.demanderSortie(this);
	else
	    caractere.choixChangerPlace(bus, nbRestantArret(numeroArret), this);
    }
    
    final public void monterDans(Transport t) {
	Bus b = (Bus) t;
	choixPlaceMontee(b);
    }

    @Override
    public String toString() {
        return nom + " " + etat.toString();
    }
}
