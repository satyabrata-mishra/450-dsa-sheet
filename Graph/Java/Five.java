import java.util.*;

import java.util.*;

class Solution {

    private ArrayList<ArrayList<Integer>> createAdjacencyList(int v, int[][] edges) {
        ArrayList<ArrayList<Integer>> adjacencyList = new ArrayList<>();
        for (int i = 0; i < v; i++)
            adjacencyList.add(new ArrayList<>());

        for (int[] e : edges) {
            adjacencyList.get(e[0]).add(e[1]);
            adjacencyList.get(e[1]).add(e[0]);
        }
        return adjacencyList;
    }

    private boolean BFSHelper(int src, ArrayList<ArrayList<Integer>> adjacencyList, boolean[] visited, int v) {
        int[] parent = new int[v];
        Arrays.fill(parent, -1);

        Queue<Integer> q = new LinkedList<>();
        visited[src] = true;
        q.offer(src);

        while (!q.isEmpty()) {
            int temp = q.poll();

            for (int neighbour : adjacencyList.get(temp)) {
                if (!visited[neighbour]) {
                    parent[neighbour] = temp;
                    visited[neighbour] = true;
                    q.offer(neighbour);
                } else if (neighbour != parent[temp]) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean detectCycleUsingBFS(int v, int[][] edges) {
        ArrayList<ArrayList<Integer>> adjacencyList = createAdjacencyList(v, edges);
        boolean[] visited = new boolean[v];

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (BFSHelper(i, adjacencyList, visited, v)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean DFSHelper(int src, int parent, ArrayList<ArrayList<Integer>> adjacencyList, boolean[] visited) {
        visited[src] = true;

        for (int neighbour : adjacencyList.get(src)) {
            if (!visited[neighbour]) {
                if (DFSHelper(neighbour, src, adjacencyList, visited)) {
                    return true;
                }
            } else if (neighbour != parent) {
                return true;
            }
        }
        return false;
    }

    private boolean detectCycleUsingDFS(int v, int[][] edges) {
        ArrayList<ArrayList<Integer>> adjacencyList = createAdjacencyList(v, edges);
        boolean[] visited = new boolean[v];

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (DFSHelper(i, -1, adjacencyList, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean isCycle(int V, int[][] edges) {
        return detectCycleUsingBFS(V, edges);
        // return detectCycleUsingDFS(V, edges);
    }
}

public class Five {
    public static void main(String[] args) {
    }
}
