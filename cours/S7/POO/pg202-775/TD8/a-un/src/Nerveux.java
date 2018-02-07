package tec;

class Nerveux implements Caractere {

    private Nerveux() {}

    private static Caractere NERVEUX = new Nerveux();

    public static Caractere getInstance() {
	return NERVEUX;
    }

    public void choixChangerPlace(Bus bus, int arret, Passager p) throws IllegalStateException{
	if( p.estAssis() ){
	    try{
		bus.demanderChangerEnDebout(p);
	    }
	    catch(IllegalStateException e){
	    }
	}
	else{
	    try{
		bus.demanderChangerEnAssis(p);
	    }
	    catch(IllegalStateException e){
		throw new IllegalStateException();
	    }
	}
    }
}
