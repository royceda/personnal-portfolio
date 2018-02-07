package fr.enseirb.webxml.data.xml;

import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

import fr.enseirb.webxml.data.dao.DBManager;
import fr.enseirb.webxml.data.model.Task;
import fr.enseirb.webxml.data.model.User;
import fr.enseirb.webxml.util.ServletToolkit;
import fr.enseirb.webxml.util.XMLToolkit;

public class XMLMediator {
	private static final Logger LOGGER = Logger.getLogger(XMLMediator.class.getName());

	public static final SimpleDateFormat DATE_FORMAT = new SimpleDateFormat("dd/MM/yyyy");

	/**
	 * Permet de cr�er un flux XML correspondant � une t�che vide
	 * 
	 * @return le flux XML de la t�che vide
	 */
	public static final String createEmptyTaskXML() {
		StringBuilder buffer = new StringBuilder(XMLToolkit.XML_HEADER);
		appendTaskXML(new Task(), buffer);
		return buffer.toString();
	}

	/**
	 * Permet de cr�eer le flux XML d'une t�che et de l'ajouter au buffer fourni
	 * 
	 * @param task
	 *            la t�che dont il faut extraire les valeurs
	 * @param buffer
	 *            le buffer � compl�ter avec le flux XML
	 */
	public static final void appendTaskXML(Task task, StringBuilder buffer) {
		buffer.append("<task id=\"").append(task.getId()).append("\" ");
		buffer.append("title=\"").append(task.getTitle()).append("\" ");
		buffer.append("creationDate=\"").append(DATE_FORMAT.format(task.getCreationDate())).append("\" ");
		buffer.append("deadline=\"").append(DATE_FORMAT.format(task.getDeadline())).append("\" ");
		buffer.append("priority=\"").append(task.getPriority()).append("\" ");
		buffer.append("done=\"").append(Boolean.toString(task.isDone())).append("\">");
		buffer.append("<description>").append(task.getDescription()).append("</description>");
		buffer.append("<asker>").append(task.getAsker()).append("</asker>");
		buffer.append("<owner>").append(task.getOwner()).append("</owner>");
		buffer.append("</task>");
	}

	/**
	 * Permet de r�cup�rer le flux XML de toutes les t�ches contenues dans la base de donn�es
	 * 
	 * @return le flux XML de toutes les t�ches, sous la forme :
	 * 
	 *         <tasks> <task id="xxx" title="ttt" deadline="dd/MM/yyyy" priority="123" done="true">
	 *         <description>ddd</description> <asker>aaa</asker> <owner>ooo</owner> </task> <task id="yyy" title="ttt"
	 *         deadline="dd/MM/yyyy" priority="123" done="false"> <description>ddd</description> <asker>aaa</asker>
	 *         <owner>ooo</owner> </task> ... </tasks>
	 */
	public static String getTasks() {
		List<Task> tasks = DBManager.INSTANCE.getTaskDAO().getTasks();
		StringBuilder task = new StringBuilder();
		task.append("<tasks>");
		for(int i=0; i<tasks.size(); i++) {
		    appendTaskXML(tasks.get(i),task);
		}
		task.append("</tasks>");
		// TODO : cr�er le flux XML correspondant aux t�ches
		String tasksXML = new String(task);
		if(XMLToolkit.isXMLValid(tasksXML,"resources/xsd/tasks.xsd")) {
		    LOGGER.log(Level.INFO, "XML Tasks are: " + tasksXML);
		    return tasksXML;
		}
		else
		    return "<error>XML is not valid</error>";
	}
	/**
	 * Permet de r�cup�rer le flux XML correspondant � la t�che dont l'id est fourni en param�tre
	 * 
	 * @param id
	 *            l'id de la t�che � r�cup�rer
	 * @return le flux de la t�che
	 */
	public static String getTask(int id) {
		Task task = DBManager.INSTANCE.getTaskDAO().getTask(id);
		StringBuilder task2 = new StringBuilder();
		appendTaskXML(task, task2);
		// TODO : cr�er le flux XML correspondant � la t�che demand�e
		String taskXML = new String(task2);
		LOGGER.log(Level.INFO, "XML Task with id " + id + " is: " + taskXML);
		return taskXML;
	}

