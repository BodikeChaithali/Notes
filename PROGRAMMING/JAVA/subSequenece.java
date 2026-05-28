import java.util.*;
public class subSequenece {
    public static void subsequenece(String str,int idx,String newString,HashSet<String> set) {
        if(idx==str.length()) {
            if(set.contains(newString))
                return;
            set.add(newString);
            System.out.println(newString);
            return;
        }
        char currchar=str.charAt(idx);
        //to be
        subsequenece(str, idx+1, newString+currchar,set);
        //not to be
        subsequenece(str, idx+1, newString,set);
    }
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        String str=sc.nextLine();
        HashSet<String> set=new HashSet<>();
        subsequenece(str,0,"",set);
        sc.close();
    }
}
