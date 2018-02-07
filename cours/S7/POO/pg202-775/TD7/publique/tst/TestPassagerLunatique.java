package tec;

class TestPassagerLunatique extends TestPassagerAbstrait{
    
    protected PassagerAbstrait creerPassager(String nom, int destination) {
	return new PassagerLunatique(nom, destination, Nerveux.getInstance());
    }

    public void testChoixPlaceMontee() {
	PassagerAbstrait aPassager = creerPassager("Victor", 6);
	assert aPassager.nom() == "Victor" : "testChoixPlaceMontee échoué, nom";
 	FauxBus aAutobus = new FauxBus(40,100);
	aPassager.choixPlaceMontee(aAutobus);
	assert aAutobus.messages.getLast() == "entreDebout" : "testChoixPlaceMontee échoué, getLast(); messages";
	aPassager = creerPassager("Lionel", 5);
 	aAutobus = new FauxBus(100,0);
	aPassager.choixPlaceMontee(aAutobus);
	assert aAutobus.messages.size() == 0 : "testChoixPlaceMontee échoué, choixPlaceMontee sans places debout";
    }

    public void testChoixChangerPlace() {
	PassagerAbstrait aPassager = creerPassager("Victor", 6);
 	FauxBus aAutobus = new FauxBus(1,100);
	aPassager.choixPlaceMontee(aAutobus);
	assert aAutobus.messages.getLast() == "entreDebout" : "testChoixPlaceMontee échoué, getLast 1; messages";
	aPassager.nouvelArret(aAutobus,2);
	assert aAutobus.messages.getLast() == "changeAssis" : "ChoixChangerPlace échoué, getLast 2; messages";
    }
}

