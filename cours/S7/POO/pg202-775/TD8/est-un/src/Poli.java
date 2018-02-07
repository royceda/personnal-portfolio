package tec;

class Poli implements Caractere {
    
    private Poli() {}

    private static Caractere POLI = new Poli();

    public static Caractere getInstance() {
	return POLI;
    }

    public void choixChangerPlace(Bus bus, int arret, Passager p) throws IllegalStateException{
	if( !bus.aPlaceAssise() ){
	    try{
		bus.demanderChangerEnDebout(p);
	    }
	    catch(IllegalStateException e){
		throw new IllegalStateException();
	    }
	}
    }
}
