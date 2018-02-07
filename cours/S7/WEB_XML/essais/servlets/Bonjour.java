import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.ServletConfig;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


import javax.servlet.annotation.WebServlet;

public class Bonjour extends HttpServlet {
    
    private int compte;
    public void init(ServletConfig config) throws ServletException{
	compte = 0;
    }

    public void doPost( HttpServletRequest req, HttpServletResponse res)
	throws ServletException, IOException {
	
	res.setcontentType("text/html"); //type MIME de la reponse
	PrintWriter out = res.getWriter();
	String nom = req.getparameter("nom");
	if (nom == null)
	    nom ="";
	compte++;
	out.println(
		    "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n"
		    + "<html>\n"
		    + "<head><title>Servlet Bonjour</title></head>\n"
		    + "<body><h1>Bonjour" + nom + "</h1>\n"
		    + "Appel no: " + compte +"\n"
		    + "</body></html>"
		    );
    }
}
