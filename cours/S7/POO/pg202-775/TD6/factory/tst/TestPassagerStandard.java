package tec;

class TestPassagerStandard extends TestPassagerAbstrait{
    
    protected PassagerAbstrait creerPassager(String nom, int destination) {
	return (PassagerAbstrait) tec.FabriqueTec.fairePassagerStandard(nom, destination);
    }
    
    public void testMonterDansDebout() {
	FauxBus aAutobus = new FauxBus(0,10);
	PassagerAbstrait aPassager = creerPassager("Reda",8);
	aPassager.monterDans(aAutobus);
	assert aAutobus.messages.getLast() == "entreDebout" : "testMonterDansDebout échoué, messages";
    }   
}
