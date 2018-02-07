

public class HelloRunnable implements Runnable {

    public static int i = 0;

    public void run() {
	i++;
        System.out.println("Hello from a thread! " +i);
    }

    public static void main(String args[]) {
        Thread[] th = new Thread[4];
	for(int i = 0; i < 4; ++i) {
	    th[i] = new Thread(new HelloRunnable());
	    th[i].start();	
	}
	/*
	for(int i = 0; i < 4; ++i) 
	th[i].join();*/
    }

}



