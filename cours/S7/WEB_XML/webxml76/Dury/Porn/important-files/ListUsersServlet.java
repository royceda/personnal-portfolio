package fr.enseirb.webxml.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import fr.enseirb.webxml.util.ServletToolkit;
import fr.enseirb.webxml.data.xml.XMLMediator;

public class ListUsersServlet extends HttpServlet{
    
    private static final long serialVersionUID = 1L;

	/**
	 * Default constructor.
	 */
	public ListUsersServlet() {
		super();
	}

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	response.setHeader("Content-Type", "application/xml");
	String users = XMLMediator.getUsers();
	ServletToolkit.writeResponse(response, users);
    }
}
