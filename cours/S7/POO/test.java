package bjr;


public class test
{
    

    public static void main(String[] args)
    {
	// Divers test
	int resultat = 10;
	int a = 12, b = 3;
	int c = (int)(a/b);
	//int c = a/b;

	String mot = new String("bonjour");
	mot = "bonjour Royce";


	System.out.println(c);
	System.out.println(mot);
	System.out.println("hello world, Royce " + resultat);


	//TD georgy
	String s1 = "Kalki";
	String s2 = "Kalki";

	System.out.println("egalite des char:");
	System.out.println(s1==s2);
	System.out.println(s1=="Kalki");
	/* reference vers la meme adresse == compare les adresses*/

	char valeur[] = {'K','a','l','k','i'};
	String s3 = new String(valeur);
	//int final e;
	String s4 = new String(valeur);
	
	System.out.println("egalite des char:");
	System.out.println(s3 == s4);
	System.out.println(s3 == "Kalki");
	/* verifie les adresses*/

	StringBuffer   buffer = new StringBuffer(s1);
	buffer.replace(0,10,"modified");
	System.out.println("valeur de buffer = " + buffer);

	System.out.println(s3.equals(s4));
	/* verifie le contenu*/


    }
}
