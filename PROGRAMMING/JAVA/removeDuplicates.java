import java.util.*;
public class removeDuplicates {
    public static int[] map=new int[26];
    public static void removeDuplicatesvalues(String str,int idx,String newstr) {
        if(idx==str.length()) {
            System.out.println(newstr);
            return;
        }
        char currchar=str.charAt(idx);
        if(map[currchar-'a']==0) {
            newstr+=currchar;
            map[currchar-'a']++;
        }
        removeDuplicatesvalues(str,idx+1,newstr);
    }
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        String str=sc.nextLine();
        removeDuplicatesvalues(str,0,"");
        sc.close();
    }
}
