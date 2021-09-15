import java.util.*;
import java.io.*;
public class Sample {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new File("input.in"));
        System.setOut(new PrintStream(new FileOutputStream("output.out")));
        System.out.println("Hello World"); 
        String s = sc.nextLine();
        System.out.println(s);
        try{
        System.out.println(s.charAt(2));
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
        sc.close();
    }
}
