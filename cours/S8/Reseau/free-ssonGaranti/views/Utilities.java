package aqua.view;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Utilities {
  static void writeFile(String fileContent, String filePathOutput) {
    try {

      // BufferedWriter a besoin d'un FileWriter, les 2 vont ensemble, on
      // donne comme argument le nom du fichier et false signifie qu'on
      // écrase le contenu du fichier et qu'on ne fait pas d'append sur le
      // contenu.
      FileWriter fileWriter = new FileWriter(filePathOutput, true);

      // Le BufferedWriter output auquel on donne comme argument le
      // fileWriter écrase le contenu déjà présent dans le fichier.
      BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);

      // On écrit dans le fichier ou plutot dans le bufferedWriter qui
      // sert de tampon(stream)
      bufferedWriter.write(fileContent);

      bufferedWriter.flush();
      bufferedWriter.close();
      //System.out.println("Fichier créé");

    } catch (IOException ioe) {
      System.err
          .println("Erreur levée de type IOException au niveau de la méthode "
              + "writeFile(...) : ");
      ioe.printStackTrace();
    }
  }// End writeFile(...)

  public static void readFile(String filePathInput, String filePathOutput) {

    Scanner scanner = null;
    String line = null;
    StringBuffer str = new StringBuffer();
    try {
      scanner = new Scanner(new File(filePathInput));

      // On boucle sur chaque champ detecté
      while (scanner.hasNextLine()) {
        line = scanner.nextLine();

        if (line != null)
          str.append(line + "\r\n");
      }

      scanner.close();
    } catch (FileNotFoundException e) {
      System.err.println("Erreur levée de type FileNotFoundException"
          + " au niveau de la méthode " + "readFile(...) : ");
      e.printStackTrace();
    }

    Utilities.writeFile(str.toString(), filePathOutput);
  }// End readFile(...)

  public static void formatSQLFileContentToIntegrateThisInTheJAVACode(
      String filePathInput, String filePathOutput) {

    Scanner scanner = null;
    String line = null;
    StringBuffer str = new StringBuffer();
    try {
      scanner = new Scanner(new File(filePathInput));

      // On boucle sur chaque champ detecté
      while (scanner.hasNextLine()) {
        line = scanner.nextLine();

        if (line != null)
          str.append(".append(\"" + line + " \")\r\n");
      }

      scanner.close();
    } catch (FileNotFoundException e) {
      System.err
          .println("Erreur levée de type FileNotFoundException"
              + " au niveau de la méthode "
              + "formatSQLFileContentToIntegrateThisInTheJAVACode(...) : ");
      e.printStackTrace();
    }

    Utilities.writeFile(str.toString(), filePathOutput);
  }// End formatSQLFileContentToIntegrateThisInTheJAVACode(...)
}// End public class Utilities
