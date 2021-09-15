import java.util.*;
import java.io.*;

public class Sample {
    public static void main(String[] args) {
    	
    	Scanner sc = new Scanner(System.in);
        if (System.getProperty("ONLINE_JUDGE") == null) {           
            try {
                System.setOut(new PrintStream(new FileOutputStream("outputf.out")));
				sc = new Scanner(new File("inputf.in"));
            }
            catch (Exception e) {
            	System.out.println(e);
            }
        }
      	
      	//code here
      	System.out.println("Hello Yashwanth M");

        sc.close();
    }
}
