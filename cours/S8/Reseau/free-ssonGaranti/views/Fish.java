package aqua.view;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.JComponent;
//import java.io.Serializable;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.awt.BasicStroke;
import java.awt.Color;
import java.io.File;
import javax.imageio.ImageIO;
import java.io.IOException;


public class Fish extends JComponent {

    private BufferedImage fishImage= null;
    private Entity entity;
    private int posX;
    private int posY;
    private boolean started;//has the fish already started
    private  static  final  long serialVersionUID =  1350092881346723535L;

    public Fish(Entity e){
        this.entity=e;
        this.posX=e.getX();
        this.posY=e.getY();
        setImage(this.entity.getType()+".jpg");
        this.started= false;
    }

    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g.create();
        g2d.translate(this.posX, this.posY);
        g2d.setStroke(new BasicStroke(1));
        g2d.drawImage(this.fishImage,this.getX(), this.getY(), this.entity.getW(),this.entity.getH(), null);
        System.out.println("draw Done at " +this.getX()+" "+this.getY()+"\n");
        //Utilities.writeFile("draw Done at " +this.getX()+" "+this.getY()+"\n", "test.txt");
    }

    public void setImage(String image){
        boolean test = true;
        try{
            this.fishImage=ImageIO.read(new File(image));
        } catch (IOException ex) {
            System.out.println(image);
            System.out.println(this.fishImage);
            System.out.println("Execption caugth\n");
            test = false;

        }
        if (!test) {
            try{
                this.fishImage=ImageIO.read(new File("defaut_fish.jpg"));
                System.out.println("image défault");
            }
            catch (IOException ex2) {
                System.out.println("Execption caugth: Poisson par défaut\n");
            }
        }
    }


    public Image getImage(){
        return this.fishImage;
    }


    public void update(){
        this.posX=this.entity.getX();
        this.posY=this.entity.getY();
    }

    public int getX(){
        return this.posX;
    }

    public int getY(){
        return this.posY;
    }

    public Entity getEntity(){
        return this.entity;
    }
    public void setPosition(int x, int y){
        this.entity.setPosX(x);
        this.entity.setPosY(y);
    }

    /*public boolean getIsStarted(){
    return this.started;
}

public void start(){
this.started=true;
}*/


}
