import java.util.Scanner;

public class loops {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                    System.out.print("* ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
        System.out.println();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j < n - i - 1) {
                    System.out.print("  ");
                } else {
                    System.out.print("* ");
                }
            }
            System.out.println();
        }
        System.out.println();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
        System.out.println();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i + 1; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
        int c = 0;
        System.out.println();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                c++;
                System.out.print(c + " ");
            }
            System.out.println();
        }
        System.out.println();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if ((i + j) % 2 == 0) {
                    System.out.print("1 ");
                } else {
                    System.out.print("0 ");
                }
            }
            System.out.println();
        }
        System.out.println();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 2 * n; j++) {
                if (j <= i || j > 2 * n - i) {
                    System.out.print("* ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 2 * n; j++) {
                if (j <= n - i + 1 || j > n + (i - 1)) {
                    System.out.print("* ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
        System.out.println();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i; j++) {
                System.out.print("  ");
            }
            for (int j = 1; j <= n; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i; j++) {
                System.out.print("  ");
            }
            for (int j = 1; j <= n; j++) {
                if (i == 1 || i == n || j == 1 || j == n)
                    System.out.print("* ");
                else
                    System.out.print("  ");
            }
            System.out.println();
        }
        System.out.println();
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(j<=n-i) {
                    System.out.print(" ");
                } else {
                    System.out.print(i+" ");
                }
            }
            System.out.println();
        }
        System.out.println();
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n-i;j++) System.out.print("  ");
            for(int j=i;j>=1;j--) System.out.print(j+" "); 
            for(int j=2;j<=i;j++) System.out.print(j+" ");
            System.out.println();
        }
        System.out.println();
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n-i;j++) System.out.print("  ");
            for(int j=i;j>=1;j--) System.out.print("* "); 
            for(int j=2;j<=i;j++) System.out.print("* ");
            System.out.println();
        }
        for(int i=n;i>0;i--) {
            for(int j=1;j<=n-i;j++) System.out.print("  ");
            for(int j=i;j>=1;j--) System.out.print("* "); 
            for(int j=2;j<=i;j++) System.out.print("* ");
            System.out.println();
        }
        sc.close();
    }
}