	/**
	 * Permet d'ajouter (si l'id n'est pas fourni) ou modifier (si l'id est founir) une t�che � la base de donn�es �
	 * partir du flux XML fourni
	 * 
	 * @param taskXML
	 *            le flux XML correspond � celui d'une t�che : <task id="xxx" title="ttt" deadline="dd/MM/yyyy"
	 *            priority="123" done="true"> <description>ddd</description> <asker>aaa</asker> <owner>ooo</owner>
	 *            </task>
	 * @return true si si l'ajout ou la modification s'est bien pass�, false sinon
	 */
	public static boolean addOrModifyTask(String taskXML) {
	    if (!XMLToolkit.isXMLValid(taskXML, "resources/xsd/task.xsd"))
		return false;
	    LOGGER.log(Level.INFO, "Adding or modifying Task stream: " + taskXML);

	    Document doc = XMLToolkit.parseDocument(taskXML);
	    Element taskElt = doc.getDocumentElement();
	    return addOrModifyTask(taskElt);
	}

	/**
	 * Permet d'ajouter (si l'id n'est pas fourni) ou modifier (si l'id est founir) une t�che � la base de donn�es �
	 * partir de l'objet Element fourni, correspondant au flux XML
	 * 
	 * @param taskXML
	 *            L'objet Element correspondant au flux XML d'une t�che : <task id="xxx" title="ttt"
	 *            deadline="dd/MM/yyyy" priority="123" done="true"> <description>ddd</description> <asker>aaa</asker>
	 *            <owner>ooo</owner> </task>
	 * @return true si l'ajout ou la modification s'est bien pass�, false sinon
	 */
	public static boolean addOrModifyTask(Element taskElt) {
		LOGGER.log(Level.INFO, "Adding or modifying Task element");

		boolean success;
		try {
			Task task = new Task();
			String s = "";
			// TODO compl�ter la cr�ation (de l'objet Task
			// pour la date, utiliser le code ci-dessous
			s = taskElt.getAttribute("id");
			if (!s.isEmpty())
			    task.setId(Integer.parseInt(s));
			s = taskElt.getElementsByTagName("asker").item(0).getTextContent();
			if (!s.isEmpty())
			    task.setAsker(s);
			s = taskElt.getElementsByTagName("owner").item(0).getTextContent();
			if (!s.isEmpty())
			    task.setOwner(s);
			s = taskElt.getAttribute("title");
			if (!s.isEmpty())
			    task.setTitle(s);
			s = taskElt.getElementsByTagName("description").item(0).getTextContent();
			if (!s.isEmpty())
			    task.setDescription(s);
			s = taskElt.getAttribute("priority");
			if (!s.isEmpty())
			    task.setPriority(Integer.parseInt(s));
			s = taskElt.getAttribute("done");
			if (!s.isEmpty())
			task.setDone(Boolean.parseBoolean(s));
			s = taskElt.getAttribute("deadline");
			if (!s.isEmpty())
			    task.setDeadline(DATE_FORMAT.parse(s));

			success = DBManager.INSTANCE.getTaskDAO().addOrModify(task);
			if (success) {
				// on rajoute les utilisateurs au passage
				DBManager.INSTANCE.getUserDAO().addUser(new User(task.getAsker()));
				DBManager.INSTANCE.getUserDAO().addUser(new User(task.getOwner()));
			}
		} catch (ParseException e) {
			LOGGER.log(Level.INFO, "Problem while adding or modifying", e);
			success = false;
		}

		return success;
	}

