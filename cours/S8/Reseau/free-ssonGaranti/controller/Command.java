package aqua.controller;


//Ceci importe la classe Scanner du package java.util
import java.util.Scanner;
//Ceci importe toutes les classes du package java.util
import java.util.*;
import java.util.regex.Pattern;

public class Command {

    String toSend = null;

    public Command(){
        //this.str = str;
    }

    protected void read(String str){

        String firstWord = getFirstWord(str);
        String second = null;
        switch (firstWord) {
            case "exit":
            exit();
            break;
            case "status":
            status();
            break;
            case "startFish":
            second = getRest(str);
            startFish(second);
            break;
            case "delFish":
            second = getRest(str);
            delFish(second);
            break;
            case "addFish":
            second = getRest(str);
            addFish(second);
            //System.out.println("kikoulol");
            break;
            case "getFishes":
            getFishes();
            break;
            case "getFishesContinuously":
            getFishesContinuously();
            break;
            case "hello":
            hello();
            break;
            default:
            toSend = "-> NOK : commande introuvable";
        }
    }


    public void status(){
        toSend = "status";
    }
    public void exit(){
        toSend = "exit";
    }

    public void getFishes(){
        toSend = "getFishes";
    }

    public void getFishesContinuously(){
        toSend = "getFishesContinuously";
    }

    public void hello(){
        toSend = "hello";
    }



    public void startFish(String fish){
        if (fish != null) {
            toSend = "startFish " + fish;
            //System.out.println("fishstart");
            //if doesn't exist  System.out.println("-> NOK : Poisson inexistant"); ?

        } else {
            toSend = "-> NOK : Poisson manquant";
        }
    }

    public void delFish(String fish){
        if (fish != null) {
            toSend = "delFish " + fish;
            //if doesn't exist  System.out.println("-> NOK : Poisson inexistant");
        } else {
            toSend = "-> NOK : Poisson manquant";
        }
    }

    public void addFish(String fish){

        if (fish != null) {
            //System.out.println("fishadd");
            if (fish.split(" ").length != 5){
                toSend = "-> NOK : Commande erronée";
            } else {
                String tmp = null;
                String at = null;
                String depart = null;
                String rectangle = null;
                String name = null;
                String type = null;
                String depart_x = null;
                String depart_y = null;
                String rectangle_x = null;
                String rectangle_y = null;
                String deplacement = null;

                name  = getFirstWord(fish);
                type = name.replaceAll("\\d", "");
                tmp = getRest(fish);

                at = getFirstWord(tmp);
                tmp = getRest(tmp);

                depart = getFirstWord(tmp);
                depart = depart.replaceAll(",", "");
                depart_x = depart.split("x")[0];
                depart_y = depart.split("x")[1];
                tmp = getRest(tmp);
                
                rectangle = getFirstWord(tmp);
                rectangle = rectangle.replaceAll(",", "");
                rectangle_x = rectangle.split("x")[0];
                rectangle_y = rectangle.split("x")[1];
                tmp = getRest(tmp);

                deplacement = getFirstWord(tmp);
                tmp = getRest(tmp);

                toSend = "addFish "+name + " " +type  + " " +depart_x + " " + depart_y + " " + rectangle_x + " " + rectangle_y + " " +  deplacement;

            }
            //if doesn't exist  System.out.println("-> NOK : Poisson inexistant");
        } else {
            toSend = "-> NOK : Poisson manquant";
        }
        // if (at == "at" ) {//Peut etre verification poussee plus tard!!!
        //
        // }
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
    public String result(String str) {
        toSend = null;
        read(str);
        if (toSend.split(" ").length > 2 && getFirstWord(getRest(toSend)).equals("NOK")) {

            System.out.println(toSend);
            return null;
        } else {
            return toSend;
        }
    }

}
