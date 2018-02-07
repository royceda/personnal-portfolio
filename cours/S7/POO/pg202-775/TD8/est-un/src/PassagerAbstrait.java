package tec;

abstract class PassagerAbstrait implements Passager, Usager{

    private String nom;
    private int destination;
    private EtatPassager etat;
    private Caractere caractere;

    PassagerAbstrait(String nom, int destination, Caractere caractere) throws RuntimeException{
	if( (destination <= 0) || nom == "" ){
	    throw new RuntimeException();
	}
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
    
    final public int nouvelArret(Bus bus, int numeroArret) throws IllegalStateException{
	int ret = 0; //Boobléen pour savoir si on a fait sortir le passager, et donc si on l'a supprimé avec remove(), pour éviter de décaler l'indice de la boucle d'allerArretSuivant()
	if( destination == numeroArret )
	    try{
		bus.demanderSortie(this);
		ret = 1; //On l'a fait sortir
	    }
	    catch(IllegalStateException e){
		throw new IllegalStateException();
	    }
	else
	    try{
		caractere.choixChangerPlace(bus, nbRestantArret(numeroArret), this);
	    }
	    catch(IllegalStateException e){
		throw new IllegalStateException();
	    }
	return ret;
    }
    
    final public void monterDans(Transport t) throws TecInvalidException{
	if( !(t instanceof Bus) ){
	    throw new TecInvalidException();
	}
	else{
	    Bus b = (Bus) t;
	    choixPlaceMontee(b);
	}
    }

    @Override
    public String toString() {
        return nom + " " + etat.toString();
    }
}
