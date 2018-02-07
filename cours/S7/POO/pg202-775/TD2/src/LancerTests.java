package tec;

class LancerTests {
  public static void main(String... args) {
    boolean estMisAssertion = false;
    assert estMisAssertion = true;

    if (!estMisAssertion) {
      System.out.println("Execution impossible sans l'option -ea");
      return;
    }

    // comment lancer les tests ?
    //System.out.println("Il reste à faire les tests unitaires fonctionnels...");

    System.out.println("Phase de Tests :");
    TestEtatPassager aTestPassager = new TestEtatPassager();
    aTestPassager.lancer();

    TestJaugeNaturel aTestJauge = new TestJaugeNaturel();
    aTestJauge.lancer();
  }
}
