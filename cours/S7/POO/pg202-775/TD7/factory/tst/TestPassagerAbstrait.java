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

    public void testExceptionConversion(){
	PassagerAbstrait aPassager = creerPassager("Reda",8);
	Transport t = new Transport() {		
		public boolean aPlaceAssise(){
		    return true;
		}
		
		public boolean aPlaceDebout(){
		    return true;
		}
		
		public void allerArretSuivant() throws TecInvalidException{
		}
	    };
	try{
	    aPassager.monterDans(t);
	    assert false: "testExceptionConversion échoué";
	}
	catch(TecInvalidException e){
	}
    }
}
