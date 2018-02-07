package tec;

class TestPassagerSportif extends TestPassagerAbstrait{

    protected PassagerAbstrait creerPassager(String nom, int destination) {
	return (PassagerAbstrait) tec.FabriqueTec.fairePassagerSportifCalme(nom, destination);
    }

    public void testChoixPlaceMontee() {
	PassagerAbstrait aCalme = creerPassager("Victor", 6);
	// Les autres comportements sont inutiles ici, on teste le choix à la montée, qui est le même pour tous (Sportif)

	FauxBus aAutobusVide = new FauxBus(40,100);
	FauxBus aAutobusPlein = new FauxBus(40,0);
	
	aCalme.choixPlaceMontee(aAutobusVide);
	assert aAutobusVide.messages.getLast() == "entreDebout" : "testChoixPlaceMontee échoué, getLast(); messages1";
	aCalme.choixPlaceMontee(aAutobusPlein);
	assert aAutobusPlein.messages.size() == 0 : "testChoixPlaceMontee échoué, getLast(); messages2";	
    }
}
