package tec;

class TestPassagerStandard extends TestPassagerAbstrait{
    
    protected PassagerAbstrait creerPassager(String nom, int destination) {
	return new PassagerStandard(nom, destination);
    }
    
    public void testMonterDansDebout() {
	FauxBus aAutobus = new FauxBus(0,10);
	PassagerAbstrait aPassager = creerPassager("Reda",8);
	try{
	    aPassager.monterDans(aAutobus);
	}
	catch(TecInvalidException e) {
	}
	assert aAutobus.messages.getLast() == "entreDebout" : "testMonterDansDebout échoué, messages";
    }   
}
