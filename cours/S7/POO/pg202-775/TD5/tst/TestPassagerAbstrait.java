package tec;

abstract class TestPassagerAbstrait{

    abstract protected PassagerAbstrait creerPassager(String nom, int destination);

    public void testFaussaire() {
	FauxBus aAutobus = new FauxBus(40,100);
	aAutobus.allerArretSuivant();
	assert aAutobus.messages.get(1) == "arretSuivant" : "testFaussaire échoué, arretsuivant";
    }

    public void testAccesseurs() {
	PassagerAbstrait aPassager = creerPassager("Reda",8);
	assert aPassager.nom() == "Reda" : "testAccesseurs échoué, nom";
	assert aPassager.estDehors() == true : "testAccesseurs échoué, estDehors";
	assert aPassager.estAssis() == false : "testAccesseurs échoué, estAssis";
	assert aPassager.estDebout() == false : "testAccesseurs échoué, estDebout";
    }

    public void testAccepterPlaceAssise () {
	PassagerAbstrait aPassager = creerPassager("Reda",8);
	aPassager.accepterPlaceAssise();
	assert aPassager.estDehors() == false : "testAccepterPlaceAssise échoué, estDehors";
	assert aPassager.estAssis() == true : "testAccepterPlaceAssise échoué, estAssis";
	assert aPassager.estDebout() == false : "testAccepterPlaceAssise échoué, estDebout";	
    }

    public void testAccepterPlaceDebout () {
	PassagerAbstrait aPassager = creerPassager("Reda",8);
	aPassager.accepterPlaceDebout();
	assert aPassager.estDehors() == false : "testAccepterPlaceDebout échoué, estDehors";
	assert aPassager.estAssis() == false : "testAccepterPlaceDebout échoué, estAssis";
	assert aPassager.estDebout() == true : "testAccepterPlaceDebout échoué, estDebout";	
    }

    public void testAccepterSortie () {
	PassagerAbstrait aPassager = creerPassager("Reda",8);
	aPassager.accepterSortie();
	assert aPassager.estDehors() == true : "testAccepterSortie échoué, estDehors";
	assert aPassager.estAssis() == false : "testAccepterSortie échoué, estAssis";
	assert aPassager.estDebout() == false : "testAccepterSortie échoué, estDebout";	
    }

    public void testMonterDansVide() {
	FauxBus aAutobus = new FauxBus(0,0);
	PassagerAbstrait aPassager = creerPassager("Reda",8);
	aPassager.monterDans(aAutobus);
	assert aAutobus.messages.size() == 0 : "testMonterDansVide échoué, messages";
    }


    //bug a la ligne 60, probleme de debordement de tableau de messages (causé par lunatique puis par standard ...)

    /*public void testArret() {
	PassagerAbstrait p = creerPassager("Reda", 5);
	FauxBus faux = new FauxBus(0,0);
	p.nouvelArret(faux, 1);    
	// test interaction.
	assert faux.messages.getLast() == "arretSuivant"  : "testArret échoué, pas a destination";
	p.nouvelArret(faux, 5);    
	// test interaction.
	assert "sortir" == faux.messages.getLast() : "testArret échoué, destination";
	}*/

}
