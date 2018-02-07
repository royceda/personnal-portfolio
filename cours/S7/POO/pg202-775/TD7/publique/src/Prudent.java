package tec;

class Prudent implements Caractere {
    
    private Prudent() {}

    private static Caractere PRUDENT = new Prudent();

    public static Caractere getInstance() {
	return PRUDENT;
    }

    public void choixChangerPlace(Bus b, int arret, Passager p) throws IllegalStateException{
	if (arret >= 5){
	    try{
		b.demanderChangerEnAssis(p);	    
	    }
	    catch(IllegalStateException e){
	    }
	}
	else if (arret <= 3){
	    try{
		b.demanderChangerEnDebout(p);
	    }
	    catch(IllegalStateException e){
		throw new IllegalStateException();
	    }
	}
    }
}
