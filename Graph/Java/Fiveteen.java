import java.util.ArrayList;
import java.util.List;

class Solution {

    private boolean dfs(int src, List<List<Integer>> adjacencyList, int[] visited) {
        visited[src] = 1; // visiting
        for (int neighbour : adjacencyList.get(src)) {
            if (visited[neighbour] == 1) {
                // cycle detected
                return false;
            }
            if (visited[neighbour] == 0) {
                if (!dfs(neighbour, adjacencyList, visited)) {
                    return false;
                }
            }
        }
        visited[src] = 2; // visited
        return true;
    }

    public boolean canFinish(int n, int[][] prerequisites) {
        List<List<Integer>> adjacencyList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjacencyList.add(new ArrayList<>());
        }
        for (int[] p : prerequisites) {
            adjacencyList.get(p[0]).add(p[1]);
        }
        int[] visited = new int[n]; // 0 = unvisited, 1 = visiting, 2 = visited
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, adjacencyList, visited)) {
                    return false;
                }
            }
        }
        return true;
    }
}

public class Fiveteen {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.canFinish(4, new int[][] { { 2, 0 }, { 2, 1 }, { 3, 2 } })); // 1 (true)
        System.out.println(sol.canFinish(3, new int[][] { { 0, 1 }, { 1, 2 }, { 2, 0 } })); // 0 (false)
    }
}
