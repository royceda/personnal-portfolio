package tec;

class Repos extends PassagerAbstrait{
        
    Repos(String nom, int destination, Caractere carac){
	super(nom, destination, carac);
    }


    public void choixPlaceMontee(Bus b) throws IllegalStateException{
	if(b.aPlaceAssise()){
	    try{
		b.demanderPlaceAssise(this);
	    }
	    catch(IllegalStateException e){
		throw new IllegalStateException();
	    }
	}
	else if(b.aPlaceDebout()){
	    try{
		b.demanderPlaceDebout(this);
	    }
	    catch(IllegalStateException e){
		throw new IllegalStateException();
	    }
	}
    }    
}	




