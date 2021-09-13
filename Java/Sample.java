import java.util.*;
public class Sample {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
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
