import java.util.*;

public class functions {
    public static void printMyName(String name) {
        System.out.println("Hello , "+name+" welcome to the program!");
        return;
    }
    public static void main(String [] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter your name:");
        String name=sc.nextLine();
        printMyName(name);//function call
        sc.close();
    }
}
