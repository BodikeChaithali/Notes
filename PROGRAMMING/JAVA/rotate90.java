import java.util.*;
class rotate90 {
	public static void rotate(int [][]arr){
		int st=0,end=arr.length-1;
		while(st<=end) {
			for(int j=0;j<arr.length;j++) {
				int temp=arr[st][j];
				arr[st][j]=arr[end][j];
				arr[end][j]=temp;
			}
			st++;
			end--;
		}
		for(int i=0;i<arr.length;i++) {
			for(int j=i;j<arr.length;j++) {
				int temp=arr[i][j];
				arr[i][j]=arr[j][i];
				arr[j][i]=temp;
			}
		}
	}
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int arr[][]=new int[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				arr[i][j]=sc.nextInt();
		rotate(arr);
		for(int i=0;i<n;i++) {
			for(int val:arr[i]) 
				System.out.print(val+" ");
			System.out.println();
		}
		sc.close();
	}
}
