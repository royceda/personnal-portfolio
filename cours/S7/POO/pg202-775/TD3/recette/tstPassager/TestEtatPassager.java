package tec;

class TestEtatPassager
{
    public void test1()
    {
	System.out.println(".");
	final EtatPassager e = EtatPassager.construct();

	assert e.estAssis()     == false;
	assert e.estDebout()    == false;
	assert e.estExterieur() == true;
	assert e.estInterieur() == false;

	System.out.println("test 1:\t ok");
    }


    public void testAssis()
    {
	System.out.println(".");
	EtatPassager e = EtatPassager.construct();
	assert e.estAssis() == false;
	e = e.assis();
	assert e.estAssis() == true;
	System.out.println("Test Assis:\t ok");
    }

    public void testDebout()
    {
	System.out.println(".");
	EtatPassager E = EtatPassager.construct();
	assert E.estDebout() == false;
	E = E.debout();
	assert E.estDebout() == true;
	System.out.println("Test Debout:\t ok");
    }

    public void testDehors()
    {
	System.out.println(".");
	EtatPassager e = EtatPassager.construct();
	assert e.estExterieur() == true;
	assert e.estInterieur() == false;
	e = e.dehors();
	assert e.estExterieur() == true;
	assert e.estInterieur() == false;
	System.out.println("Test Dehors:\t ok");
    }

    public void lancer()
    {
	int k = 0;
	test1();
	k++;
	testAssis();
	k++;
	testDebout();
	k++;
	testDehors();
	k++;
	System.out.println("Tests aboutis (" + k +"/4)");
    }
}
