package two;

public class C2 extends one.C{

    public C2(String nom){super(nom);}

    public void m(){
        System.out.println(this+".m");
        b();
        //c();  accès par défaut interdit dans un autre package
    }
}

