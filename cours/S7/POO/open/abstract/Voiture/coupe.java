public class coupe extends voiture implements supercar
{
    public coupe()
    {
	this.couleur = "noir";
    }

    void vroum()
    {
	System.out.println("je roule sur circuit");
	System.out.println(couleur);
    }

    public void vroumVroum()
    {
	System.out.println("je suis un supercar");
    }
}