	/**
	 * Permet de r�cup�rer le flux XML correspondant � tous les utilisateurs stock�s en base de donn�es
	 * 
	 * @return le flux XML sous la forme : <users> <user name="xxx"/> <user name="yyy"/> ... </users>
	 */
    public static String getUsers() {
	List<User> users = DBManager.INSTANCE.getUserDAO().getUsers();
	StringBuffer user = new StringBuffer();
	user.append("<users>");
	for (int i=0; i< users.size(); i++) {
	    user.append("<user name=\""+users.get(i).getName()+"\"/>");
	}
	user.append("</users>");
	// TODO renvoyer le flux XML correspondant � la liste des utilisateurs
	String usersXML = new String(user);
	if(XMLToolkit.isXMLValid(usersXML, "resources/xsd/users.xsd")) {
	    LOGGER.log(Level.INFO, "XML Users are: " + usersXML);
	    return usersXML;
	}
	else
	    return "<error>XML is not valid</error>";
    }
    

	/**
	 * Permet d'ajouter un utilisateur en base de donn�es � partir d'un flux XML fourni
	 * 
	 * @param userXML
	 *            le flux XML correspondant � un utilisateur, sous la forme : <user name="xxx"/>
	 * @return true si l'ajout s'est bien pass�, et false sinon
	 */
	public static boolean addUser(String userXML) {
	    if(!XMLToolkit.isXMLValid(userXML, "resources/xsd/user.xsd"))
		return false;
	    LOGGER.log(Level.INFO, "Adding User stream: " + userXML);
	    
	    Document doc = XMLToolkit.parseDocument(userXML);
	    Element userElt = doc.getDocumentElement();
	    return addUser(userElt);
	}

	/**
	 * Permet d'ajouter un utilisateur en base de donn�es � partir d'un objet Element correspondant � un flux XML
	 * 
	 * @param userXML
	 *            L'objet Element correspondant au flux XML d'un utilisateur, sous la forme : <user name="xxx"/>
	 * @return true si l'ajout s'est bien pass�, et false sinon
	 */
	public static boolean addUser(Element userElt) {
	    LOGGER.log(Level.INFO, "Adding User element: " + userElt.getTagName());
		
		// TODO : remplir la variable "name" avec la valeur de l'attribut "name" de userElt
		String name = userElt.getAttribute("name");
		User user = new User(name);

		return DBManager.INSTANCE.getUserDAO().addUser(user);
	}

	/**
	 * Permet de r�cup�rer un flux XML correspondant aux statistiques sur les utilisateurs et t�ches
	 * 
	 * @return le flux XML, sous la forme : <stats> <user name="uuu"> <tasks number="2"> <done number="1"> <task
	 *         title="ttt1"></task> </done> <todo number="1"> <late number="1"> <task title="ttt2"></task> </late>
	 *         <intime number="0"></intime> </todo> </tasks> </user> <user name="uuu2"> <tasks number="2"> <done
	 *         number="0"></done> <todo number="2"> <late number="0"></late> <intime number="2"> <task
	 *         title="ttt3"></task> <task title="ttt4"></task> </intime> </todo> </tasks> </user> ... </stats>
	 */
	public static String buildStats() {
		LOGGER.log(Level.INFO, "Building stats");
		String current_user;
		String users = getUsers();
		String tasks = getTasks();

		String now = DATE_FORMAT.format(new Date());
		String day = now.substring(0, 2);
		String month = now.substring(3, 5);
		String year = now.substring(6, 10);

		String nowDate = year + month + day;
		String xPathDate = "concat(substring(@deadline,7,4), substring(@deadline,4,2), substring(@deadline,1,2))";

		// TODO : cr�er un flux XML pour les stats

		String statsXML = "<stats>";
		statsXML += "\n";
		Iterator<String> listUsersName = XMLToolkit.getXPathValues(users, "users/user/@name").iterator();
		while (listUsersName.hasNext()) {
		    current_user = listUsersName.next();
		    //		    List<String> listTaskUser = XMLToolkit.getXPath
		}
		statsXML += "</stats>";
		LOGGER.log(Level.INFO, "Stats built: " + statsXML);
		return statsXML;
	}

