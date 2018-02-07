class Test
{
    public static void main(String[] args)
    {
        Animal wolf = new Loup();
	System.out.println(wolf.toString());
	wolf.crier();
	Animal cat = new Chat();
	System.out.println(cat.toString());
	cat.crier();
    }
}
