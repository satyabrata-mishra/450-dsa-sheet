import java.util.ArrayList;
import java.util.Stack;

class Solution {
    private ArrayList<ArrayList<Integer>> createAdjacencyList(int v, int[][] edges) {
        ArrayList<ArrayList<Integer>> adjacencyList = new ArrayList<>();
        for (int i = 0; i < v; i++)
            adjacencyList.add(new ArrayList<>());

        for (int[] e : edges) {
            adjacencyList.get(e[0]).add(e[1]);
        }
        return adjacencyList;
    }

    private void dfs(int src, ArrayList<ArrayList<Integer>> adjacencyList, boolean visited[], Stack<Integer> st) {
        visited[src] = true;
        for (int neighbour : adjacencyList.get(src)) {
            if (!visited[neighbour]) {
                dfs(neighbour, adjacencyList, visited, st);
            }
        }
        st.add(src);
    }

    public ArrayList<Integer> topoSort(int V, int[][] edges) {
        ArrayList<ArrayList<Integer>> adjacencyList = createAdjacencyList(V, edges);
        boolean visited[] = new boolean[V];
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adjacencyList, visited, st);
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();
        while (!st.isEmpty()) {
            ans.add(st.pop());
        }
        return ans;
    }
}

public class Thirteen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.topoSort(4, new int[][] { { 3, 0 }, { 1, 0 }, { 2, 0 } }));
    }
}
