package tec;

final public class FabriqueTec{
    public static PassagerStandard fairePassagerStandard(String nom, int arret) {
	PassagerStandard passager = new PassagerStandard(nom, arret);
	return passager;
    }

    public static Autobus faireAutobus(int nbPlaceAssise, int nbPlaceDebout) {
	Autobus autobus = new Autobus(nbPlaceAssise, nbPlaceDebout);
	return autobus;
    }
}
