import java.util.*;

public class subsets {
    public static void printsubset(ArrayList<Integer> subset){
        for(int i=0;i<subset.size();i++)
            System.out.print(subset.get(i)+" ");
            // System.out.print(subset+" ");
        System.out.println();
    }
    public static void findsubsets(int n,ArrayList<Integer> subset){
        if(n==0){
            printsubset(subset);
            return;
        }
        //include
        subset.add(n);
        findsubsets(n-1,subset);
        //exclude
        subset.remove(subset.size()-1);
        findsubsets(n-1,subset);
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        ArrayList<Integer> subset=new ArrayList<>();
        findsubsets(n,subset);
        sc.close();
    }
}
