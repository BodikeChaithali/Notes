import java.util.ArrayList;
import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
public class shortestDistance {
    public static void bfs(ArrayList<ArrayList<Integer>> graph,int src,int dest) {
        Queue<Integer> q=new LinkedList<>();
        boolean []visited=new boolean[graph.size()];
        int []distance=new int[graph.size()];
        q.add(src);
        visited[src]=true;
        distance[src]=0;
        while(!q.isEmpty()) {
            int node=q.poll();
            for(int neighbour:graph.get(node)) {
                if(!visited[neighbour]) {
                    q.add(neighbour);
                    visited[neighbour]=true;
                    distance[neighbour]=distance[node]+1;
                }
            }
        }
        if (distance[dest] == 0 && src != dest) 
            System.out.println("No path exists from " + src + " to " + dest);
        else 
            System.out.println("Shortest distance from " + src + " to " + dest + " is: " + distance[dest]);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for(int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        sc.close();
    }
}
