import java.util.Scanner;

public class sudoko {
    public static boolean isSafe(int [][]board,int row,int col,int num) {
        for(int i=0;i<board.length;i++) {
            if(board[row][i]==num) return false;
            if(board[i][col]==num) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==num) return false;
        }
        return true;
    }
    public static boolean helper(int [][]board,int row,int col) {
        if(row==board.length) return true;
        int nrow=0,ncol=0;
        if(col==board.length-1) {
            nrow=row+1;
            ncol=0;
        }
        else{
            ncol=col+1;
            nrow=row;
        }
        if(board[row][col]!=0) {
            if(helper(board, nrow, ncol))
                return true;
        }
        else{
            for(int i=1;i<=9;i++) {
                if(isSafe(board, row, col, i)) {
                    board[row][col]=i;
                    if(helper(board, nrow, ncol))
                        return true;
                    else
                        board[row][col]=0;
                }
            }
        }
        return false;
    }
    public static void SudokoSolver(int [][]board) {
        helper(board, 0, 0);
    }
    public static void main(String []args) {
        Scanner sc=new Scanner(System.in);
        int board[][]=new int[9][9];
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) 
                board[i][j]=sc.nextInt();
        }
        SudokoSolver(board);
        System.err.println();
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) 
                System.out.print(board[i][j]+" ");
            System.err.print("\n");
        }
        sc.close();
    }
}
