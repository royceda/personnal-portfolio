package tec;

class TestPassagerTetu extends TestPassagerAbstrait{

    protected PassagerAbstrait creerPassager(String nom, int destination) {
	return (PassagerAbstrait) Tetu.fairePassagerTetuCalme(nom, destination);
    }

    public void testChoixPlaceMontee() {
	PassagerAbstrait aCalme = creerPassager("Victor", 6);

	FauxBus aAutobusVide = new FauxBus(40,100);
	FauxBus aAutobusPlein = new FauxBus(40,0);
	
	aCalme.choixPlaceMontee(aAutobusVide);
	assert aAutobusVide.messages.getLast() == "entreDebout" : "testChoixPlaceMontee échoué, getLast(); messages1";
	aCalme.choixPlaceMontee(aAutobusPlein);
	assert aAutobusPlein.messages.getLast() == "entreDebout" : "testChoixPlaceMontee échoué, getLast(); messages2";	
    }
}
