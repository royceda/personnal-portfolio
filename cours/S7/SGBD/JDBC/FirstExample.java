//STEP 1. Import required packages
import java.sql.*;

public class FirstExample {
   // JDBC driver name and database URL
   static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
   static final String DB_URL = "jdbc:mysql://127.0.0.1";

   //  Database credentials
   static final String USER = "root";
   static final String PASS = "a";
   
   public static void main(String[] args) {
   Connection conn = null;
   Statement stmt = null;
   try{
      //STEP 2: Register JDBC driver
      Class.forName("com.mysql.jdbc.Driver");
      System.out.println("ok");

      //STEP 3: Open a connection
      System.out.println("Connecting to database...");
      conn = DriverManager.getConnection(DB_URL, USER, PASS);


      //STEP 4: Execute a query
      System.out.println("Creating statement...");
      stmt = conn.createStatement();
      String sql;
      ResultSet rs;
      sql = "USE ENVIEE";
      rs  = stmt.executeQuery(sql);
      sql = "INSERT INTO truck (poids, nom, hauteur, largeur, longueur) VALUES (13, 'REDA', 3, 3,7);";
      stmt.executeUpdate(sql);
      sql = "SELECT * FROM truck";
      rs  = stmt.executeQuery(sql);      
      System.out.println("Use : Ok, niiiice!!!!!");
      

      //STEP 5: Extract data from result set
      while(rs.next()){
         //Retrieve by column name
         int id          = rs.getInt("id");
	 int poids       = rs.getInt(2);
         String nom      = rs.getString(3);
         String hauteur  = rs.getString(4);
         String largeur  = rs.getString(5);
         String longueur = rs.getString(6);

         //Display values
         System.out.print("ID: " + id);
         System.out.print(", poids: " + poids);
         System.out.print(", nom: " + nom);
	 System.out.println(", hauteur: " + hauteur);
      }


      //STEP 6: Clean-up environment
      rs.close();
      stmt.close();
      conn.close();
   }catch(SQLException se){
      //Handle errors for JDBC
      se.printStackTrace();
   }catch(Exception e){
      //Handle errors for Class.forName
      e.printStackTrace();
   }finally{
      //finally block used to close resources
      try{
         if(stmt!=null)
            stmt.close();
      }catch(SQLException se2){
      }// nothing we can do
      try{
         if(conn!=null)
            conn.close();
      }catch(SQLException se){
         se.printStackTrace();
      }//end finally try
   }//end try
   System.out.println("Goodbye!");
}//end main
}//end FirstExample
