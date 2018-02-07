package tec;

interface Bus{
    boolean aPlaceAssise();
    boolean aPlaceDebout();

    void demanderPlaceAssise(Passager p);
    void demanderPlaceDebout(Passager p);
    void demanderSortie(Passager p);

    void demanderChangerEnDebout(Passager p);
    void demanderChangerEnAssis(Passager p);
}
