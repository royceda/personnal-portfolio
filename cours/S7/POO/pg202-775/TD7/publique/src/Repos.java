package tec;

public class Repos extends PassagerAbstrait{
        
    Repos(String nom, int destination, Caractere carac){
	super(nom, destination, carac);
    }

    public static Usager fairePassagerReposPrudent(String nom, int arret) {
	return new Repos(nom, arret, Prudent.getInstance());
    }
    
    public static Usager fairePassagerReposAgoraphobe(String nom, int arret) {
	return new Repos(nom, arret, Agoraphobe.getInstance());
    }
    
    public static Usager fairePassagerReposPoli(String nom, int arret) {
	return new Repos(nom, arret, Poli.getInstance());
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




