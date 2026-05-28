import java.util.Scanner;
// we can easily solve using dynamic programing but here is the recursive solution
public class noofmazes {
    public static int countMazes(int i, int j, int n, int m) {
        if (i == n - 1 && j == m - 1) {
            return 1;
        }
        if (i >= n || j >= m) {
            return 0;
        }
        return countMazes(i + 1, j, n, m) + countMazes(i, j + 1, n, m);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        System.out.println(countMazes(0, 0, n, m));
        sc.close();
    }
}
