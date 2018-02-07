package tec;

class TestCaracterePrudent extends TestPassagerAbstrait{
    
    protected PassagerAbstrait creerPassager(String nom, int destination) {
	return (PassagerAbstrait) tec.FabriqueTec.fairePassagerSportifPrudent(nom, destination);
    }

    public void testChoixChangerPlace() {
	PassagerAbstrait aPrudent = creerPassager("Victor", 6);
	FauxBus aAutobus = new FauxBus(40,100);

	aPrudent.choixPlaceMontee(aAutobus);

	//Prudent : s'assoit si plus de 5 arrêts, et si moins de 3 arrêts se met debout
	aPrudent.nouvelArret(aAutobus,1);
	assert aAutobus.messages.getLast() == "changeAssis" : "testChoixChangerPlace échoué, Prudent; messages1";
	aPrudent.nouvelArret(aAutobus,2);
	assert aAutobus.messages.getLast() == "changeAssis" : "testChoixChangerPlace échoué, Prudent; messages2";
	aPrudent.nouvelArret(aAutobus,5);
	assert aAutobus.messages.getLast() == "changeDebout" : "testChoixChangerPlace échoué, Prudent; messages3";
	aPrudent.nouvelArret(aAutobus,6);
	assert aAutobus.messages.getLast() == "sortir" : "testChoixChangerPlace échoué, Prudent; messages4";
    }

}
