import java.util.Scanner;
// Dynamic programing
public class noofplacetitles {
    public static int countPlaceTitles(int n,int m) {
        if (n==m) return 2;
        if (n<m) return 1;
        return countPlaceTitles(n-m, m)+countPlaceTitles(n-1, m); 
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        System.out.println(countPlaceTitles(n,m));
        sc.close();
    }
}