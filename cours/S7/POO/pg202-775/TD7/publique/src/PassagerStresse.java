package tec;

final class PassagerStresse extends PassagerAbstrait{
    
    PassagerStresse(String nom, int destination, Caractere caractere){
	super(nom, destination, caractere);
    }
    
    void choixPlaceMontee(Bus b) {
	if (b.aPlaceAssise() )
	    b.demanderPlaceAssise(this);
    }

    void choixChangerPlace(Bus b, int arret) {
	if ( arret <= 3)
	    b.demanderChangerEnDebout(this);
    }
	
}
