package tec;

class LancerTests {
    public static void main(String... args) {
	boolean estMisAssertion = false;
	assert estMisAssertion = true;

	if (!estMisAssertion) {
	    System.out.println("Execution impossible sans l'option -ea");
	    return;
	}

	System.out.println("Tests EtatPassager :");
	TestEtatPassager aTestPassager = new TestEtatPassager();
	aTestPassager.lancer();

	System.out.println("Tests PassagerStandard :");
	TestPassagerStandard aTestPassagerStandard = new TestPassagerStandard();
	aTestPassagerStandard.lancer();
    }
}
