import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    private void dfsWithStack(int src, ArrayList<ArrayList<Integer>> adj, boolean[] visited, Stack<Integer> st) {
        visited[src] = true;
        for (int neighbour : adj.get(src)) {
            if (!visited[neighbour]) {
                dfsWithStack(neighbour, adj, visited, st);
            }
        }
        st.push(src);
    }

    private void dfs(int src, ArrayList<ArrayList<Integer>> revAdjList, boolean[] visited) {
        visited[src] = true;
        for (int neighbour : revAdjList.get(src)) {
            if (!visited[neighbour]) {
                dfs(neighbour, revAdjList, visited);
            }
        }
    }

    public int kosaraju(ArrayList<ArrayList<Integer>> adj) {
        int v = adj.size();
        boolean[] visited = new boolean[v];
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfsWithStack(i, adj, visited, st);
            }
        }
        ArrayList<ArrayList<Integer>> revAdjList = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            revAdjList.add(new ArrayList<>());
        }

        for (int i = 0; i < v; i++) {
            for (int neighbour : adj.get(i)) {
                revAdjList.get(neighbour).add(i);
            }
        }
        Arrays.fill(visited, false);
        int scc = 0;
        while (!st.isEmpty()) {
            int node = st.pop();
            if (!visited[node]) {
                scc++;
                dfs(node, revAdjList, visited);
            }
        }
        return scc;
    }
}

public class Twentyseven {
    public static void main(String[] args) {
        Solution sol = new Solution();
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        adj.add(new ArrayList<>(Arrays.asList(2, 3)));
        adj.add(new ArrayList<>(Arrays.asList(0)));
        adj.add(new ArrayList<>(Arrays.asList(1)));
        adj.add(new ArrayList<>(Arrays.asList(4)));
        adj.add(new ArrayList<>());
        System.out.println(sol.kosaraju(adj));
    }
}
