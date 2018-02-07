package tec;

class Sportif extends PassagerAbstrait{
        
    Sportif(String nom, int destination, Caractere carac){
	super(nom, destination, carac);
    }


    public void choixPlaceMontee(Bus b){
	if(b.aPlaceDebout())
	    b.demanderPlaceDebout(this);	    
    }
}
