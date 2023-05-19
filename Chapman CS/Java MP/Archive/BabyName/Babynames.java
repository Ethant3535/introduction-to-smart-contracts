import java.io.*;
public class Babynames {
    public static void main(String[] args) {
        BufferedReader reader = null;
        PrintWriter writer = null;
        try {
            // param to FileReader constructor is the local path to the file
            reader = new BufferedReader(new FileReader(args[0]));
            String currentLine;
            // set currentLine to the next line in file
            // make sure that line is not null 
            // when it's null, there is nothing in the file
            while((currentLine = reader.readLine()) != null) {
                System.out.println(currentLine.toUpperCase());
            }
        }catch (FileNotFoundException e) {
            // runs if the file does not exist
            // organize our catch statements my most specific -> lest specific
            System.err.println("We couldn't find that file.");
        }
        catch (IOException e) {
            // runs if something else breaks during file i/o
            System.out.println("Error reading or writing to a file.");
            System.err.println(e.getMessage());
        }

        //writer = new PrintWriter(new FileWriter("./potential_names.txt", true));
        }

    public static void readFile(BufferedReader reader) throws IOException, IncorrectFileExtension {
        String currentLine;
        int nLines = 0;
        while((currentLine = reader.readLine()) != null){
            if (currentLine.contains("fuck") || currentLine.contains("shit")) {
                // we must create a new object of our custom exception with whatever error message we want
                // keyword "throw" says "hey, something is wrong! somebody else do something about it!" 
                throw new IncorrectFileExtension("This file is the wrong extension");
            }
            nLines++;
        }
        System.out.println("There are " + nLines + " lines in your file.");
    }
}
