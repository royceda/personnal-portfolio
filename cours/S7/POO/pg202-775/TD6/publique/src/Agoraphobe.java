package tec;

class Agoraphobe implements Caractere {

    private Agoraphobe() {}

    private static Caractere AGORAPHOBE = new Agoraphobe();

    public static Caractere getInstance() {
	return AGORAPHOBE;
    }

    public void choixChangerPlace(Bus bus, int arret, Passager p) {
	if (!(bus.aPlaceDebout() && bus.aPlaceAssise()))
	    bus.demanderSortie(p);
    }
}
