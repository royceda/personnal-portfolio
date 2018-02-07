

class TestTelecommande {
  void testAction() {
    // initialisation des objets factices du test
    PorteCharniere[] faux = {null,
			     new PorteCharniere(),
			     new PorteCharniere(PorteCharniere.OUVERTE),
			     new PorteCharniere()}; //3
    
    // initialisation de l'objet à tester
    Telecommande tele = new Telecommande(10);
      
    /*******************************************/
    for (int i = 1; i <= 3; i++)
      tele.positionner(faux[i]);
    
    tele.activer(3);

    // test interaction 
    assert "ouvrir" == faux[3].messages.getLast() : "ouvrir 3";
    
    assert 0 == faux[2].messages.size() : "faux 2";

    /*******************************************/
    tele.desactiver(2);

    // test interaction 
    assert "fermer" == faux[2].messages.getLast() : "fermer 2";

    assert 0 == faux[1].messages.size() : "faux 1";
    assert 1 == faux[3].messages.size() : "faux 3";
  }

  void testDesactiverTout() {
    // initialisation des objets factices du test
    PorteCharniere[] faux = {null,
			     new PorteCharniere(PorteCharniere.OUVERTE),
			     new PorteCharniere(),
			     new PorteCharniere(PorteCharniere.OUVERTE),
			     new PorteCharniere()}; //4
    
    // initialisation de l'objet à tester
    Telecommande t = new Telecommande(4);

    for (int i = 1; i <= 4; i++)
      t.positionner(faux[i]);

    faux[1].messages.clear(); // ici pas necessaire
    
    /*******************************************/
    t.desactiver();

    // test interaction 
    for (int i = 1; i <= 3; i++) {
      if (2 == i) {
	assert 0 == faux[i].messages.size() : "faux " + i;
      }
      else {
	assert "fermer" == faux[i].messages.getLast() : "fermer "+ i;
      }
    }
  }

  static public void main(String[] argv) {
    boolean estMisAssertion = false;
    assert estMisAssertion = true;

    if (!estMisAssertion) {
      System.out.println("Execution impossible sans l'option -ea");
      return;
    }

    int nbTest = 0;
    TestTelecommande tst = new TestTelecommande();

    System.out.print('.'); nbTest++;
    tst.testAction();

    System.out.print('.'); nbTest++;
    tst.testDesactiverTout();
    
    System.out.println("OK(" + nbTest + "):" + tst.getClass().getName());
  }
}
