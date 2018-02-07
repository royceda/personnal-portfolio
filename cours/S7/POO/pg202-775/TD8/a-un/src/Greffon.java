package tec;
import java.io.IOException;

class Greffon implements Bus, Transport{
    protected Collecte collecte;
    protected Bus bus;

    public Greffon () {
    	// On discutera de la possibilité de passer la collecte en private et ainsi de
    	// l'instancier ici.
    }

    public void demanderChangerEnAssis(Passager p) throws IllegalStateException{
	bus.demanderChangerEnAssis(p);
    }

    public void demanderChangerEnDebout(Passager p) throws IllegalStateException{
	bus.demanderChangerEnDebout(p);
    }

    public boolean aPlaceDebout(){
	return bus.aPlaceDebout();
    }
    public boolean aPlaceAssise(){
	return bus.aPlaceAssise();
    }

    public void allerArretSuivant() throws TecInvalidException{
	try{
	    bus.allerArretSuivant(this);  // allerArretSuivant prend un bus en argument, mais on lui donne un Greffon pour aiguiller le polymorphisme sur la méthode voulue
	    collecte.changerArret();
	}
	catch(TecInvalidException e){
	    throw new TecInvalidException();
	}
    }

    public void allerArretSuivant(Bus bus) {} //Ajout pour cohérence avec Bus
    
    public void demanderPlaceAssise(Passager p) throws IllegalStateException{
	try{
	    bus.demanderPlaceAssise(p);
	    collecte.uneEntree();
	}
	catch(IllegalStateException e){
	    throw new IllegalStateException();
	}
    }

    public void demanderPlaceDebout(Passager p) throws IllegalStateException{
	try{
	    bus.demanderPlaceDebout(p);
	    collecte.uneEntree();
	}
	catch(IllegalStateException e){
	    throw new IllegalStateException();
	}
    }

    public void demanderSortie(Passager p) throws IllegalStateException{
	try{
	    bus.demanderSortie(p);
	    collecte.uneSortie();
	}
	catch(IllegalStateException e){
	    throw new IllegalStateException();
	}
    }

    @Override
    public String toString(){
	return bus.toString() + "\n" + collecte.toString();
    }
}
