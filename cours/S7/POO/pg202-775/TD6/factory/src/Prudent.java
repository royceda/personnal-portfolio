package tec;

class Prudent implements Caractere {
    
    private Prudent() {}

    private static Caractere PRUDENT = new Prudent();

    public static Caractere getInstance() {
	return PRUDENT;
    }

    public void choixChangerPlace(Bus b, int arret, Passager p) {
	if (arret >= 5)
	    b.demanderChangerEnAssis(p);
	    
	else if (arret <= 3)
	    b.demanderChangerEnDebout(p);
    }
}
