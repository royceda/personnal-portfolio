package tec;

class TestPassagerStandard {

    void testFaussaire() {
	System.out.println("testFaussaire...");
	Autobus aAutobus = new Autobus(40,100);
	aAutobus.allerArretSuivant();
	assert aAutobus.messages.get(1) == "arretSuivant";
	System.out.println("testFaussaire ok");
    }

    void testAccesseurs() {
	System.out.println("testAccesseurs...");
	PassagerStandard aPassager = new PassagerStandard("Reda",8);
	assert aPassager.nom() == "Reda";
	assert aPassager.estDehors() == true;
	assert aPassager.estAssis() == false;
	assert aPassager.estDebout() == false;
	System.out.println("testAccesseurs ok");
    }

    void testAccepterPlaceAssise () {
	System.out.println("testAccepterPlaceAssise...");
	PassagerStandard aPassager = new PassagerStandard("Reda",8);
	aPassager.accepterPlaceAssise();
	assert aPassager.estDehors() == false;
	assert aPassager.estAssis() == true;
	assert aPassager.estDebout() == false;
	System.out.println("testAccepterPalceAssise ok");	
    }

    void testAccepterPlaceDebout () {
	System.out.println("testAccepterPlaceDebout...");
	PassagerStandard aPassager = new PassagerStandard("Reda",8);
	aPassager.accepterPlaceDebout();
	assert aPassager.estDehors() == false;
	assert aPassager.estAssis() == false;
	assert aPassager.estDebout() == true;
	System.out.println("testAccepterPalceDebout ok");	
    }

    void testAccepterSortie () {
	System.out.println("testAccepterSortie...");
	PassagerStandard aPassager = new PassagerStandard("Reda",8);
	aPassager.accepterSortie();
	assert aPassager.estDehors() == true;
	assert aPassager.estAssis() == false;
	assert aPassager.estDebout() == false;
	System.out.println("testAccepterSortie ok");	
    }

    void testMonterDansVide() {
	System.out.println("testMonterDansVide...");
	Autobus aAutobus = new Autobus(0,0);
	PassagerStandard aPassager = new PassagerStandard("Reda",8);
	aPassager.monterDans(aAutobus);
	assert aAutobus.messages.size() == 0;
	System.out.println("testMonterDansVide ok");
    }

    void testMonterDansDebout() {
	System.out.println("testMonterDansDebout...");
	Autobus aAutobus = new Autobus(0,10);
	PassagerStandard aPassager = new PassagerStandard("Reda",8);
	aPassager.monterDans(aAutobus);
	assert aAutobus.messages.getLast() == "entreDebout";
	System.out.println("testMonterDansDebout ok");
    }

    void testArret() {
	System.out.println("testArret...");
	PassagerStandard p = new PassagerStandard("Reda", 5);
	Autobus faux = new Autobus(0,0);
	/*******************************************/
	p.nouvelArret(faux, 1);    
	// test interaction.
	assert 0 == faux.messages.size() : "pas a destination";
	/*******************************************/
	p.nouvelArret(faux, 5);    
	// test interaction.
	assert "sortir" == faux.messages.getLast() : "destination";
	System.out.println("testArret ok");
    }

    void lancer() {
	int nbTest = 0;

	System.out.print('.'); nbTest++;
	testFaussaire();
	System.out.print('.'); nbTest++;
	testAccesseurs();
	System.out.print('.'); nbTest++;
	testAccepterPlaceAssise();
	System.out.print('.'); nbTest++;
	testAccepterPlaceDebout();
	System.out.print('.'); nbTest++;
	testAccepterSortie();
	System.out.print('.'); nbTest++;
	testMonterDansVide();
	System.out.print('.'); nbTest++;
	testMonterDansDebout();
	System.out.print('.'); nbTest++;
	testArret();
	
 	System.out.println("(" + nbTest + "):OK: " + getClass().getName()); 
    }
}
