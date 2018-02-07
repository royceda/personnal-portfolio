package tecb;
import tecb.Ville;

class Capitale extends Ville
{
    //attributs
    private String monument;

    //Constructeur
    public Capitale()
    {
	super(); //appelle le constructeur de la classe mere
	monument = "Inconnu";
    }

    public Capitale( String pnomVille, String pnomPays, int pnbHabitant, String pmonument)
    {
	super(pnomVille, pnomPays, pnbHabitant);
	this.monument = pmonument;
    }


    /*--------getter-----*/
    private String getMonument()
    {
	return monument;

    }



    /*--------Methodes------------*/
    public void print()
    {
	super.print();
	System.out.println("monument: " + this.monument + "\n\n");
    }

}
