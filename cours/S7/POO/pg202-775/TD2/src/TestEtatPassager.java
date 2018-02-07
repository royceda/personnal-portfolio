package tec;

class TestEtatPassager
{
    public boolean test1()
    {
	System.out.println(".");
	EtatPassager e = new EtatPassager();

	assert e.estAssis()     == false; //
	assert e.estDebout()    == false; //
	assert e.estExterieur() == true;  //
	assert e.estInterieur() == false; //

	System.out.println("test 1:\t ok");
	return true;
    }


    public boolean testAssis()
    {
	System.out.println(".");
	EtatPassager e = new EtatPassager();
	assert e.estAssis() == false; //
	e.assis();
	//assert e.estAssis() == true;
	System.out.println("Test Assis:\t ok");
	return true;
    }

    public boolean testDebout()
    {
	System.out.println(".");
	EtatPassager E = new EtatPassager();
	assert E.estDebout() == false;
	E.debout();
	//assert E.estDebout() == true;
	System.out.println("Test Debout:\t ok");
	return true;
    }

    public boolean testDehors()
    {
	System.out.println(".");
	EtatPassager e = new EtatPassager();
	assert e.estExterieur() == true;
	assert e.estInterieur() == false;
	e.dehors();
	/*
	assert E.estExterieur() == false;
	assert E.estInterieur() == true;
	*/
	System.out.println("Test Dehors: ok");
	return true;
    }


    public boolean testToString()
    {
	EtatPassager e = new EtatPassager();
	System.out.println("Etat de To String:" + e.toString());
	return true;
	
    }
    
    public void lancer()
    {
	int k = 0;
	if (test1())
	    k++;
	if (testAssis())
	    k++;
	if (testDebout())
	    k++;
	if (testDehors())
	    k++;
	if (testToString())
	    k++;
	System.out.println("Tests aboutis (" + k +"/5)");
    }
}
