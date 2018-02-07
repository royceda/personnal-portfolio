package tec;

class TestPassagerFatigue extends TestPassagerAbstrait{

    protected PassagerAbstrait creerPassager(String nom, int destination) {
	return (PassagerAbstrait) Fatigue.fairePassagerFatigueCalme(nom, destination);
    }

      public void testChoixPlaceMontee() {
	PassagerAbstrait aCalme = creerPassager("Victor", 6);

	FauxBus aAutobusVide = new FauxBus(40,100);
	FauxBus aAutobusPlein = new FauxBus(0,40);
	
	aCalme.choixPlaceMontee(aAutobusVide);
	assert aAutobusVide.messages.getLast() == "entreAssis" : "testChoixPlaceMontee échoué, getLast(); messages1";
	aCalme.choixPlaceMontee(aAutobusPlein);
	assert aAutobusPlein.messages.size() == 0 : "testChoixPlaceMontee échoué, getLast(); messages2";	
    }
}
