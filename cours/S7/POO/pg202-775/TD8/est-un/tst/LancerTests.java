package tec;

public class LancerTests {

    static private void lancer(Class c) throws Exception{
	Object o = c.newInstance();
	java.lang.reflect.Method[] mesMethodes = c.getMethods();
	int nbTest = 0;

	System.out.print(o.getClass().getName() + ": ");

	for (int i = 0; i < mesMethodes.length; i++) {
	    java.lang.reflect.Method m = mesMethodes[i];
	    if (m.getName().startsWith("test")){
		System.out.print(".");
		m.invoke(o);
		nbTest++;
	    }
	}
	System.out.println(" (" + nbTest + ")");
    }

    public static void main(String... args) {
	boolean estMisAssertion = false;
	assert estMisAssertion = true;

	if (!estMisAssertion) {
	    System.out.println("Execution impossible sans l'option -ea");
	    return;
	}

	try{
	    lancer(TestAutobus.class);
	    lancer(TestGreffonAutobus.class);
	    lancer(TestPassagerStandard.class);
	    lancer(TestPassagerStresse.class);
	    lancer(TestPassagerLunatique.class);
	    lancer(TestPassagerSportif.class);
	    lancer(TestPassagerRepos.class);
	    lancer(TestPassagerFatigue.class);
	    lancer(TestPassagerTetu.class);
	    lancer(TestCaractereAgoraphobe.class);
	    lancer(TestCaractereCalme.class);
	    lancer(TestCaractereNerveux.class);
	    lancer(TestCaracterePoli.class);
	    lancer(TestCaracterePrudent.class);
	    lancer(TestJaugeNaturel.class);
	    lancer(TestEtatPassager.class);
	}
	catch (Exception e){
	    System.out.println("Erreur lors des tests : ");
	    e.printStackTrace();
	}
    }
}
