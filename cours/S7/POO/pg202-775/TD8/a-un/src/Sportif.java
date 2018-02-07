package tec;

class Sportif extends PassagerAbstrait{
        
    Sportif(String nom, int destination, Caractere carac){
	super(nom, destination, carac);
    }


    public void choixPlaceMontee(Bus b) throws IllegalStateException{
	if(b.aPlaceDebout()){
	    try{
		b.demanderPlaceDebout(this);
	    }
	    catch(IllegalStateException e){
		throw new IllegalStateException();
	    }
	}
    }
}
