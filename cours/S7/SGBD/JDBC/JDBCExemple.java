import java.sql.*;

public class JDBCExemple {

    public static void main(String[] argv) {

	System.out.println("Teste de connexion.....");
	try {
	    Class.forName("com.mysql.jdbc.Driver");
	} catch(ClassNotFoundException e) {
	    System.out.println("Ou est le JDBC Driver ?");
	    //	    e.printStackTrace();
	    return;
	}

	System.out.println("MySQL JDBC Driver Registered!!");
	Connection connection = null;
	
	try {
	    connection = DriverManager.getConnection("jdbc:mysql://127.0.0.1","root","a");
	}catch (SQLException e) {
	    System.out.println("Echec de connexion....");
	    // e.printStackTrace;
	    return;
	}

	if (connection != null) {
	    System.out.println("OKK, Nice ca marche");
	} else {
	    System.out.println("echec !!!!!");
	}
	
    }
}
