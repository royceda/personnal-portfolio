package ex;


public class NombreHabitantException extends Exception {
    
    public NombreHabitantException(){
	System.out.println("Exception sur nombre d'habitant negatif");
    }
}
