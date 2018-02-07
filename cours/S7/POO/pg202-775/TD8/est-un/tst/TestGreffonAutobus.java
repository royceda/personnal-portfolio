package tec;

class TestGreffonAutobus{

    public void testdemanderPlaceAssise(){
	FausseCollecte collecte = new FausseCollecte();
    	GreffonAutobus gref = new GreffonAutobus(1, 2, collecte);
    	Passager mec = new PassagerStandard("mohammed", 8);
	gref.demanderPlaceAssise(mec);
	assert collecte.messages.getLast() == "une entree";
    }

    public void testDemanderSortie(){
	FausseCollecte collecte = new FausseCollecte();
    	GreffonAutobus gref = new GreffonAutobus(1, 2, collecte);
	Passager mec = new PassagerStandard("mohammed",2);
	gref.demanderPlaceAssise(mec);
	gref.demanderSortie(mec);
    	assert collecte.messages.getLast() == "une sortie";
    }

    public void testdemanderPlaceDebout(){
	FausseCollecte collecte = new FausseCollecte();
    	GreffonAutobus gref = new GreffonAutobus(1, 2, collecte);
    	Passager mec = new PassagerStandard("mohammed", 8);
	gref.demanderPlaceDebout(mec);
	assert collecte.messages.getLast() == "une entree";
    }
    
    public void testAllerArretSuivant() throws TecInvalidException{
	FausseCollecte collecte = new FausseCollecte();
    	GreffonAutobus gref = new GreffonAutobus(1, 2, collecte);
	Passager mec = new PassagerStandard("mohammed",2);
	try{
	    gref.allerArretSuivant();
	}
	catch(TecInvalidException e) {}
    	assert collecte.messages.getLast() == "changer arret";
    }
}
