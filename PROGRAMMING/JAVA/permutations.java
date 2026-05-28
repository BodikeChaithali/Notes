import java.util.Scanner;
// backtracking
public class permutations {
    public static void printPermutations(String str, String ans){
        if(str.length()==0){
            System.out.println(ans);
            return;
        }
        for(int i=0;i<str.length();i++){
            char currCh=str.charAt(i);
            String newStr=str.substring(0,i)+str.substring(i+1);
            printPermutations(newStr, ans+currCh);
        }
    }
    // public static void printPermutations(String str, String ans,int idx){
    //     if(str.length()==0){
    //         System.out.println(ans);
    //         return;
    //     }
    //     for(int i=0;i<str.length();i++){
    //         char currCh=str.charAt(i);
    //         String newStr=str.substring(0,i)+str.substring(i+1);
    //         printPermutations(newStr, ans+currCh,idx +1);
    //     }
    // }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String str=sc.nextLine();
        printPermutations(str, "");
        // printPermutations(str, "",0);
        sc.close();
    }
}
