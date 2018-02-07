

public class serie5{
    

    public static void main(String[] args){

	//	Thread[] threads = new threads[4];
	
	Thread[] threads = new Thread[4];
	for ( int i = 0; i < 3; i++ ) {
	    // threads[i] = new Thread( new Runnable { System.out.println("Hello from a thread"); } );
	    threads[i].start();
	}
	
	for ( int i = 0; i < 3; i++ ) {
	    threads[i].join();
	}
    }
}


