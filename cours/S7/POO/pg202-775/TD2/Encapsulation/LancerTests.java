class LancerTests {
  public static void main(String... args) {
    boolean estMisAssertion = false;
    assert estMisAssertion = true;

    if (!estMisAssertion) {
      System.out.println("Execution impossible sans l'option -ea");
      return;
    }

    System.out.println("Phase de Tests :");

    TestJaugeNaturel aTestJauge = new TestJaugeNaturel();
    aTestJauge.lancer();
  }
}
