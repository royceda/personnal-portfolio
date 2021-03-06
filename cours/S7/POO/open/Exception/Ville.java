import ex.NomVilleException;
import ex.NombreHabitantException;

public class Ville{
    
    String nomVille;
    int nbHabitant;
    String nomPays;

    //constructeur avec propagation 
    public Ville(String pNom, int pNbHabitant, String pPays) 
	throws NombreHabitantException, NomVilleException
    {
	if(pNbHabitant < 0)
	    throw new NombreHabitantException(); //Possibilité de mettre un message d'erreur
	if (pNom.length() < 4)
	    throw new NomVilleException("Le nom est trop court"+pNom);
	else
	    {
		nomVille = pNom;
		nbHabitant = pNbHabitant;
		nomPays = pPays;
	    }
    }
    
}

  
