package tec;
import java.util.LinkedList;

class FausseCollecte implements Collecte{
    final Messages messages = new Messages();

    public FausseCollecte(){
	messages.add("initialisation");
    }

    public void uneEntree(){
	messages.add("une entree");
    }

    public void uneSortie(){
	messages.add("une sortie");
    }

    public void changerArret(){
	messages.add("changer arret");
    }
}
