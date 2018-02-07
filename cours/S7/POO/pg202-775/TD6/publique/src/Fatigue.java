package tec;

public class Fatigue extends PassagerAbstrait{
    
    Fatigue(String nom, int destination, Caractere carac){
	super(nom,destination,carac);
    }

    public static Usager fairePassagerFatigueCalme(String nom, int arret) {
	return new Fatigue(nom, arret, Calme.getInstance());
    }

    public static Usager fairePassagerFatigueNerveux(String nom, int arret) {
	return new Fatigue(nom, arret, Nerveux.getInstance());
    }

    public static Usager fairePassagerFatigueAgoraphobe(String nom, int arret) {
	return new Fatigue(nom, arret, Agoraphobe.getInstance());
    }

    public static Usager fairePassagerFatiguePoli(String nom, int arret) {
	return new Fatigue(nom, arret, Poli.getInstance());
    }

    void choixPlaceMontee(Bus b){
	if( b.aPlaceAssise() )
	    b.demanderPlaceAssise(this);
    }
}