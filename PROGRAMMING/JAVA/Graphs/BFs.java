import java.util.*;
class BFs {
    public static void bfs(ArrayList<ArrayList<Integer>> graph,int source) {
        Queue<Integer> q=new LinkedList<>();
        boolean[] visited=new boolean[graph.size()];
        q.add(source);
        visited[source]=true;
        while(!q.isEmpty()) {
            int node=q.poll();
            System.out.print(node+" ");
            for(int neighbour:graph.get(node)) {
                if(!visited[neighbour]) {
                    q.add(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
        System.out.println();
    }
    //Recursive DFS
    public static void dfs(ArrayList<ArrayList<Integer>> graph, int node, boolean[] visited) {
        visited[node] = true;
        System.out.print(node + " ");
        for (int neighbour : graph.get(node)) {
            if (!visited[neighbour]) 
                dfs(graph, neighbour, visited);
        }
    }
    public static void dfs(ArrayList<ArrayList<Integer>> graph, int src) {
        boolean[] visited = new boolean[graph.size()];
        Stack<Integer> stack = new Stack<>();
        stack.push(src);
        while (!stack.isEmpty()) {
            int node = stack.pop();
            if (!visited[node]) {
                visited[node] = true;
                System.out.print(node + " ");
                for (int i = graph.get(node).size() - 1; i >= 0; i--) {
                    int neighbour = graph.get(node).get(i);
                    if (!visited[neighbour]) 
                        stack.push(neighbour);
                }
            }
        }
        System.out.println();
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
        int source = sc.nextInt();
        bfs(graph, source);
        boolean[] visited = new boolean[graph.size()];
        dfs(graph, source, visited);
        sc.close();
    }
}