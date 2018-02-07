
class UnScenario {
  public static void main (String[] args) {
    PorteCharniere p1 = new PorteCharniere();
    PorteCharniere p2 = new PorteCharniere();
    PorteCharniere p3 = new PorteCharniere();
    System.out.println("p1.estFerme: " + p1.estFerme());


    Telecommande tele = new Telecommande(3);    
    tele.positionner(p1);
    tele.positionner(p2);
    tele.positionner(p3);

    
    System.out.println("\ndesactiver tout");
    tele.desactiver();

    System.out.println("p1.estFerme: " + p1.estFerme());
    System.out.println("p2.estFerme: " + p2.estFerme());
    System.out.println("p3.estFerme: " + p3.estFerme());

    System.out.println("\nactiver p1 et p3");
    tele.activer(1);
    tele.activer(3);

    System.out.println("p1.estFerme: " + p1.estFerme());
    System.out.println("p2.estFerme: " + p2.estFerme());
    System.out.println("p3.estFerme: " + p3.estFerme());
  }
}
