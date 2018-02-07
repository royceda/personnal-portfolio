package tec;

class TestEtatPassager
{
    public void test1()
    {
	final EtatPassager e = EtatPassager.construct();
	assert e.estAssis() == false : "test1 échoué, estAssis";
	assert e.estDebout() == false : "test1 échoué, estDebout";
	assert e.estExterieur() == true : "test1 échoué, estExterieur";
	assert e.estInterieur() == false : "test1 échoué, estInterieur";
    }


    public void testAssis()
    {
	EtatPassager e = EtatPassager.construct();
	assert e.estAssis() == false : "testAssis échoué, estAssis1";
	e = e.assis();
	assert e.estAssis() == true : "testAssis échoué, estAssis2";
    }

    public void testDebout()
    {
	EtatPassager E = EtatPassager.construct();
	assert E.estDebout() == false : "testDebout échoué, estDebout1";
	E = E.debout();
	assert E.estDebout() == true : "testDebout échoué, estDebout2";
    }

    public void testDehors()
    {
	EtatPassager e = EtatPassager.construct();
	assert e.estExterieur() == true : "testDehors échoué, estExterieur1";
	assert e.estInterieur() == false : "testDehors échoué, estInterieur1";
	e = e.dehors();
	assert e.estExterieur() == true : "testDehors échoué, estExterieur2";
	assert e.estInterieur() == false : "testDehors échoué, estInterieur2";
    }
}
