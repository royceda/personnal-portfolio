package tec;
import java.io.IOException;

final public class FabriqueTec{
    private FabriqueTec() {
    }

    public static Transport faireAutobus(int nbPlaceAssise, int nbPlaceDebout) {
	return new Autobus(nbPlaceAssise, nbPlaceDebout);
    }

    public static Transport faireAutobusMemoire(int nbPlaceAssise, int nbPlaceDebout) {
	return new GreffonAutobus(nbPlaceAssise, nbPlaceDebout);
    }

    public static Transport faireAutobusCollecte(int nbPlaceAssise, int nbPlaceDebout, Collecte collecte) {
	return new GreffonAutobus(nbPlaceAssise, nbPlaceDebout, collecte);
    }

    public static Transport faireAutobusFichier(int nbPlaceAssise, int nbPlaceDebout, String cheminFichier) throws IOException{
	GreffonAutobus g;
	try{
	    g = new GreffonAutobus(nbPlaceAssise, nbPlaceDebout, cheminFichier);
	}
	catch(IOException e){
	    g = new GreffonAutobus(nbPlaceAssise, nbPlaceDebout); //Choix de ne pas passer par un fichier si erreur
	}
	return g;
    }

    /************************************************/
    
    public static Usager fairePassagerStandard(String nom, int arret) {
	return new Repos(nom, arret, Calme.getInstance());
    }

    public static Usager fairePassagerLunatique(String nom, int arret) {
	return new Sportif(nom, arret, Nerveux.getInstance());
    }

    public static Usager fairePassagerStresse(String nom, int arret) {
	return new Fatigue(nom, arret, Prudent.getInstance());
    }

    /***********************************************/

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

    /***********************************************/

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

    /***********************************************/

    public static Usager fairePassagerReposPrudent(String nom, int arret) {
	return new Repos(nom, arret, Prudent.getInstance());
    }

    public static Usager fairePassagerReposAgoraphobe(String nom, int arret) {
	return new Repos(nom, arret, Agoraphobe.getInstance());
    }

    public static Usager fairePassagerReposPoli(String nom, int arret) {
	return new Repos(nom, arret, Poli.getInstance());
    }
    
    /***********************************************/

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
}
