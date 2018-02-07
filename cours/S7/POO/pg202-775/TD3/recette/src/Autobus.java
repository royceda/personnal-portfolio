package tec;

public class Autobus
{
    private JaugeNaturel aJaugeAssise;
    private JaugeNaturel aJaugeDebout;
    private PassagerStandard[] passagers;
    private int arrets;

    public Autobus(int nbPlaceAssise, int nbPlaceDebout){
	aJaugeAssise = new JaugeNaturel(nbPlaceAssise, 0);
	aJaugeDebout = new JaugeNaturel(nbPlaceDebout, 0);
	passagers = new PassagerStandard[nbPlaceDebout + nbPlaceAssise];
	arrets = 0;
    }
    
    public void allerArretSuivant(){
	arrets++;
	for(int i = 0; i < passagers.length; i++){
	    if (passagers[i] != null)
		passagers[i].nouvelArret(this, arrets);
	}
    }
    
    public boolean aPlaceAssise(){
	return aJaugeAssise.estVert();
    }

    public boolean aPlaceDebout(){
	return aJaugeDebout.estVert();
    }

    public void demanderChangerEnAssis(PassagerStandard p){
	if( aPlaceAssise() ){
	    p.accepterPlaceAssise();
	    aJaugeDebout.decrementer();
	    aJaugeAssise.incrementer();
	}
    }
    
    public void demanderChangerEnDebout(PassagerStandard p){
	if( aPlaceDebout() ){
	    p.accepterPlaceDebout();
	    aJaugeAssise.decrementer();
	    aJaugeDebout.incrementer();
	}
    }

    public void demanderPlaceAssise(PassagerStandard p){
	int i=0;
	if( aPlaceAssise() ){
	    p.accepterPlaceAssise();
	    aJaugeAssise.incrementer();
	    while((i < passagers.length) && passagers[i] != null)
		i++;
	    if (i<passagers.length)
		passagers[i] = p;
	}
    }

    public void demanderPlaceDebout(PassagerStandard p){
	int i=0;
	if( aPlaceDebout() ){
	    p.accepterPlaceDebout();
	    aJaugeDebout.incrementer();
	    while( i < passagers.length && passagers[i] != null)
		i++;
	    if (i<passagers.length)
		passagers[i] = p;
	}
    }

    public void demanderSortie(PassagerStandard p){	
	int i = 0;
	if( p.estAssis() ){
	    aJaugeAssise.decrementer();
	}
	else if( p.estDebout() ){
	    aJaugeDebout.decrementer();
	}
	p.accepterSortie();
	while( i < passagers.length && passagers[i] != null && passagers[i].nom() != p.nom() )
	    i++;
	if( i < passagers.length && passagers[i] != null && passagers[i].nom() == p.nom() )
	    passagers[i] = null;
    }

    @Override
    public String toString() {
	return "[arret:" + arrets + ", assis:" + aJaugeAssise.toString() + ", debout:" + aJaugeDebout.toString() + "]";
    }
}
