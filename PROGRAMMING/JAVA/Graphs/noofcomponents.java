import java.util.ArrayList;
import java.util.Scanner;

public class noofcomponents {
    public static void dfs(ArrayList<ArrayList<Integer>> graph, int node, boolean[] visited) {
        visited[node] = true;
        for (int neighbour : graph.get(node)) {
            if (!visited[neighbour]) 
                dfs(graph, neighbour, visited);
        }
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
        boolean []visited = new boolean[graph.size()];
        int count = 0;
        for(int i = 0; i < graph.size(); i++) {
            if(!visited[i]) {
                count++;
                dfs(graph, i, visited);
            }
        }
        System.out.println("Number of components: " + count);
        sc.close();
    }
}
