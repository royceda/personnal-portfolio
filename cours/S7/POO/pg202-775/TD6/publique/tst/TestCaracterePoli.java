package tec;

class TestCaracterePoli extends TestPassagerAbstrait{

    protected PassagerAbstrait creerPassager(String nom, int destination) {
	return (PassagerAbstrait) Fatigue.fairePassagerFatiguePoli(nom, destination);
    }

    public void testChoixChangerPlace() {
	PassagerAbstrait aPoli = creerPassager("Lionel", 5);

	//Poli : Si plus de places assises se met debout
	FauxBus aAutobus3 = new FauxBus(0,100);
	aPoli.choixPlaceMontee(aAutobus3);
	aPoli.nouvelArret(aAutobus3,1);
	assert aAutobus3.messages.getLast() == "changeDebout" : "testChoixChangerPlace échoué, Poli; messages1";
    }

}
