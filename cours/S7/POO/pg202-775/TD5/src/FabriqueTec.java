package tec;

final public class FabriqueTec{
    private FabriqueTec() {
    }
    
    public static Usager fairePassagerStandard(String nom, int arret) {
	return new PassagerStandard(nom, arret);
    }

    public static Transport faireAutobus(int nbPlaceAssise, int nbPlaceDebout) {
	return new Autobus(nbPlaceAssise, nbPlaceDebout);
    }
}
