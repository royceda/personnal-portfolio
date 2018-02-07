package tec;

final class PassagerStresse extends PassagerAbstrait{
    
    PassagerStresse(String nom, int destination){
	super(nom, destination);
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
