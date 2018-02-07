package tecb;



public class Ville
{
    public static int nbInstances = 0;
    protected static int nbinstacesBis = 0;

    protected String nomVille;
    protected String nomPays;
    protected int nbHabitant;
    protected char categorie;

    //Constructeur par defaut
    public Ville()
    {
	System.out.println("\nConstruction d'une ville.. ");
	nomVille = "inconnu";
	nomPays = "inconnu";
	nbHabitant = 0;
	this.setCategorie();
    }

    //Constructeur avec options, en surcharge
    public Ville(String pnomVille, String pnomPays, int pnbHabitant)
    {
	System.out.println("\nConstruction d'une ville...");
	nomVille = pnomVille;
	nomPays = pnomPays;
	nbHabitant = pnbHabitant;
	this.setCategorie();
    }
    
    //Methodes associees
    public void print()
    {
	System.out.println("nom de la ville: " + getNomVille());
	System.out.println("nom du pays: " + getNomPays());
	System.out.println("nombre d'habitant: " + getNbHabitant() + "\n");
    }

    /*------------Getters / Accesseur------------*/
    public String getNomVille()
    {
	return nomVille;
    }
    
    public String getNomPays()
    {
	return nomPays;
    }
    
    public int getNbHabitant()
    {
	return nbHabitant;
    }

    /*-----------Setters / Mutateurs-------------*/
    public void setNomVille(String pNomVille)
    {
	nomVille = pNomVille;
    }

    public void setNomPays(String pNomPays)
    {
	nomPays = pNomPays;
    }

    public void setNbHabitant(int pNbHabitant)
    {
	nbHabitant = pNbHabitant;
    }
    
    public void setCategorie()
    {
	int bornesSuperieures[] = {0, 1000, 10000, 100000, 500000, 1000000, 5000000, 10000000};
	char categories[] = {'?', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	
	int i = 0;
	while (i < bornesSuperieures.length && this.nbHabitant > bornesSuperieures[i])
	    i++;
	
	this.categorie = categories[i];
    }
}
