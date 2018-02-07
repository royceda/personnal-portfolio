package one;

public class C{
    private String nom;

    public C(String nom){this.nom=nom;}
	
    public static String className(Object o){
        return (""+o.getClass()).substring(6);
    }
	
    public String toString(){ return "("+className(this)+")"+nom; }

    public    void a(){System.out.println(this+".a");}
    protected void b(){System.out.println(this+".b");}
              void c(){System.out.println(this+".c");}
    private   void d(){System.out.println(this+".d");} 
}
