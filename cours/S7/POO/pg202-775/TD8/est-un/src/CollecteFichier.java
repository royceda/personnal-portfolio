package tec;
import java.io.Writer;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.IOException;

class CollecteFichier implements Collecte{
    private FileWriter f;
    private PrintWriter p;
    private int numeroArret;
    private int nombreEntrees;
    private int nombreSorties;
    private int tmpSorties; //Cet entier sert uniquement au bon affichage du nombre de sorties.
    //En effet, le nombre de sorties est incrémenté seulement quand la méthode allerArretSuivant() est appelée, et c'est aussi le moment (juste après) où il est réinitialisé.
    //Ce tmpSorties va donc prendre la valeur de nombreSorties entre sa dernière incrémentation et sa réinittialisation, et ça ne peut pas se faire en dehors de la méthode changerArret()
    private int tmpEntrees; //Cet entier sert à afficher le nombre d'entrées au même moment que le nombre de sorties, et donc au bon moment, par rapport au print debog du client.

    public CollecteFichier(String cheminFichier) throws IOException{
	try{
	    f = new FileWriter(cheminFichier);
	}
	catch(IOException e){}
	p = new PrintWriter(f);
	//Quand fermer le fichier ?
	numeroArret = 0;
	nombreEntrees = 0;
	nombreSorties = 0;
    }

    public void uneEntree(){
	nombreEntrees++;
    }

    public void uneSortie(){
	nombreSorties++;
    }

    public void changerArret(){
	//À l'appel de cette méthode on sait que la dernière incrémentation de nombreSorties est effectuée (entre la fin de la méthode allerArretSuivant et le début de cette méthode, dans GreffonAutobus).
	tmpSorties = nombreSorties;
	tmpEntrees = nombreEntrees;
	p.println("Arrêt numéro : " + numeroArret + " Nombre d'entrées : " + nombreEntrees + " Nombre de sorties : " + nombreSorties);
	p.flush();
	numeroArret++;
	nombreEntrees = 0;
	nombreSorties = 0; //Réinitialisation de nombreSorties. Tout affichage de cette variable en dehors de cette méthode sera donc inutile (tout le temps 0)
    }

    @Override
    public String toString(){
	String ret = "Arrêt numéro : " + numeroArret + " Nombre d'entrées : " + tmpEntrees + " Nombre de sorties : " + tmpSorties; //On utilise tmpSorties pour l'affichage en dehors de changerArret, comme expliqué précédemment
	return ret;
    }
}
