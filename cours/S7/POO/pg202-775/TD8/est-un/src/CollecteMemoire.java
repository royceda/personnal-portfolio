package tec;
import java.util.LinkedList;

class CollecteMemoire implements Collecte{
    private int numeroArret;
    private LinkedList<Integer> nombreEntrees;
    private LinkedList<Integer> nombreSorties;

    public CollecteMemoire(){
	numeroArret = 0;
	nombreEntrees = new LinkedList<Integer>();
	nombreEntrees.add(0);
	nombreSorties = new LinkedList<Integer>();
	nombreSorties.add(0);
    }

    public void uneEntree(){
	int old = nombreEntrees.get(numeroArret);
	nombreEntrees.set(numeroArret, old+1);
    }

    public void uneSortie(){
	int old = nombreSorties.get(numeroArret);
	nombreSorties.set(numeroArret, old+1);
    }

    public void changerArret(){
	numeroArret++;
	nombreEntrees.add(0);
	nombreSorties.add(0);
    }
    @Override
    public String toString(){
	String ret = "";
	for(int i = 0; i <= numeroArret; i++){
	    ret = ret + "Arrêt numéro : " + i + " Nombre d'entrées : " + nombreEntrees.get(i) + " Nombre de sorties : " + nombreSorties.get(i) + "\n";
	}
	return ret;
    }
}
