package tec;

public class Sportif extends PassagerAbstrait{
        
    Sportif(String nom, int destination, Caractere carac){
	super(nom, destination, carac);
    }

    public static Usager fairePassagerSportifCalme(String nom, int arret) {
	return new Sportif(nom, arret, Calme.getInstance());
    }

     public static Usager fairePassagerSportifPrudent(String nom, int arret) {
	return new Sportif(nom, arret, Prudent.getInstance());
    }

     public static Usager fairePassagerSportifAgoraphobe(String nom, int arret) {
	return new Sportif(nom, arret, Agoraphobe.getInstance());
    }

    public static Usager fairePassagerSportifPoli(String nom, int arret) {
	return new Sportif(nom, arret, Poli.getInstance());
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
