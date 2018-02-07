package tec;

class TestCaractereCalme extends TestPassagerAbstrait{
    
    protected PassagerAbstrait creerPassager(String nom, int destination) {
	return (PassagerAbstrait) tec.FabriqueTec.fairePassagerSportifCalme(nom, destination);
    }

    public void testChoixChangerPlace() {
	PassagerAbstrait aCalme = creerPassager("Victor", 6);
	FauxBus aAutobus = new FauxBus(40,100);
	int size;

	aCalme.choixPlaceMontee(aAutobus);

	// Calme : ne change pas de place
	size = aAutobus.messages.size();
	aCalme.nouvelArret(aAutobus,1);
	assert aAutobus.messages.size() == size : "testChoixChangerPlace échoué, Calme; messages1";
	aCalme.nouvelArret(aAutobus,2);
	assert aAutobus.messages.size() == size : "testChoixChangerPlace échoué, Calme; messages2";
	aCalme.nouvelArret(aAutobus,3);
	assert aAutobus.messages.size() == size : "testChoixChangerPlace échoué, Calme; messages3";
    }
}
