package aqua.controller;
import java.io.*;
import java.net.*;
import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import aqua.view.View;

/** Le processus client se connecte au site fourni dans la commande
* d'appel en premier argument et utilise le port distant 8888.
*/

public class Client extends Thread {
    static private String name = "controller.cfg";
    static int port; /*accessible au package*/
    static String ipAd;
    static BufferedReader plec;
    static PrintWriter pred;
    Socket socket;
    String toSend;

    private Scanner sc = new Scanner(System.in);
    Command c = new Command();
    CommandReceived cr;
    View v;

    public void Client() {

    }

    public void run(){
        try {
            System.out.println("port: "+portNumber());
        } catch(IOException e) {
            e.printStackTrace();
        }
        try {
	     System.out.println("ip: "+ipNumber());
            socket = new Socket(ipNumber(), portNumber());
        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("SOCKET = " + socket);

        try {
            plec = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }

        try{
            pred = new PrintWriter( new BufferedWriter( new OutputStreamWriter(socket.getOutputStream())), true);
        } catch (IOException e) {
            e.printStackTrace();
        }

        this.toSend = "bonjour localhost " + port + "\n SOCKET = " +socket+"\n";
        try {
            send_message(toSend, socket);
        } catch (Exception e) {
            e.printStackTrace();
        }
        try {
            rec_message(socket);
        } catch (Exception e) {
            e.printStackTrace();
        }
        //instanciation de l'aqua

        v = new View();
        sc = new Scanner(System.in);
        cr = new CommandReceived(v, socket);
        Thread t = new Thread (){
            @Override
            public void run () {
                String str2;
                Thread t2 = new Thread (){
                    @Override
                    public void run () {
                        String toSend;
                        for(;;) {
                            System.out.println("Choisir une commande:"); //log out puis attente de bye puis close.
                            String str = sc.nextLine();
                            toSend = c.result(str);
                            //System.out.println("Retour traitement : " + this.toSend);
                            if (toSend != null) {
                                try {
                                    send_message(toSend, socket);
                                } catch (Exception e) {
                                    e.printStackTrace();
                                }
                            }
                        }
                    }
                };

                t2.start();
                for(;;){
                    try {
                        str2 = rec_message(socket);
                        cr.rcvAll(str2);
                        //v.test();
                        if (str2 == null || str2.equals("BYE")) {
                            break;
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
                v.close();
                //t2.stop();

                // try {
                //     t2.join();
                // } catch (InterruptedException e) {
                //     e.printStackTrace();
                // }

                //bye();

            }
        };
        t.start();

        // Thread t2 = new Thread (){
        //     @Override
        //     public void run () {
        //         for(;;) {
        //             System.out.println("Choisir une commande:"); //log out puis attente de bye puis close.
        //             String str = sc.nextLine();
        //             this.toSend = c.result(str);
        //             //System.out.println("Retour traitement : " + this.toSend);
        //             if (this.toSend != null) {
        //                 try {
        //                     send_message(toSend, socket);
        //                 } catch (Exception e) {
        //                     e.printStackTrace();
        //                 }
        //                 // try {
        //                 //     str = rec_message(socket);
        //                 //     if (str.equals("bye")) {
        //                 //         //t.stop();
        //                 //         break;
        //                 //     }
        //                 // } catch (Exception e) {
        //                 //     e.printStackTrace();
        //                 // }
        //             }
        //             //
        //         }
        //         //bye();
        //
        //
        //
        //         //plec.close();
        //         //pred.close();
        //         // try {
        //         //     socket.close();
        //         // } catch (IOException e) {
        //         //     e.printStackTrace();
        //         // }
        //     }
        //
        // };
    }

    static int portNumber() throws IOException{
        BufferedReader br = new BufferedReader(new FileReader(name));
        try {
            StringBuilder sb = new StringBuilder();
            String line = br.readLine();

            String delims = "[ ]+";
            String[] tokens = line.split(delims);

            port = Integer.parseInt(tokens[2]);

        } finally {
            br.close();
        }

        //	port = 12345;
        return port;
    }


    static String ipNumber() throws IOException{
        BufferedReader br = new BufferedReader(new FileReader(name));
        try {
            StringBuilder sb = new StringBuilder();
            String line = null;
	    String[] tokens = null;
	    for(;;) {
		line = br.readLine();
		tokens = line.split(" ");
		if (tokens[0].equals("server"))
		    break;
	    }

            ipAd = tokens[2];

        } finally {
            br.close();
        }

        //	port = 12345;
        return ipAd;
    }

    static void send_message(String str, Socket sock) throws Exception{
        BufferedReader plec = new BufferedReader(new InputStreamReader(sock.getInputStream()));
        pred.println(str); //envoi du message

    }

    static String rec_message( Socket sock) throws Exception{
        String str;
        str = plec.readLine(); //lecture de echo
        System.out.println(str);
        return str;
    }

    public void bye(){
        try {
            this.socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
