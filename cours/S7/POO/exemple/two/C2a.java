package two;

import one.C;

public class C2a{
    String nom;
	
    public C2a(String nom){this.nom=nom;}
	
    public String toString(){return "("+C.className(this)+")"+nom;}

    public void m(){
        C x2a = new C("x2a");
        System.out.println(this+".m");
        //x2a.b();   accès protégé ni dans le package ni par héritage
        //x2a.c();   accès par défaut interdit dans un autre package
        //x2a.d();   accès privé interdit en dehors de la classe
    }
}
