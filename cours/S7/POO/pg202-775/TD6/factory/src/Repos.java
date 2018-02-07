package tec;

class Repos extends PassagerAbstrait{
        
    Repos(String nom, int destination, Caractere carac){
	super(nom, destination, carac);
    }


    public void choixPlaceMontee(Bus b){
	if(b.aPlaceAssise())
	    b.demanderPlaceAssise(this);
	else if(b.aPlaceDebout())
	    b.demanderPlaceDebout(this);
    }    
}	




