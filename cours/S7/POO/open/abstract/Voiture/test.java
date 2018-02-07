public class test
{
    public static void main(String[] args)
    {
	voiture jaguar = new berline();
	jaguar.vroum();

	voiture b = new coupe();
	coupe benz = (coupe)b;
	benz.vroumVroum();
	benz.vroum();
	
    }
}
