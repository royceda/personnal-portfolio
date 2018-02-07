package tec;
import java.util.ArrayList;


class Autobus implements Bus, Transport{
    private JaugeNaturel aJaugeAssise;
    private JaugeNaturel aJaugeDebout;
    private ArrayList<Passager> passagers;
    private int arrets;

    public Autobus(int nbPlaceAssise, int nbPlaceDebout) throws RuntimeException{
	if(nbPlaceDebout < 0 || nbPlaceAssise < 0)
	    throw new RuntimeException();
	aJaugeAssise = new JaugeNaturel(nbPlaceAssise, 0);
	aJaugeDebout = new JaugeNaturel(nbPlaceDebout, 0);
	passagers    = new ArrayList<Passager>(nbPlaceDebout + nbPlaceAssise);
	arrets = 0;
    }

    public void allerArretSuivant() throws TecInvalidException{
	arrets++;
	for(int i = 0; i < passagers.size(); i++){
	    if (passagers.get(i) != null) {
		try{
		    passagers.get(i).nouvelArret(this, arrets);
		}
		catch(IllegalStateException e){
		    throw new TecInvalidException("allerArretSuivant échoué", e);
		}
	    }
	}
    }

    public boolean aPlaceAssise(){
	return aJaugeAssise.estVert();
    }

    public boolean aPlaceDebout(){
	return aJaugeDebout.estVert();
    }

    public void demanderChangerEnAssis(Passager p) throws IllegalStateException{
	if( p.estAssis())
	    throw new IllegalStateException("Passager déjà assis");
	else if( aPlaceAssise() ){
	    p.accepterPlaceAssise();
	    aJaugeDebout.decrementer();
	    aJaugeAssise.incrementer();
	}
    }

    public void demanderChangerEnDebout(Passager p) throws IllegalStateException{
	if( p.estDebout())
	    throw new IllegalStateException("Passager déjà debout");
	else if( aPlaceDebout() ){
	    p.accepterPlaceDebout();
	    aJaugeAssise.decrementer();
	    aJaugeDebout.incrementer();
	}
    }

    public void demanderPlaceAssise(Passager p) throws IllegalStateException{
	if( !p.estDehors() )
	    throw new IllegalStateException();
	int i=0;
	if( aPlaceAssise() ){
	    if( !passagers.contains(p) ){
		p.accepterPlaceAssise();
		aJaugeAssise.incrementer();
		passagers.add(p);
	    }
	}
    }

    public void demanderPlaceDebout(Passager p) throws IllegalStateException{
	if( !p.estDehors() )
	    throw new IllegalStateException();
	int i=0;
	if( aPlaceDebout() ){
	    if( !passagers.contains(p) ){
		p.accepterPlaceDebout();
		aJaugeDebout.incrementer();
		passagers.add(p);
	    }
	}
    }

    public void demanderSortie(Passager p) throws IllegalStateException{
	int i = 0;
	if( p.estAssis() ){
	    aJaugeAssise.decrementer();
	}
	else if( p.estDebout() ){
	    aJaugeDebout.decrementer();
	}
	else if( p.estDehors() ){
	    throw new IllegalStateException();
	}
	p.accepterSortie();
	passagers.remove(p);
    }

    @Override
    public String toString() {
	return "[arret:" + arrets + ", assis:" + aJaugeAssise.toString() + ", debout:" + aJaugeDebout.toString() + "]";
    }
}
