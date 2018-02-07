package aqua.view;

import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.util.LinkedList;
import java.awt.BorderLayout;


public class Aquarium extends JPanel {

    private int aquaWidth;
    private int aquaHeight;
    private final Color aquaColor = new Color(0, 153, 255);
    private LinkedList<Fish> fishList;
    //private LinkedList<Fish> fishesToAdd;
    private  static  final  long serialVersionUID =  1350092881346723535L;

    public Aquarium(Dimension d){
        this.aquaWidth=d.width;
        this.aquaHeight=d.height;
        d.setSize(aquaWidth, aquaHeight);
        this.setPreferredSize(d);
        this.setBackground(aquaColor);
        fishList=new LinkedList<Fish>();
	    }

    public void paintComponent(Graphics g){
        super.paintComponent(g);

        for (Fish f: this.fishList){
            f.paintComponent(g);
            //this.add(f.getLab(),BorderLayout.CENTER);
        }
    }

    public LinkedList<Fish> getFishList(){
        return this.fishList;
    }

    public void addFishInList(Fish f){
        this.fishList.add(f);
    }


    public void updateAqua(LinkedList<Fish> fishesReceived){
	while (!this.fishList.isEmpty()) {
	    this.fishList.removeFirst();
	}
	// Assert que fishList est vide
	for(Fish f1: fishesReceived){
	    fishList.add(f1);
	}
        this.repaint();
    }


    public void delFish(String name){
        for(Fish f: this.fishList){
            if(f.getName().equals(name))
		this.fishList.remove(f);
        }
    }

    /*public void startFish(String name){
      int index;
      for(Fish f: this.fishList){
      if(f.getName().equals(name))
      f.start();
      }
      }*/

}
