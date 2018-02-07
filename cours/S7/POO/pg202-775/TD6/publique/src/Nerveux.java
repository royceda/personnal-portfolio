package tec;

class Nerveux implements Caractere {

    private Nerveux() {}

    private static Caractere NERVEUX = new Nerveux();

    public static Caractere getInstance() {
	return NERVEUX;
    }
    
    public void choixChangerPlace(Bus bus, int arret, Passager p) {
	if( p.estAssis() )                   
	    bus.demanderChangerEnDebout(p);
	else
	    bus.demanderChangerEnAssis(p);
    }
}
