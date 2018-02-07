package tec;

abstract class Bus implements Transport{
  abstract public boolean aPlaceAssise();
  abstract public boolean aPlaceDebout();

  abstract protected void demanderPlaceAssise(Passager p);
  abstract protected void demanderPlaceDebout(Passager p);
  abstract protected void demanderSortie(Passager p);

  abstract protected void demanderChangerEnDebout(Passager p);
  abstract protected void demanderChangerEnAssis(Passager p);
}
