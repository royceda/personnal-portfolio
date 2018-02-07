class berline extends voiture
{
    public berline()
    {
	this.couleur = "Rouge";

    }

    void vroum()
    {
	System.out.println("je roule sur autoroute");
	System.out.println(this.couleur);
    }

}
