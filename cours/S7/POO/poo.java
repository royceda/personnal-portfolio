class Lady {
    public void laRoseDeversailles() {
	this.genre();
    }
    
    protected static void genre() {
	System.out.println("Marquise");
    }
}


class Oscar extends Lady {
    protected static void genre() {
	System.out.println("Capitaine");
    }
}

class LadyOscar {
    private static void affiche(Lady l) {
	l.laRoseDeversailles();
    }
			
    public static void main (String[] args) {
	affiche(new Oscar());
    }
}
