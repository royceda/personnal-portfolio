package tec;

class Agoraphobe implements Caractere {
    
    private Agoraphobe() {}

    private static Caractere AGORAPHOBE = new Agoraphobe();

    public static Caractere getInstance() {
	return AGORAPHOBE;
    }

    public void choixChangerPlace(Bus bus, int arret, Passager p) throws IllegalStateException{
	if (!bus.aPlaceDebout() || !bus.aPlaceAssise()){
	    try{
		bus.demanderSortie(p);
	    }
	    catch(IllegalStateException e){
		throw new IllegalStateException();
	    }
	}
    }
}
