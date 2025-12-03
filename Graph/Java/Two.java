import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public ArrayList<Integer> bfs(ArrayList<ArrayList<Integer>> adj) {
        ArrayList<Integer> ans = new ArrayList<>();
        int noOfVertices = adj.size();
        boolean visited[] = new boolean[noOfVertices];
        Queue<Integer> q = new LinkedList<>();
        visited[0] = true;
        ans.add(0);
        q.add(0);
        while (!q.isEmpty()) {
            int temp = q.poll();
            for (int neighbour : adj.get(temp)) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    ans.add(neighbour);
                    q.add(neighbour);
                }
            }
        }
        return ans;
    }
}

public class Two {
    public static void main(String[] args) {
        Solution sol = new Solution();
    }
}
