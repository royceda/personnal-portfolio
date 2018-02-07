package tec;

class Fatigue extends PassagerAbstrait{
    
    Fatigue(String nom, int destination, Caractere carac){
	super(nom,destination,carac);
    }
    
    void choixPlaceMontee(Bus b) throws IllegalStateException{
	if( b.aPlaceAssise() ){
	    try{
		b.demanderPlaceAssise(this);
	    }
	    catch(IllegalStateException e){
		throw new IllegalStateException();
	    }
	}
    }
}
