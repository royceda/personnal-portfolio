package tec;

public class Repos extends PassagerAbstrait{

    public Repos(String nom, int destination, Caractere carac){
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

    void choixPlaceMontee(Bus b){
	if(b.aPlaceAssise())
	    b.demanderPlaceAssise(this);
	else if (b.aPlaceDebout())
	    b.demanderPlaceDebout(this);
    }
}




