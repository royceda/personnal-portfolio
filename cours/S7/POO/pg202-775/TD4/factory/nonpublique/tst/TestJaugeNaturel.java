package tec;

class TestJaugeNaturel {
    //Test si estVert() est vrai
    public void testDansIntervalle1() {
	JaugeNaturel aJauge = new JaugeNaturel(67899,100);
	assert aJauge.estBleu() == false : "testDansIntervalle1 échoué, estBleu";
	assert aJauge.estVert() == true : "testDansIntervalle1 échoué, estVert";
	assert aJauge.estRouge() == false : "testDansIntervalle1 échoué, estRouge";
    }
    
    //Test quand départ supérieur VigieMax
    public void testDansIntervalle2() {
	JaugeNaturel aJauge = new JaugeNaturel(100,67899);
	assert aJauge.estBleu() == false : "testDansIntervalle2 échoué, estBleu";
	assert aJauge.estVert() == false : "testDansIntervalle2 échoué, estVert";
	assert aJauge.estRouge() == true : "testDansIntervalle2 échoué, estRouge";
    }

    //Test quand départ = vigieMax
    public void testDansIntervalle3() {
	JaugeNaturel aJauge = new JaugeNaturel(100,100);
	assert aJauge.estBleu() == false : "testDansIntervalle3 échoué, estBleu";
	assert aJauge.estVert() == false : "testDansIntervalle3 échoué, estVert";
	assert aJauge.estRouge() == true : "testDansIntervalle3 échoué, estRouge";
    }

    //Test quand départ négatif
    public void testDansIntervalle4() {
	JaugeNaturel aJauge = new JaugeNaturel(67899,-5);
	assert aJauge.estBleu() == true : "testDansIntervalle4 échoué, estBleu";
	assert aJauge.estVert() == false : "testDansIntervalle4 échoué, estVert";
	assert aJauge.estRouge() == false : "testDansIntervalle4 échoué, estRouge";
    }

    //Test quand départ = 0
    public void testDansIntervalle5() {
	JaugeNaturel aJauge = new JaugeNaturel(67899, 0);
	assert aJauge.estBleu() == true : "testDansIntervalle5 échoué, estBleu";
	assert aJauge.estVert() == true : "testDansIntervalle5 échoué, estVert";
	assert aJauge.estRouge() == false : "testDansIntervalle5 échoué, estRouge";
    }

    //Test incrementer
    public void testDansIntervalle6() {
	JaugeNaturel aJauge = new JaugeNaturel(101, 100);
	assert aJauge.estVert() == true : "testDansIntervalle6 échoué, estVert1";
	assert aJauge.estRouge() == false : "testDansIntervalle6 échoué, estRouge1";
	assert aJauge.estBleu() == false : "testDansIntervalle6 échoué, estBleu1";
	aJauge.incrementer();
	assert aJauge.estVert() == false : "testDansIntervalle6 échoué, estVert2";
	assert aJauge.estRouge() == true : "testDansIntervalle6 échoué, estRouge2";
	assert aJauge.estBleu() == false : "testDansIntervalle6 échoué, estBleu2";
    }
    
    public void testDansIntervalle7() {
	JaugeNaturel aJauge = new JaugeNaturel(100, 101);
	//System.out.println(aJauge.toString());
	assert aJauge.estVert() == false : "testDansIntervalle7 échoué, estVert1";
	assert aJauge.estRouge() == true : "testDansIntervalle7 échoué, estRouge1";
	assert aJauge.estBleu() == false : "testDansIntervalle7 échoué, estBleu1";
	aJauge.decrementer();
	assert aJauge.estVert() == false : "testDansIntervalle7 échoué, estVert2";
	assert aJauge.estRouge() == true : "testDansIntervalle7 échoué, estRouge2";
	assert aJauge.estBleu() == false : "testDansIntervalle7 échoué, estBleu2";
	aJauge.decrementer();
	assert aJauge.estVert() == true : "testDansIntervalle7 échoué, estVert3";
	assert aJauge.estRouge() == false : "testDansIntervalle7 échoué, estRouge3";
	assert aJauge.estBleu() == false : "testDansIntervalle7 échoué, estBleu3";
    }
}
