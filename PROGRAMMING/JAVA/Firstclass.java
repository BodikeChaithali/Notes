import java.util.*;


class Firstclass {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter your name:");
        String name=sc.next();
        System.out.println("Hello, " + name + "!");
        sc.nextLine(); // 🔥 consume leftover newline
        System.out.print("Enter your Full name:");
        String fullName=sc.nextLine();
        System.out.println("Your Full Name is " + fullName);
        sc.close();
    }
}