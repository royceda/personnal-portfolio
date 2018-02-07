package tec;

class TestAutobus {

    public void lancer() throws Exception{
	Class c = this.getClass();
	java.lang.reflect.Method[] mesMethodes = c.getMethods();
	int nbTest = 0;
	for (int i = 0; i < mesMethodes.length; i++) {
	    java.lang.reflect.Method m = mesMethodes[i];
	    if (m.getName().startsWith("test")){
		System.out.print(".");
		m.invoke(this);
		nbTest++;
	    }
	}
	System.out.println("(" + nbTest + "):OK: " + getClass().getName());
    }


    public void testFaussaire() {
	System.out.println("accepterSortie...");
	PassagerStandard aPassagerStandard = new PassagerStandard();
	aPassagerStandard.accepterSortie();
	assert aPassagerStandard.messages.get(1) == "accepterSortie";
	System.out.println("accepterSortie ok");
    }

    void constructTestPlace (int nbPlaceAssise, int nbPlaceDebout, boolean boolAssis, boolean boolDebout) {
	System.out.println("aPlaceAssise/aPlaceDebout...");
	Autobus aAutobus = new Autobus(nbPlaceAssise,nbPlaceDebout);
	assert aAutobus.aPlaceAssise() == boolAssis;
	assert aAutobus.aPlaceDebout() == boolDebout;
	System.out.println("aPlaceAssise/aPlaceDebout ok");
    }
    
    public void testConstructAssis() {
	constructTestPlace(0,1000,false,true);
    }

    public void testConstructDebout() {
	constructTestPlace(1000,0,true,false);
    }

    public void testAllerArretSuivant() {
	System.out.println("allerArretSuivant...");
	PassagerStandard[] faux = {null,
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard()}; //9
    
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
	    assert 1 == faux[i].messages.size() : "faux " + i;
	    assert "accepterPlaceAssise" == faux[i].messages.getLast() 
		: "message " + i;
	}
	
	for (int i = 4; i <= 5; i++) {
	    assert 1 == faux[i].messages.size() : "faux " + i;
	    assert "accepterPlaceDebout" == faux[i].messages.getLast() 
		: "message " + i;
	}
	
	bus.allerArretSuivant();

	//faussaire
	for (int i = 1; i <= 5; i++) {
	    assert "nouvelArret" == faux[i].messages.getLast() : "message " + i;
	}
	System.out.println("allerArretSuivant OK");
    }	


    public void testDemanderSortie() {
	System.out.println("demanderSortie...");
	PassagerStandard[] faux = {null,
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard()}; //9
    
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
	
	assert bus.aPlaceAssise() == false;
	bus.demanderSortie(faux[3]);
	faux[3].status = 2;
	assert bus.aPlaceAssise() == true;

	//faussaire
	assert faux[3].messages.getLast() == "accepterSortie";

	
	//test un passager debout sort
	//etat	
	assert bus.aPlaceDebout() == false;
	bus.demanderSortie(faux[7]);
	faux[7].status = 2;
	assert bus.aPlaceDebout() == true;

	//faussaire
	assert faux[3].messages.getLast() == "accepterSortie";
	
	System.out.println("demanderSortie OK");
    }

    public void testDemanderChanger() {
	System.out.println("demanderChanger...");
	PassagerStandard[] faux = {null,
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard()}; //9

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
	assert bus.aPlaceAssise() == true;
	assert bus.aPlaceDebout() == false;

	//tests faussaires
	assert "accepterPlaceDebout" == faux[3].messages.getLast();
	bus.demanderChangerEnAssis(faux[6]);
	
	
	faux[6].status = 0;
	//tests sur les accesseurs
	
	assert bus.aPlaceAssise() == false;
	assert bus.aPlaceDebout() == true;

	//tests faussaires
	assert "accepterPlaceAssise" == faux[6].messages.getLast();
		
	System.out.println("demanderChanger OK");
    }


    public void testDemanderPlace() {
	System.out.println("demanderPlace...");
	PassagerStandard[] faux = {null,
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard(),
				   new PassagerStandard()}; //9

	Autobus bus = new Autobus(5, 3);

	/*******************************************/
	for (int i = 1; i <= 5; i++) {

	    bus.demanderPlaceAssise(faux[i]);
      
	    // test etat.
	    if (i == 5)
		assert false == bus.aPlaceAssise() : "fin assis";
	    else
		assert true == bus.aPlaceAssise() : "demande " + i;	
	}

	// test interaction.
	for (int i = 1; i <= 5; i++) {
	    assert 1 == faux[i].messages.size() : "faux " + i;
	    assert "accepterPlaceAssise" == faux[i].messages.getLast() 
		: "message " + i;
	}
    
	/*******************************************/
	for (int i = 6; i <= 8; i++) {

	    bus.demanderPlaceDebout(faux[i]);

	    // test etat.
	    if (i == 8)
		assert false == bus.aPlaceDebout() : "fin debout";
	    else
		assert true == bus.aPlaceDebout() : "demande " + i;	
	}

	// test interaction.
	for (int i = 6; i <= 8; i++) {
	    assert "accepterPlaceDebout" == faux[i].messages.getLast() 
		: "message " + i;
	}
	System.out.println("demanderPlace OK");
    }
}
