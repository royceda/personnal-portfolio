import java.io.*;
import java.net.*;


/** Le processus client se connecte au site fourni dans la commande 
 * d'appel en premier argument et utilise le port distant 8888.
 */

public class client{
    static int port = 8888;

    public static void main(String[] args) throws Exception{
	Socket socket = new Socket(args[0], port);
	System.out.println("SOCKET = " + socket);

	BufferedReader plec = new BufferedReader(new InputStreamReader(socket.getInputStream()));

	PrintWriter pred = new PrintWriter( new BufferedWriter( new OutputStreamWriter(socket.getOutputStream())), true);

	String str = "bojour localhost " +port;

	for(int i = 0; i < 10; ++i){
	    pred.println(str); //envoi du message
	    str = plec.readLine(); //lecture de echo
	}

	System.out.println("END");
	plec.close();
	pred.close();
	socket.close();
    }
}
