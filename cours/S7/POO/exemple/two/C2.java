package two;

public class C2 extends one.C{

    public C2(String nom){super(nom);}

    public void m(){
        System.out.println(this+".m");
        b();
        //c();  acc�s par d�faut interdit dans un autre package
    }
}

