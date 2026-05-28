// import java.util.*;
public class string {
    public static void main(String[] args) {
       int num[]= {5,10,15,20,25};
       System.out.println(num.length);
       String str="Hello World";
       System.out.println(str.length());
       System.out.println(str.charAt(0));
       StringBuilder sb=new StringBuilder("Hello");
       sb.append(" World");
       System.out.println(sb);
       sb.setCharAt(0, 'H');
         System.out.println(sb);
    }
}
