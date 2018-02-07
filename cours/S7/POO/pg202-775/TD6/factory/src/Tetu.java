package tec;

class Tetu extends PassagerAbstrait{
    
    Tetu(String nom, int destination, Caractere carac){
	super(nom,destination,carac);
    }
    
    void choixPlaceMontee(Bus b){
	b.demanderPlaceDebout(this);
    }
}
