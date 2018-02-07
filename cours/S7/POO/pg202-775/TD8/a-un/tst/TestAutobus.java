package tec;

class TestAutobus {

    public void testFaussaire() {
	FauxPassager aFauxPassager = new FauxPassager();
	aFauxPassager.accepterSortie();
	assert aFauxPassager.messages.get(1) == "accepterSortie" : "testFaussaire échoué";
    }

    void constructTestPlace (int nbPlaceAssise, int nbPlaceDebout, boolean boolAssis, boolean boolDebout) {
	Autobus aAutobus = new Autobus(nbPlaceAssise,nbPlaceDebout);
	assert aAutobus.aPlaceAssise() == boolAssis : "constructTestPlace1 échoué";
	assert aAutobus.aPlaceDebout() == boolDebout : "constructTestPlace2 échoué";
    }
    
    public void testConstructAssis() {
	constructTestPlace(0,1000,false,true);
    }

    public void testConstructDebout() {
	constructTestPlace(1000,0,true,false);
    }

    public void testAllerArretSuivant() {
	FauxPassager[] faux = {null,
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager()}; //9
    
	Autobus bus = new Autobus(5, 3);

	//Remplit 3 places assises
	for (int i = 1; i <=3; i++) {
	    bus.demanderPlaceAssise(faux[i]);
	}
	
	//Remplit 2 places debouts
	for (int i = 4; i <= 5; i++) {
	    bus.demanderPlaceDebout(faux[i]);
	}

	//faussaire
	for (int i = 1; i <= 3; i++) {
	    assert 1 == faux[i].messages.size() : "testAllerArretSuivant échoué, demanderPlaceAssise " + i;
	    assert "accepterPlaceAssise" == faux[i].messages.getLast(): "testAllerArretSuivant échoué, accepterPlaceAssise " + i;
	}
	
	for (int i = 4; i <= 5; i++) {
	    assert 1 == faux[i].messages.size() : "testAllerArretSuivant échoué, demanderPlaceDebout " + i;
	    assert "accepterPlaceDebout" == faux[i].messages.getLast() : "testAllerArretSuivant échoué, accepterPlaceDebout " + i;
	}
	try {
	    bus.allerArretSuivant();
	}
	catch(TecInvalidException e) {
	}
	//faussaire
	for (int i = 1; i <= 5; i++) {
	    assert "nouvelArret" == faux[i].messages.getLast() : "testAllerArretSuivant échoué, nouvelArret " + i;
	}
    }	


    public void testDemanderSortie() {
	FauxPassager[] faux = {null,
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager()}; //9
    
	Autobus bus = new Autobus(5, 3);
	
	//Remplit toutes les places assises
	for (int i = 1; i <= 5; i++) {
	    bus.demanderPlaceAssise(faux[i]);
	    faux[i].status = 0;
	}
	
	//Remplit toutes les places debouts
	for (int i = 6; i <= 8; i++) {
	    bus.demanderPlaceDebout(faux[i]);
	    faux[i].status = 1;
	}

	//test un passager assis sort
	//etat
	
	assert bus.aPlaceAssise() == false : "testDemanderSortie échoué, aPlaceAssise1";
	bus.demanderSortie(faux[3]);
	faux[3].status = 2;
	assert bus.aPlaceAssise() == true : "testDemanderSortie échoué, aPlaceAssise2";

	//faussaire
	assert faux[3].messages.getLast() == "accepterSortie" : "testDemanderSortie échoué, accepterSortie1";

	
	//test un passager debout sort
	//etat	
	assert bus.aPlaceDebout() == false : "testDemanderSortie échoué, aPlaceDebout1";
	bus.demanderSortie(faux[7]);
	faux[7].status = 2;
	assert bus.aPlaceDebout() == true : "testDemanderSortie échoué, aPlaceDebout2";

	//faussaire
	assert faux[3].messages.getLast() == "accepterSortie" : "testDemanderSortie échoué, aPlaceSortie2";
    }

    public void testDemanderChanger() {
	FauxPassager[] faux = {null,
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager()}; //9

	Autobus bus = new Autobus(5, 3);

	/*******************************************/
	for (int i = 1; i <= 5; i++) {
	    bus.demanderPlaceAssise(faux[i]);
	    faux[i].status = 0;
     	}
    
	/*******************************************/
	for (int i = 6; i <= 7; i++) {
	    bus.demanderPlaceDebout(faux[i]);
	    faux[i].status = 1;
	}
	bus.demanderChangerEnDebout(faux[3]);
	faux[3].status = 1;
	//tests sur les accesseurs
	assert bus.aPlaceAssise() == true : "testDemanderChanger échoué, aPlaceAssise1";
	assert bus.aPlaceDebout() == false : "testDemanderChanger échoué, aPlaceDebout1";

	//tests faussaires
	assert "accepterPlaceDebout" == faux[3].messages.getLast() : "testDemanderChanger échoué, accepterPlaceDebout";
	bus.demanderChangerEnAssis(faux[6]);
	
	
	faux[6].status = 0;
	//tests sur les accesseurs
	
	assert bus.aPlaceAssise() == false : "testDemanderChanger échoué, aPlaceAssise2";
	assert bus.aPlaceDebout() == true : "testDemanderChanger échoué, aPlaceDebout2";

	//tests faussaires
	assert "accepterPlaceAssise" == faux[6].messages.getLast() : "testDemanderChanger échoué, accepterPlaceAssise";
    }


    public void testDemanderPlace() {
	FauxPassager[] faux = {null,
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager(),
				   new FauxPassager()}; //9

	Autobus bus = new Autobus(5, 3);

	/*******************************************/
	for (int i = 1; i <= 5; i++) {

	    bus.demanderPlaceAssise(faux[i]);
      
	    // test etat.
	    if (i == 5)
		assert false == bus.aPlaceAssise() : "testDemanderPlace échoué, aPlaceAssise1";
	    else
		assert true == bus.aPlaceAssise() : "testDemanderPlace échoué, aPlaceAssise2";	
	}

	// test interaction.
	for (int i = 1; i <= 5; i++) {
	    assert 1 == faux[i].messages.size() : "testDemanderPlace échoué, faux " + i;
	    assert "accepterPlaceAssise" == faux[i].messages.getLast() : "testDemanderPlace échoué, accepterPlaceAssise " + i;
	}
    
	/*******************************************/
	for (int i = 6; i <= 8; i++) {

	    bus.demanderPlaceDebout(faux[i]);

	    // test etat.
	    if (i == 8)
		assert false == bus.aPlaceDebout() : "testDemanderPlace échoué, aPlaceDebout1";
	    else
		assert true == bus.aPlaceDebout() : "testDemanderPlace échoué, aPlaceDebout2";	
	}

	// test interaction.
	for (int i = 6; i <= 8; i++) {
	    assert "accepterPlaceDebout" == faux[i].messages.getLast() : "testDemanderPlace échoué, accepterPlaceDebout " + i;
	}
    }
    
    public void testEtatIncoherent() {
	Autobus b = new Autobus(10,10);
	Passager man = new Passager() {
		public String nom() {return "nom";}
		public boolean estDehors() {return true;}
		public boolean estAssis() {return true;}
		public boolean estDebout() {return true;}
		public void accepterSortie() {}
		public void accepterPlaceAssise() {}
		public void accepterPlaceDebout() {}

		public int nouvelArret(Bus bus, int numeroArret) throws IllegalStateException{ 
		    throw new IllegalStateException();
		}
	    };
	try{
	    man.nouvelArret(b, 3);
	    assert false: "testEtatIncoherent échoué";
	}
	catch(IllegalStateException e){
	}
    }
}
