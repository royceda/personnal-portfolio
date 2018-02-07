package tec;

class TestCaractereNerveux extends TestPassagerAbstrait{
    
    protected PassagerAbstrait creerPassager(String nom, int destination) {
	return (PassagerAbstrait) Fatigue.fairePassagerFatigueNerveux(nom, destination);
    }

    public void testChoixChangerPlace() {
	PassagerAbstrait aNerveux = creerPassager("Victor", 6);
	FauxBus aAutobus = new FauxBus(40,100);
	FauxBus aAutobus2 = new FauxBus(40,100);

	aNerveux.choixPlaceMontee(aAutobus);

	aNerveux.nouvelArret(aAutobus,1);
	assert aAutobus.messages.getLast() == "changeAssis" : "testChoixChangerPlace échoué, Nerveux; messages1";
	aNerveux.nouvelArret(aAutobus,2);
	assert aAutobus.messages.getLast() == "changeAssis" : "testChoixChangerPlace échoué, Nerveux; messages2";
    }

}
