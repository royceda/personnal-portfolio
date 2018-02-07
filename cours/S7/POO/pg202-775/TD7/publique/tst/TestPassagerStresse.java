package tec;

class TestPassagerStresse extends TestPassagerAbstrait{
    
    protected PassagerAbstrait creerPassager(String nom, int destination) {
	return new PassagerStresse(nom, destination, Prudent.getInstance());
    }
    
    public void testChoixPlaceMontee() {
	PassagerAbstrait aPassager = creerPassager("Aurélien", 6);
	assert aPassager.nom() == "Aurélien" : "testChoixPlaceMontee échoué, nom";
 	FauxBus aAutobus = new FauxBus(40,100);
	aPassager.choixPlaceMontee(aAutobus);
	assert aAutobus.messages.getLast() == "entreAssis" : "testChoixPlaceMontee échoué, entreAssis; messages";
	aPassager = creerPassager("Lionel", 5);
 	aAutobus = new FauxBus(0,100);
	aPassager.choixPlaceMontee(aAutobus);
	assert aAutobus.messages.size() == 0 : "testChoixPlaceMontee échoué, monterDans sans places assises";
    }

    public void testChoixChangerPlace() {
	PassagerAbstrait aPassager = creerPassager("Aurélien", 6);
 	FauxBus aAutobus = new FauxBus(40,100);
	aPassager.choixPlaceMontee(aAutobus);
	aPassager.nouvelArret(aAutobus,2000);
	assert aAutobus.messages.getLast() == "changeDebout" : "ChoixChangerPlace échoué, entreAssis messages";
	aPassager.nouvelArret(aAutobus,3);
	assert aAutobus.messages.getLast() == "changeDebout" : "ChoixChangerPlace échoué, changeDebout messages";
	aPassager.nouvelArret(aAutobus,4);
	assert aAutobus.messages.getLast() == "changeDebout" : "testChoixChangerPlace échoué, continuerDebout1";
	aPassager.nouvelArret(aAutobus,5);
	assert aAutobus.messages.getLast() == "changeDebout" : "testChoixChangerPlace échoué, continuerDebout2";
    }
}
