package tec;

class Fatigue extends PassagerAbstrait{
    
    Fatigue(String nom, int destination, Caractere carac){
	super(nom,destination,carac);
    }
    
    void choixPlaceMontee(Bus b){
	if( b.aPlaceAssise() )
	    b.demanderPlaceAssise(this);
    }
}
