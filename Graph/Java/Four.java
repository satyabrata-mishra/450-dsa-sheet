import java.util.*;

class Solution {

    private List<List<Integer>> createAdjacencyList(int[][] edges, int v) {
        List<List<Integer>> adjacencyList = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adjacencyList.add(new ArrayList<>());
        }

        for (int[] e : edges) {
            adjacencyList.get(e[0]).add(e[1]);
        }

        return adjacencyList;
    }

    private boolean dfsCheck(int src, List<List<Integer>> adjacencyList,
            boolean[] visited, boolean[] pathVisited) {

        visited[src] = true;
        pathVisited[src] = true;

        for (int neighbour : adjacencyList.get(src)) {
            if (!visited[neighbour]) {
                if (dfsCheck(neighbour, adjacencyList, visited, pathVisited)) {
                    return true;
                }
            } else if (pathVisited[neighbour]) {
                return true;
            }
        }

        pathVisited[src] = false;
        return false;
    }

    private boolean checkCycleUsingDFS(int[][] edges, int v) {
        boolean[] visited = new boolean[v];
        boolean[] pathVisited = new boolean[v];

        List<List<Integer>> adjacencyList = createAdjacencyList(edges, v);

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (dfsCheck(i, adjacencyList, visited, pathVisited)) {
                    return true;
                }
            }
        }

        return false;
    }

    public boolean isCyclic(int V, int edges[][]) {
        return checkCycleUsingDFS(edges, V);
    }

}

public class Four {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[][] edges1 = { { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 3 } };
        System.out.println(sol.isCyclic(4, edges1)); // 1

        int[][] edges2 = { { 0, 1 }, { 0, 2 }, { 1, 2 }, { 2, 3 } };
        System.out.println(sol.isCyclic(4, edges2)); // 0
    }
}
