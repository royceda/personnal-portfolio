package tec;

class Calme implements Caractere {

    private Calme() {}

    private static Caractere CALME = new Calme();

    public static Caractere getInstance() {
	return CALME;
    }

    public void choixChangerPlace(Bus b, int arret, Passager p) {}
}
