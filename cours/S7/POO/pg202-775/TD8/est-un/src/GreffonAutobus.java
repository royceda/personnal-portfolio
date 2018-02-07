package tec;
import java.io.IOException;

class GreffonAutobus extends Autobus{
    private Collecte collecte;

    public GreffonAutobus(int nbPlaceAssise, int nbPlaceDebout) throws RuntimeException{
	super(nbPlaceAssise,nbPlaceDebout);
	collecte = new CollecteMemoire();
    }

    public GreffonAutobus(int nbPlaceAssise, int nbPlaceDebout, String cheminFichier) throws RuntimeException, IOException{
	super(nbPlaceAssise,nbPlaceDebout);
	collecte = new CollecteFichier(cheminFichier);
    }

    public GreffonAutobus(int nbPlaceAssise, int nbPlaceDebout, Collecte collecte) throws RuntimeException{
	super(nbPlaceAssise,nbPlaceDebout);
	this.collecte = collecte;
    }

    public void allerArretSuivant() throws TecInvalidException{
	try{
	    super.allerArretSuivant();
	    collecte.changerArret();
	}
	catch(TecInvalidException e){
	    throw new TecInvalidException();
	}
    }

    public void demanderPlaceAssise(Passager p) throws IllegalStateException{
	try{
	    super.demanderPlaceAssise(p);
	    collecte.uneEntree();
	}
	catch(IllegalStateException e){
	    throw new IllegalStateException();
	}
    }

    public void demanderPlaceDebout(Passager p) throws IllegalStateException{
	try{
	    super.demanderPlaceDebout(p);
	    collecte.uneEntree();
	}
	catch(IllegalStateException e){
	    throw new IllegalStateException();
	}
    }

    public void demanderSortie(Passager p) throws IllegalStateException{
	try{
	    super.demanderSortie(p);
	    collecte.uneSortie();
	}
	catch(IllegalStateException e){
	    throw new IllegalStateException();
	}
    }

    @Override
    public String toString(){
	return super.toString() + "\n" + collecte.toString();
    }
}
