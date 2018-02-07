import java.io.*;
import java.net.*;


public class Serveur{

    static final int port = 8880;

    static public void main(String[] args) throws Exception{
	ServerSocket s = new ServerSocket(port,1);
	Socket soc = s.accept();

	//Le buffer reader
	BufferedReader plec = new BufferedReader( new InputStreamReader(soc.getInputStream()));
	
	//un printer writer 
	//en mode auto-flush
	PrintWriter pred = new PrintWriter(new BufferedWriter( new OutputStreamWriter(soc.getOutputStream())), true);


	while(true){
	    String str = plec.readLine(); //lecture du message
	    if (str.equals("END")) //Mot cle de fin de session
		break;
	    System.out.println("Message: " + str); //locale
	    pred.println(str);//renvoi d'un echo
	}
	plec.close();
	pred.close();
	soc.close();
    }
}
	    
