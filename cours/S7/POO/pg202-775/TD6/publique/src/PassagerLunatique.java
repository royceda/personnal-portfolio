package tec;

final class PassagerLunatique extends PassagerAbstrait{

    PassagerLunatique(String nom, int destination, Caractere caractere){
	super(nom, destination, caractere);
    }
 
    public void choixChangerPlace(Bus bus, int numeroArret, Passager p) {
	if( this.estAssis() )                   
	    bus.demanderChangerEnDebout(this);
	else
	    bus.demanderChangerEnAssis(this);
    }

    public void choixPlaceMontee(Bus b) { 
	if( b.aPlaceDebout() )
	    b.demanderPlaceDebout(this);
    }
}
