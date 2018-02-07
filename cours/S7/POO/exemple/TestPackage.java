//  essai de visibilité des identificateurs avec les packages
//  avec l'exemple de Lewis&Loftus (ed 1) p 599, (ed 2) p 559
//	
//  attention: 
//  il y a une erreur dans L&L à propos de l'appel à 
//  b() dans un objet d'un autre package que one:
//  L&L prétend que ce n'est pas accessible mais ça l'est... (voir two.C2)

import one.*;
import two.*;

public class TestPackage {
    static C   x  = new C("x");
    static C1  y  = new C1("y");
    static C1a y1 = new C1a("y1");
    static C2  z  = new C2("z");
    static C2a z1 = new C2a("z1");
	
    public static void main(String args[]) {
	// appels directs (les appels interdits sont en commentaires...)
        // public
        x.a();
        y.a();
        z.a();
		
        /// protected  inaccessibles dans un autre package
        // x.b();  
        // y.b();
        // z.b();
		
        /// défaut     inaccessibles dans un autre package
        // x.c();
        // y.c();
        // z.c();
		
        /// private    inaccessibles dans un autre package
        // x.d();   
        // y.d();
        // z.d();
	
	// appels indirects
        y.m();
        z.m();
        y1.m();
        z1.m();
    }
}

/* résultats imprimés par ces appels

(one.C)x.a
(one.C1)y.a
(two.C2)z.a
(one.C1)y.m
(one.C1)y.b
(one.C1)y.c
(two.C2)z.m
(two.C2)z.b
(one.C1a)y1.m
(one.C)x1a.b
(one.C)x1a.c
(two.C2a)z1.m

*/
