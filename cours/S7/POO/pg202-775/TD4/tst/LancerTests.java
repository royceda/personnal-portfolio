package tec;

public class LancerTests {

    static private void lancer(Class c) throws Exception{
	Object o = c.newInstance();
	java.lang.reflect.Method[] mesMethodes = c.getMethods();
	int nbTest = 0;
	for (int i = 0; i < mesMethodes.length; i++) {
	    java.lang.reflect.Method m = mesMethodes[i];
	    if (m.getName().startsWith("test")){
		System.out.print(".");
		m.invoke(o);
		nbTest++;
	    }
	}
	System.out.println("(" + nbTest + "):OK: " + o.getClass().getName());
    }

    public static void main(String... args) {
	boolean estMisAssertion = false;
	assert estMisAssertion = true;

	if (!estMisAssertion) {
	    System.out.println("Execution impossible sans l'option -ea");
	    return;
	}

	try{
	    lancer(TestEtatPassager.class);
	    lancer(TestPassagerStandard.class);
	    lancer(TestJaugeNaturel.class);
	    lancer(TestAutobus.class);
	}
	catch (Exception e){
	    System.out.println("Erreur lors des tests : ");
	    e.printStackTrace();
	}
    }
}
