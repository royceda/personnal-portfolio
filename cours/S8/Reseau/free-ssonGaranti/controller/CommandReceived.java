package aqua.controller;
import aqua.view.View;
import java.net.*;
import java.io.*;


//Ceci importe la classe Scanner du package java.util
import java.util.Scanner;
//Ceci importe toutes les classes du package java.util
import java.util.*;
import java.util.regex.Pattern;

public class CommandReceived {
    String toWrite = null;
    View v;
    Socket socket;

    public CommandReceived(View v, Socket socket){
        this.v=v;
        this.socket=socket;
    }

    protected void rcvAll(String str) {
        if (str != null) {
            if(str.length() != 0 && str.charAt(0) == '[') {
                String[] allFishes = str.split(";");
                v.removeAllFishes();
                for (String s: allFishes) {
                    rcvOne(s);
                }
                v.update();
            }
        }
    }

    protected void rcvOne(String str) {
        if (str != null) {
            String tmp = new String(str);
            tmp = tmp.replaceAll("\\[", "");
            tmp = tmp.replaceAll("\\]", "");
            tmp = tmp.replaceAll(" at ", " ");
            tmp = tmp.replaceAll(",", "");
            String first = getFirstWord(tmp);
            System.out.println(first);
            if (first != null && getRest(tmp)!= null) {
                String depart = getFirstWord(getRest(tmp));
                System.out.println("depart = "+ depart);
                String depart_x = depart.split("x")[0];
                String depart_y = depart.split("x")[1];

                String rectangle = getFirstWord(getRest(getRest(tmp)));
                String rectangle_x = rectangle.split("x")[0];
                String rectangle_y = rectangle.split("x")[1];
                v.addFish(first, Integer.parseInt(depart_x), Integer.parseInt(depart_y), Integer.parseInt(rectangle_x), Integer.parseInt(rectangle_y));
            }
        }
    }

    private String getFirstWord(String text) {
        if (text.indexOf(' ') > -1) { // Check if there is more than one word.
            return text.substring(0, text.indexOf(' ')); // Extract first word.
        } else {
            return text; // Text is the first word itself.
        }
    }

    private String getRest(String text) {
        if (text.indexOf(' ') > -1) { // Check if there is more than one word.
            return text.substring(text.indexOf(' ') + 1, text.length()); // Extract first word.
        } else {
            text = null;
            return text; // Text is the first word itself.
        }
    }

    // protected void write(String str){
    //
    //     String firstWord = getFirstWord(str);
    //     String secondWord=null;
    //     switch (firstWord){
    //         case "addFish":
    //         second = getRest(str);
    //         addFish(second);
    //         break;
    //         case "delFish":
    //         secondWord = getRest(str);
    //         delFish(secondWord);
    //         break;
    //         case "startFish":
    //         //startFish(); a faireeeeeeeeee salope
    //         break;
    //         case "bye":
    //         bye();
    //         break;
    //         default:
    //         toWrite= "-> NOK";
    //     }
    // }
    //
    // public void addFish(String fish){
    //     String tmp = null;
    //     String at = null;
    //     String depart = null;
    //     String rectangle = null;
    //     String name = null;
    //     String type = null;
    //     String depart_x = null;
    //     String depart_y = null;
    //     String rectangle_x = null;
    //     String rectangle_y = null;
    //     String deplacement = null;
    //
    //     //name  = getFirstWord(fish);
    //     type = name.replaceAll("\\d", "");
    //     //tmp = getRest(fish);
    //
    //     at = getFirstWord(tmp);
    //     tmp = getRest(tmp);
    //
    //     depart = getFirstWord(tmp);
    //     depart = depart.replaceAll(",", "");
    //     depart_x = depart.split("x")[0];
    //     depart_y = depart.split("x")[1];
    //     tmp = getRest(tmp);
    //
    //     rectangle = getFirstWord(tmp);
    //     rectangle = rectangle.replaceAll(",", "");
    //     rectangle_x = rectangle.split("x")[0];
    //     rectangle_y = rectangle.split("x")[1];
    //     tmp = getRest(tmp);
    //
    //     deplacement = getFirstWord(tmp);
    //     tmp = getRest(tmp);
    //
    //     toWrite ="OK";
    //
    //     this.v.addFish(name, Integer.valueOf(depart_x), Integer.valueOf(depart_y), Integer.valueOf(rectangle_x), Integer.valueOf(rectangle_y));
    //
    // }
    //
    //
    // public void delFish(String fish){
    //     v.delFish(fish);
    // }
    //
    // public void startFish(String fish){
    //     v.startFish(fish);
    // }
    //
    // private String getFirstWord(String text) {
    //     if (text.indexOf(' ') > -1) { // Check if there is more than one word.
    //         return text.substring(0, text.indexOf(' ')); // Extract first word.
    //     } else {
    //         return text; // Text is the first word itself.
    //     }
    // }
    //
    // private String getRest(String text) {
    //     if (text.indexOf(' ') > -1) { // Check if there is more than one word.
    //         return text.substring(text.indexOf(' ') + 1, text.length()); // Extract first word.
    //     } else {
    //         text = null;
    //         return text; // Text is the first word itself.
    //     }
    // }


    public void bye(){
        try {
            this.socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


}
