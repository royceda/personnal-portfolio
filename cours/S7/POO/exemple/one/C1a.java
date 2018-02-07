package one;

public class C1a{
    String nom;

    public C1a(String nom){this.nom=nom;}

    public String toString(){return "("+C.className(this)+")"+nom;}

    public void m(){
        C x1a = new C("x1a");
        System.out.println(this+".m");
        x1a.b();
        x1a.c();
        //x1a.d();   méthode privée
    }
}
