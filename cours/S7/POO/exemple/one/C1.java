package one;

public class C1 extends C {

    public C1(String nom){super(nom);}

    public void m(){
        System.out.println(this+".m");
        b();
        c();
    }
};
