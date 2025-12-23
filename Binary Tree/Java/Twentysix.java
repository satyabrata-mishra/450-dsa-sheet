import java.util.ArrayList;
import java.util.Arrays;

class Solution {

    private void dfs(int node, ArrayList<ArrayList<Integer>> adj, boolean[] visited) {
        visited[node] = true;
        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    public boolean isTree(int n, int m, ArrayList<ArrayList<Integer>> edges) {
        // Condition 1: A tree must have exactly n - 1 edges
        if (m != n - 1)
            return false;

        // Build adjacency list
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (ArrayList<Integer> e : edges) {
            int u = e.get(0);
            int v = e.get(1);
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        // DFS to check connectivity
        boolean[] visited = new boolean[n];
        dfs(0, adj, visited);

        // Condition 2: Graph must be connected
        for (boolean v : visited) {
            if (!v)
                return false;
        }

        return true;
    }
}

public class Twentysix {
    public static void main(String[] args) {
        Solution sol = new Solution();

        // First test case
        ArrayList<ArrayList<Integer>> edges1 = new ArrayList<>();
        edges1.add(new ArrayList<>(Arrays.asList(0, 1)));
        edges1.add(new ArrayList<>(Arrays.asList(1, 2)));
        edges1.add(new ArrayList<>(Arrays.asList(1, 3)));

        System.out.println(sol.isTree(4, 3, edges1)); // true

        // Second test case
        ArrayList<ArrayList<Integer>> edges2 = new ArrayList<>();
        edges2.add(new ArrayList<>(Arrays.asList(0, 1)));
        edges2.add(new ArrayList<>(Arrays.asList(1, 2)));
        edges2.add(new ArrayList<>(Arrays.asList(2, 0)));

        System.out.println(sol.isTree(4, 3, edges2)); // false
    }
}
