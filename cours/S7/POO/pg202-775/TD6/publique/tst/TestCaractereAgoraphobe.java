package tec;

class TestCaractereAgoraphobe extends TestPassagerAbstrait {

    protected PassagerAbstrait creerPassager(String nom, int destination) {
	return (PassagerAbstrait) Sportif.fairePassagerSportifAgoraphobe(nom, destination);
    }

    public void testChoixChangerPlace() {
	PassagerAbstrait aAgoraphobe = creerPassager("Reda", 4);
	FauxBus aAutobus1 = new FauxBus(0,100);

	//Agoraphobe : sort si plus de places assises ou debout
	aAgoraphobe.choixPlaceMontee(aAutobus1);
	aAgoraphobe.nouvelArret(aAutobus1,1);
	assert aAutobus1.messages.getLast() == "sortir" : "testChoixChangerPlace échoué, Agoraphobe; messages1";

	FauxBus aAutobus2 = new FauxBus(40,0);
	aAgoraphobe.choixPlaceMontee(aAutobus2);
	aAgoraphobe.nouvelArret(aAutobus2,1);
	assert aAutobus2.messages.getLast() == "sortir" : "testChoixChangerPlace échoué, Agoraphobe; messages2";
    }
}
