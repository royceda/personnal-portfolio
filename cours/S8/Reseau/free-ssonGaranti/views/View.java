package aqua.view;

import javax.swing.JFrame;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GraphicsEnvironment;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.Toolkit;
import java.lang.InterruptedException;
import java.util.regex.Pattern;
import java.util.LinkedList;




public class View extends JFrame /*implements Updatable*/{
    private  static  final  long serialVersionUID =  1350092881346723535L;

    private int screenWidth;
    private int screenHeight;
    static private Aquarium aqua;
    private LinkedList<Fish> fishesToSend = new LinkedList<Fish>();
    Thread t;
    boolean test = false;

    public View(){
        this.setTitle("Client display");
        Rectangle bounds = GraphicsEnvironment.getLocalGraphicsEnvironment().getMaximumWindowBounds();
        this.screenWidth = bounds.width;
        this.screenHeight = bounds.height;
        this.setSize(screenWidth, screenHeight);
        this.setExtendedState(JFrame.MAXIMIZED_BOTH);

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        aqua = new Aquarium(Toolkit.getDefaultToolkit().getScreenSize());
        /*TestAqua ta = new TestAqua();
        aqua = (Aquarium) ta;
        */
        this.add(aqua, BorderLayout.CENTER);
        this.setLocation(
        new Point((bounds.width - this.getWidth()) / 2,
        (bounds.height - this.getHeight()) / 2));

        this.setVisible(true);


        //this.update();
        t = new Thread (){
            @Override
            public void run () {
                try {

                    for(;;){
                        if (test) {
                            break;
                        }
                        Thread.sleep(1000);//500 milliseconds is 1/2 second.
                        //System.out.println("test");



                        //aqua.move(i);
                        //update();
                    }
                    Thread.currentThread().join();

                } catch (InterruptedException e) {

                    // nous avons été interrompu
                    // on remet interrupted à false par l'appel à cette méthode
                    //Thread.currentThread().interrupted() ;
                }
            }
        };
        t.start();

    }

    public void update(){
        this.sendFishes();
    }


    public void test() {
        System.out.println("boooooobs");
    }

    public void removeAllFishes(){
        if (fishesToSend != null) {
	    while (!fishesToSend.isEmpty()) {
		fishesToSend.removeFirst();
	    }
        }
    }

    public void addFish(String name, int startX, int startY, int width, int height){
        Fish fishToAdd= new Fish(new Entity(startX, startY, width, height, name/*move à ajouter plus tard*/));
        fishesToSend.add(fishToAdd);
    }

    public void sendFishes(){
        View.aqua.updateAqua(fishesToSend);
    }

    public void delFish(String name){
        aqua.delFish(name);
    }

    /*
    public void startFish(String name){
    aqua.startFish(name);
}*/

public void close() {
    System.out.println("fermeture");
    this.test = true;
    Thread.currentThread().interrupt() ;
    // Thread.currentThread().stop();
    // Thread.currentThread().destroy();


}


}
