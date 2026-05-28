import java.util.*;
public class mergeKSortedarrays {
    public static int[] merge(List<int[]> arrays) {
        if(arrays==null || arrays.size()==0)
            return new int[0];
        return mergeHelper(arrays, 0, arrays.size()-1);
    }
    private static int[] mergeHelper(List<int[]> arrays, int left, int right) {
        if(left==right)
            return arrays.get(left);
        int mid=left+(right-left)/2;
        int[] leftMerged=mergeHelper(arrays, left, mid);
        int[] rightMerged=mergeHelper(arrays, mid+1, right);
        return mergeTwoArrays(leftMerged, rightMerged);
    }
    private static int[] mergeTwoArrays(int[] arr1, int[] arr2) {
        int n1=arr1.length, n2=arr2.length;
        int[] merged=new int[n1+n2];
        int i=0, j=0, k=0;
        while(i<n1 && j<n2) {
            if(arr1[i]<=arr2[j]) 
                merged[k++]=arr1[i++];
            else    
                merged[k++]=arr2[j++];
        }
        while(i<n1)
            merged[k++]=arr1[i++];
        while(j<n2)
            merged[k++]=arr2[j++];
        return merged;
    }
    public static void main(String []args) {
        Scanner sc=new Scanner(System.in);
        int k=sc.nextInt();
        List<int[]> arrays=new ArrayList<>();
        for(int i=0;i<k;i++) {
            int n=sc.nextInt();
            int arr[]=new int[n];
            for(int j=0;j<n;j++)
                arr[j]=sc.nextInt();
            arrays.add(arr);
        }
        int result[]=merge(arrays);
        for(int val:result)
            System.out.print(val+" ");
        sc.close();
    }
}
