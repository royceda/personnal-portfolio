package aqua.view;
import java.util.regex.Pattern;
import java.awt.Toolkit;
import java.awt.Dimension;

public class Entity {
    private int posX;
    private int posY;
    private String name;
    private String type;
    private int width;
    private int height;

    public Entity(int x, int y,int w,int h, String n){
	int px = (int) Toolkit.getDefaultToolkit().getScreenSize().getWidth();
	int py = (int) Toolkit.getDefaultToolkit().getScreenSize().getHeight();
	//System.out.println("px =" + px + " ; py =" +py);
	this.posX=(x*px)/205;
	this.posY=(y*py)/230;
	//System.out.println("posx =" + posX + " ; posy =" +posY);
    this.width=w;
    this.height=h;
    this.name=n;
    this.type= this.name.replaceAll("\\d", "");
    }

    public int getX(){
	return this.posX;
    }

    public int getY(){
	return this.posY;
    }

    public void setPosX(int x){
	this.posX=x;
    }

    public void setPosY(int y){
	this.posY=y;
    }

    public int getW(){
    return this.width;
    }

    public int getH(){
    return this.height;
    }

    /*public void setPosW(int x){
    this.posX=x;
    }

    public void setPosY(int y){
    this.posY=y;
    }*/


   /* public int getId(){
        return this.id;
    }*/

    public String getType(){
        return this.type;
    }

    public String getName(){
        return this.name;
    }
}
