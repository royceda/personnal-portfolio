package tec;

public class Tetu extends PassagerAbstrait{
    
    Tetu(String nom, int destination, Caractere carac){
	super(nom,destination,carac);
    }
    
    public static Usager fairePassagerTetuCalme(String nom, int arret) {
	return new Tetu(nom, arret, Calme.getInstance());
    }

    public static Usager fairePassagerTetuNerveux(String nom, int arret) {
	return new Tetu(nom, arret, Nerveux.getInstance());
    }

    public static Usager fairePassagerTetuPrudent(String nom, int arret) {
	return new Tetu(nom, arret, Prudent.getInstance());
    }

    public static Usager fairePassagerTetuAgoraphobe(String nom, int arret) {
	return new Tetu(nom, arret, Agoraphobe.getInstance());
    }

    public static Usager fairePassagerTetuPoli(String nom, int arret) {
	return new Tetu(nom, arret, Poli.getInstance());
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
