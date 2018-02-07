package tec;

class TestPassagerRepos extends TestPassagerAbstrait {

    protected PassagerAbstrait creerPassager(String nom, int destination) {
	return (PassagerAbstrait) Repos.fairePassagerReposPoli(nom, destination);
    }
    
    public void testChoixPlaceMontee() {
	
	PassagerAbstrait aPassager  = creerPassager("Charlie Brown", 7);
	FauxBus          aAutobus       = new FauxBus(1,100);
	FauxBus          aAutobusAssis  = new FauxBus(1,0);
	FauxBus          aAutobusDebout = new FauxBus(0,1);

	assert aPassager.nom() == "Charlie Brown": "TestChoixPlaceMontee: echec, nom";  
	
	//Poli
	aPassager.choixPlaceMontee(aAutobus);
	assert aAutobus.messages.getLast() == "entreAssis": "TestChoixPlaceMontee: echec, getLast(): messages";
	aPassager.choixPlaceMontee(aAutobusAssis);
	assert aAutobusAssis.messages.getLast() == "entreAssis": "TestChoixPlaceMontee: echec, getLast(): messages";
	aPassager.choixPlaceMontee(aAutobusDebout);
	assert aAutobusDebout.messages.getLast() == "entreDebout": "TestChoixPlaceMontee: echec, getLast(): messages";

	aPassager = creerPassager("Linus Van Pelt", 13);
	aAutobus  = new FauxBus(0, 0);
	assert aAutobus.messages.size() == 0: "testChoixMontee: echec, getLast(): Sans Place debout";
    }
}
