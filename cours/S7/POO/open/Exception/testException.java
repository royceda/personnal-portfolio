public class testException {

    public static void main(String[] args) {	
	int i = 10;
	int j = 0;
	try{
	    System.out.println(i/j);
	}
	catch(ArithmeticException e){
	    System.out.println("Division par zero");
	    System.out.println("message de e"+e.getMessage());
	}
	finally{ //teste pour une connexion a une BD par exemple
	    System.out.println("on a test la division par 0");
	}
	System.out.println("OK !!");
    }
}

/*toujours un try et au moins un catch

  Par defaut la JVM, capture toute les exceptions & affiche un message d'erreur. */
