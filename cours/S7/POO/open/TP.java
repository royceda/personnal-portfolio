import java.util.Scanner;


public class TP
{
    public static void main(String[] args)
    {
	/*	
	System.out.println("taper un mot");
	Scanner sc = new Scanner(System.in);

	StringBuffer str = new StringBuffer( sc.nextLine());
	System.out.println("mot: " + str);

	System.out.println("taper un nombre");
	Scanner sci = new Scanner(System.in);
	int n = sci.nextInt();
	System.out.println("nombre: " + n);
	*/

	System.out.println("1. F -> C");
	System.out.println("2. C -> F");	
	Scanner c = new Scanner(System.in);
	int choix = c.nextInt();
	double t, R =0;
	String str = new String("O");
	
	
	while(str.equals("O"))
	    {	
		if (choix > 2)
		    {
			System.out.println(" Choix inexistant");
		    }
		else 
		    {			
			System.out.println("temperature");
			t = c.nextDouble();
			R = 0.0;
			if( choix == 1)
			    {
				R = arrondi( ((t-32)*5)/9, 3);
				System.out.println("resultat " + R);
				
			    }
			else 
			    if( choix == 2)
				{
				    R = arrondi( (9*t)/5+32, 3);
				    System.out.println("resultat " + R);
				    
				}
			
		    }
		System.out.println("restart  (O/N)");
		str = c.nextLine();
				
	    }
    }
    
    public static double arrondi(double A, int B)
    {
	return (double) ( (int) (A * Math.pow(10,B) + .5)) / Math.pow(10, B);
    }
    
}