	/**
	 * Permet d'initialiser la base de donn�es � partir de donn�es sous la forme d'un fichier XML
	 * 
	 * @param initDBPath
	 *            le chemin vers le fichier � lire, sous la forme d'un chemin absolu (commen�ant par "/") � partir du
	 *            r�pertoire WebContent
	 * @return
	 */
	public static boolean parseInitDB(String initDBPath) {
		LOGGER.log(Level.INFO, "Parsing init DB file: " + initDBPath);

		String initDBStream;
		try {
			initDBStream = ServletToolkit.readFile(initDBPath);
		} catch (IOException e) {
			LOGGER.log(Level.SEVERE, "Error while parsing init DB file");
			initDBStream = null;
		}

		if (initDBStream != null) {
			return importXMLTasks(initDBStream);
		} else {
			return false;
		}
	}

	/**
	 * Permet d'importer des t�ches dans la base de donn�es, en mettant � jour les t�ches d�j� existants (si l'id de la
	 * t�che existe d�j� en base de donn�es), en la cr�ant sinon ; et dans tous les cas, en ajoutant les utilisateurs
	 * non encore pr�sents
	 * 
	 * @param initDBStream
	 *            le flux XML correspondant aux donn�es � importer, sous la forme : <db_dump> <tasks> <task id="xxx"
	 *            title="ttt" deadline="dd/MM/yyyy" priority="123" done="true"> <description>ddd</description>
	 *            <asker>aaa</asker> <owner>ooo</owner> </task> <task id="yyy" title="ttt" deadline="dd/MM/yyyy"
	 *            priority="123" done="false"> <description>ddd</description> <asker>aaa</asker> <owner>ooo</owner>
	 *            </task> ... </tasks> <users> <user name="xxx"/> <user name="yyy"/> ... </users> </db_dump>
	 * @return
	 */
	public static boolean importXMLTasks(String initDBStream) {
		LOGGER.log(Level.INFO, "Importing tasks");

		boolean success;
		try {
			// if (!XMLToolkit.isXMLValid(initDBStream, "/resources/xsd/db_dump.xsd")) {
			// throw new Exception("Init file is not valid against XMLSchema");
			// }

			Document doc = XMLToolkit.parseDocument(initDBStream);
			Element rootElt = doc.getDocumentElement();

			NodeList tasksNodes = rootElt.getElementsByTagName("tasks");
			if (tasksNodes.getLength() > 1) {
				throw new Exception("More than 1 <tasks> element");
			}

			NodeList usersNodes = rootElt.getElementsByTagName("users");
			if (tasksNodes.getLength() > 1) {
				throw new Exception("More than 1 <users> element");
			}

			if (tasksNodes.getLength() == 1) {
				// on ajoute les t�ches
				Element tasksNode = (Element) tasksNodes.item(0);
				NodeList taskNodes = tasksNode.getElementsByTagName("task");
				for (int i = 0; i < taskNodes.getLength(); i++) {
					Element taskNode = (Element) taskNodes.item(i);
					if (!addOrModifyTask(taskNode)) {
						throw new Exception("Error while adding task");
					}
				}
			}

			if (usersNodes.getLength() == 1) {
				// on ajoute les users
				Element usersNode = (Element) usersNodes.item(0);
				NodeList userNodes = usersNode.getElementsByTagName("user");
				for (int i = 0; i < userNodes.getLength(); i++) {
					Element userNode = (Element) userNodes.item(i);
					if (!addUser(userNode)) {
						throw new Exception("Error while adding user");
					}
				}
			}

			success = true;
		} catch (IOException e) {
			LOGGER.log(Level.INFO, "Error while importing data in db", e);
			success = false;
		} catch (Exception e) {
			LOGGER.log(Level.INFO, "Error while importing data in db", e);
			success = false;
		}

		return success;
	}

}
