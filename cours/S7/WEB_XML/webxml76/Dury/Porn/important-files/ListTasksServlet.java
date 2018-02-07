package fr.enseirb.webxml.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import fr.enseirb.webxml.util.ServletToolkit;
import fr.enseirb.webxml.data.xml.XMLMediator;

public class ListTasksServlet extends HttpServlet{
    
    private static final long serialVersionUID = 1L;

	/**
	 * Default constructor.
	 */
	public ListTasksServlet() {
		super();
	}

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	response.setHeader("Content-Type", "application/xml");
	java.util.Properties params = ServletToolkit.parseURLParams(request);
	if (params.containsKey("id")) {
	    String id = params.getProperty("id");
	    int num = Integer.parseInt(id);
	    XMLMediator.getTask(num);
	}
	String tasks = XMLMediator.getTasks();
	ServletToolkit.writeResponse(response, tasks);
    }
}
