class RunnableDemo implements Runnable {
    private Thread t;
    private String threadName;
   
    RunnableDemo( String name){
	threadName = name;
	System.out.println("Creating " +  threadName );
    }

    public void run() {
	System.out.println("Running " +  threadName +"\n" );
	try {
	    for(int i = 10; i > 0; i--) {
		System.out.println("Thread: " + threadName + ", " + i);
		// Let the thread sleep for a while.
		Thread.sleep(50);
	    }
	} catch (InterruptedException e) {
	    System.out.println("Thread " +  threadName + " interrupted.");
	}
	System.out.println("\nThread " +  threadName + " exiting.");
    }
    
    public void start ()
    {
	System.out.println("Starting " +  threadName );
	if (t == null)
	    {
		t = new Thread (this, threadName);
		t.start ();
	    }
    }

}