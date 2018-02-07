package tec;

final class PassagerStandard extends PassagerAbstrait{

    PassagerStandard(String nom, int destination) {
	super(nom, destination, Calme.getInstance());
    }

    void choixChangerPlace(Bus b, int arret) {
    }

    void choixPlaceMontee(Bus b) {
	if (b.aPlaceAssise() )
	    b.demanderPlaceAssise(this);
	else if (b.aPlaceDebout() )
	    b.demanderPlaceDebout(this);
    }	
}
