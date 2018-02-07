package tec;

class TestJaugeNaturel {
    //Test si estVert() est vrai
    public void testDansIntervalle1() {
	JaugeNaturel aJauge = new JaugeNaturel(67899,100);
	assert aJauge.estBleu() == false;
	assert aJauge.estVert() == true;
	assert aJauge.estRouge() == false;
    }
    
    //Test quand départ supérieur VigieMax
    public void testDansIntervalle2() {
	JaugeNaturel aJauge = new JaugeNaturel(100,67899);
	assert aJauge.estBleu() == false;
	assert aJauge.estVert() == false;
	assert aJauge.estRouge() == true;
    }

    //Test quand départ = vigieMax
    public void testDansIntervalle3() {
	JaugeNaturel aJauge = new JaugeNaturel(100,100);
	assert aJauge.estBleu() == false;
	assert aJauge.estVert() == false;
	assert aJauge.estRouge() == true;
    }

    //Test quand départ négatif
    public void testDansIntervalle4() {
	JaugeNaturel aJauge = new JaugeNaturel(67899,-5);
	assert aJauge.estBleu() == true;
	assert aJauge.estVert() == false;
	assert aJauge.estRouge() == false;
    }

    //Test quand départ = 0
    public void testDansIntervalle5() {
	JaugeNaturel aJauge = new JaugeNaturel(67899, 0);
	assert aJauge.estBleu() == true;
	assert aJauge.estVert() == true;
	assert aJauge.estRouge() == false;
    }

    //Test incrementer
    public void testDansIntervalle6() {
	JaugeNaturel aJauge = new JaugeNaturel(101, 100);
	assert aJauge.estVert() == true;
	assert aJauge.estRouge() == false;
	assert aJauge.estBleu() == false;
	aJauge.incrementer();
	assert aJauge.estVert() == false;
	assert aJauge.estRouge() == true;
	assert aJauge.estBleu() == false;
    }
    
    public void testDansIntervalle7() {
	JaugeNaturel aJauge = new JaugeNaturel(100, 101);
	//System.out.println(aJauge.toString());
	assert aJauge.estVert() == false;
	assert aJauge.estRouge() == true;
	assert aJauge.estBleu() == false;
	aJauge.decrementer();
	assert aJauge.estVert() == false;
	assert aJauge.estRouge() == true;
	assert aJauge.estBleu() == false;
	aJauge.decrementer();
	assert aJauge.estVert() == true;
	assert aJauge.estRouge() == false;
	assert aJauge.estBleu() == false;
    }

    public void lancer() {
	int cpt = 0;
	testDansIntervalle1();
	cpt++;
	System.out.println(".");
	testDansIntervalle2();
	cpt++;
	System.out.println(".");
	testDansIntervalle3();
	cpt++;
	System.out.println(".");
	testDansIntervalle4();
	cpt++;
	System.out.println(".");
	testDansIntervalle5();
	cpt++;
	System.out.println(".");
	testDansIntervalle6();
	cpt++;
	System.out.println(".");
	testDansIntervalle7();
	cpt++;
	System.out.println(".");
	System.out.println("OK " + cpt);
    }
}
