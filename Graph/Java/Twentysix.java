import java.util.*;

class Solution {

    private boolean found = false;

    private void dfs(int src, int parent, int[] timer,
            List<List<Integer>> adj,
            boolean[] visited,
            int[] intime,
            int[] lowtime,
            int c, int d) {

        visited[src] = true;
        intime[src] = lowtime[src] = timer[0]++;

        for (int neighbour : adj.get(src)) {

            if (neighbour == parent)
                continue;

            if (!visited[neighbour]) {

                dfs(neighbour, src, timer, adj, visited, intime, lowtime, c, d);
                lowtime[src] = Math.min(lowtime[src], lowtime[neighbour]);

                // bridge condition
                if (lowtime[neighbour] > intime[src]) {
                    if ((src == c && neighbour == d) || (src == d && neighbour == c)) {
                        found = true;
                    }
                }
            } else {
                // back-edge
                lowtime[src] = Math.min(lowtime[src], intime[neighbour]);
            }
        }
    }

    public boolean isBridge(int V, int[][] edges, int c, int d) {

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++)
            adj.add(new ArrayList<>());

        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }

        boolean[] visited = new boolean[V];
        int[] intime = new int[V];
        int[] lowtime = new int[V];

        int[] timer = new int[] { 0 }; // simulate pass-by-reference

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, timer, adj, visited, intime, lowtime, c, d);
            }
        }

        return found;
    }
}

public class Twentysix {
    public static void main(String[] args) {

        Solution sol = new Solution();

        int[][] edges1 = {
                { 0, 1 },
                { 1, 2 },
                { 2, 3 }
        };
        System.out.println(sol.isBridge(4, edges1, 1, 2)); // true

        int[][] edges2 = {
                { 0, 1 },
                { 0, 3 },
                { 1, 2 },
                { 2, 0 },
                { 3, 4 }
        };
        System.out.println(sol.isBridge(5, edges2, 0, 2)); // false
    }
}
