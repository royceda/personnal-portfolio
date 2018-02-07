import tec.Transport;
import tec.Usager;
import tec.FabriqueTec;

class Simple {

  /*
   * Affiche les etats d'un usager et d'un transport.
   * Sur un parametre de type Object, la methode println()
   * utilise la methode toString().
   * La methodes toString() doit etre redefinie dans les
   * deux classes PassagerStandard et Autobus.
   */
  static private void deboguerEtat (Transport t, Usager p) {
    System.out.println(p);
    System.out.println(t);
  }

  static public void main (String[] args) {
    Transport serenity = tec.FabriqueTec.faireAutobus(1,2);

    Usager kaylee = tec.FabriqueTec.fairePassagerStandard("Kaylee", 5);

    serenity.allerArretSuivant();
    // debogue
    System.out.println(serenity);

    kaylee.monterDans(serenity);

    Usager jayne = tec.FabriqueTec.fairePassagerStandard("Jayne", 4);
    jayne.monterDans(serenity);

    serenity.allerArretSuivant();
    // debogue
    System.out.println(serenity);
    System.out.println(kaylee);
    System.out.println(jayne);

    Usager inara = tec.FabriqueTec.fairePassagerStandard("Inara", 5);
    inara.monterDans(serenity);

    serenity.allerArretSuivant();
    // debogue
    System.out.println(serenity);
    System.out.println(kaylee);
    System.out.println(jayne);
    System.out.println(inara);

    serenity.allerArretSuivant();
    // debogue
    System.out.println(serenity);
    System.out.println(kaylee);
    System.out.println(jayne);
    System.out.println(inara);

    serenity.allerArretSuivant();
    // debogue
    System.out.println(serenity);
    System.out.println(kaylee);
    System.out.println(jayne);
    System.out.println(inara);
  }
}

/* Resultat de l'execution.
[arret:1, assis:0, debout:0]
[arret:2, assis:1, debout:1]
Kaylee assis
Jayne debout
[arret:3, assis:1, debout:2]
Kaylee assis
Jayne debout
Inara debout
[arret:4, assis:1, debout:1]
Kaylee assis
Jayne dehors
Inara debout
[arret:5, assis:0, debout:0]
Kaylee dehors
Jayne dehors
Inara dehors
*/
