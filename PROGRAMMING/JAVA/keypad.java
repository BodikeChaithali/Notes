import java.util.Scanner;

public class keypad {
    public static String keypadString[] ={".","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

    public static void printComb(String str,int idx,String comb) {
        if(idx==str.length()) {
            System.out.println(comb);
            return;
        }
        char currCh=str.charAt(idx);
        String mapping=keypadString[currCh-'0'];
        for(int i=0;i<mapping.length();i++) 
            printComb(str, idx+1, comb+mapping.charAt(i));
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String str=sc.nextLine();
        printComb(str, 0, "");
        sc.close();
    }
}
