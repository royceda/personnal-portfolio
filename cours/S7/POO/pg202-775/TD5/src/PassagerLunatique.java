package tec;

final class PassagerLunatique extends PassagerAbstrait{

    PassagerLunatique(String nom, int destination){
	super(nom, destination);
    }
 
    public void choixChangerPlace(Bus bus, int numeroArret) {
	if( this.estAssis() )                   
	    bus.demanderChangerEnDebout(this);
	else
	    bus.demanderChangerEnAssis(this);
    }

    public void choixPlaceMontee(Bus b) { 
	if( b.aPlaceDebout() )                // Le if ici n'est-il pas redondant pour une version finalisé du code ?
	    b.demanderPlaceDebout(this);
    }
}
