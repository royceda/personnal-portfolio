package two;

import one.C;

public class C2a{
    String nom;
	
    public C2a(String nom){this.nom=nom;}
	
    public String toString(){return "("+C.className(this)+")"+nom;}

    public void m(){
        C x2a = new C("x2a");
        System.out.println(this+".m");
        //x2a.b();   acc�s prot�g� ni dans le package ni par h�ritage
        //x2a.c();   acc�s par d�faut interdit dans un autre package
        //x2a.d();   acc�s priv� interdit en dehors de la classe
    }
}
