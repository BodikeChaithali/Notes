import java.util.Scanner;

public class noofwaystocallguest {
    public static int countways(int n){
        if (n<=1) return 1;
        return countways(n-1)+countways(n-2)*(n-1);
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.println(countways(n));
        sc.close();
    }
}
