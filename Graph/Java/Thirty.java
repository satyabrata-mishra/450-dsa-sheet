import java.util.*;

class Solution {
    // Create adjacency list
    private static List<List<Pair>> createAdjacencyList(int[][] edges, int v) {
        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adj.get(edge[0]).add(new Pair(edge[1], edge[2]));
        }
        return adj;
    }

    // Topological sort using DFS
    private static void topologicalSort(int src, List<List<Pair>> adj,
            boolean[] visited, Stack<Integer> st) {
        visited[src] = true;

        for (Pair neighbour : adj.get(src)) {
            if (!visited[neighbour.node]) {
                topologicalSort(neighbour.node, adj, visited, st);
            }
        }
        st.push(src);
    }

    // Main function
    public static int[] maximumDistance(int v, int e, int src, int[][] edges) {

        List<List<Pair>> adj = createAdjacencyList(edges, v);

        boolean[] visited = new boolean[v];
        Stack<Integer> st = new Stack<>();

        // Topological sort for all components
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                topologicalSort(i, adj, visited, st);
            }
        }

        int[] dist = new int[v];
        Arrays.fill(dist, Integer.MIN_VALUE);
        dist[src] = 0;

        // Relax edges in topological order
        while (!st.isEmpty()) {
            int curr = st.pop();

            if (dist[curr] != Integer.MIN_VALUE) {
                for (Pair neighbour : adj.get(curr)) {
                    if (dist[curr] + neighbour.weight > dist[neighbour.node]) {
                        dist[neighbour.node] = dist[curr] + neighbour.weight;
                    }
                }
            }
        }
        return dist;
    }

    // Helper Pair class
    static class Pair {
        int node, weight;

        Pair(int node, int weight) {
            this.node = node;
            this.weight = weight;
        }
    }
}

public class Thirty {
    public static void main(String[] args) {
        int ans[] = Solution.maximumDistance(6, 10, 1, new int[][] { { 0, 1, 5 }, { 0, 2, 3 }, { 1, 3, 6 }, { 1, 2, 2 },
                { 2, 4, 4 }, { 2, 5, 2 }, { 2, 3, 7 }, { 3, 5, 1 }, { 3, 4, -1 }, { 4, 5, -2 } });
        for (int i : ans) {
            System.out.print(i + " "); // INF,0,2,9,8,10
        }
    }
}
