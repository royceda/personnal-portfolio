import ex.NombreHabitantException;
import ex.NomVilleException;


public class sdz1{
    
    public static void main(String[] args){
	System.out.println("Cas defavorable");
	try{
	    Ville da = new Ville("LH", -12, "FR");
	}
	catch(NombreHabitantException | NomVilleException  e){
	    System.out.println("problems:  "+ e);
	}
	finally{
	    System.out.println("on test.....\n");
	}

	System.out.println("Cas favorable");
	try{
	    Ville da = new Ville("Le Havre", 12, "FR");
	}
	catch(NombreHabitantException | NomVilleException e){
	    System.out.println("problems:  "+ e);
	}
	finally{
	    System.out.println("on test.....");
	}
	
    }
}
