package tec;

class Tetu extends PassagerAbstrait{
    
    Tetu(String nom, int destination, Caractere carac){
	super(nom,destination,carac);
    }
    
    void choixPlaceMontee(Bus b) throws IllegalStateException{
	try{
	    b.demanderPlaceDebout(this);
	}
	catch(IllegalStateException e){
	    throw new IllegalStateException();
	}
    }
}
