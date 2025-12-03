import java.util.ArrayList;

class Solution {
    ArrayList<Integer> ans;

    private void dfsHelper(int node, ArrayList<ArrayList<Integer>> adj, boolean visited[]) {
        ans.add(node);
        visited[node] = true;
        for (int neighbour : adj.get(node)) {
            if (!visited[neighbour]) {
                dfsHelper(neighbour, adj, visited);
            }
        }
    }

    public ArrayList<Integer> dfs(ArrayList<ArrayList<Integer>> adj) {
        ans = new ArrayList<>();
        int noOfVertices = adj.size();
        boolean visited[] = new boolean[noOfVertices];
        for (int i = 0; i < noOfVertices; i++) {
            if (!visited[i]) {
                dfsHelper(i, adj, visited);
            }
        }
        return ans;
    }
}

public class Three {
    public static void main(String[] args) {

    }
}
