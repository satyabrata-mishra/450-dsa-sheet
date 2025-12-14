import java.util.*;

class Solution {
    private static class Triple implements Comparable<Triple> {
        int weight, node, parent;

        Triple(int weight, int node, int parent) {
            this.weight = weight;
            this.node = node;
            this.parent = parent;
        }

        @Override
        public int compareTo(Triple other) {
            return Integer.compare(this.weight, other.weight);
        }
    }

    private List<List<int[]>> createAdjacencyList(int[][] edges, int V) {
        List<List<int[]>> adjacencyList = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adjacencyList.add(new ArrayList<>());
        }
        for (int[] e : edges) {
            adjacencyList.get(e[0]).add(new int[] { e[1], e[2] });
            adjacencyList.get(e[1]).add(new int[] { e[0], e[2] });
        }
        return adjacencyList;
    }

    public int spanningTree(int V, int[][] edges) {
        List<List<int[]>> adjacencyList = createAdjacencyList(edges, V);
        PriorityQueue<Triple> minHeap = new PriorityQueue<>();
        boolean[] visited = new boolean[V];
        ArrayList<Integer> mst = new ArrayList<>();
        minHeap.add(new Triple(0, 0, -1));
        int sum = 0;
        while (!minHeap.isEmpty()) {
            Triple top = minHeap.poll();
            int weight = top.weight;
            int node = top.node;
            int parent = top.parent;
            if (visited[node])
                continue;
            visited[node] = true;
            sum += weight;
            mst.add(node);
            for (int[] nbr : adjacencyList.get(node)) {
                int neighNode = nbr[0];
                int neighWeight = nbr[1];
                if (!visited[neighNode]) {
                    minHeap.add(new Triple(neighWeight, neighNode, node));
                }
            }
        }
        // System.out.println(mst);
        return sum;
    }
}

public class Nineteen {
    public static void main(String[] args) {

        Solution sol = new Solution();

        // Example 1
        int V1 = 3;
        int[][] edges1 = {
                { 0, 1, 5 },
                { 1, 2, 3 },
                { 0, 2, 1 }
        };

        int mstSum1 = sol.spanningTree(V1, edges1);
        System.out.println("MST Total Weight: " + mstSum1); // Expected: 4

        // Example 2
        int V2 = 2;
        int[][] edges2 = {
                { 0, 1, 5 }
        };

        int mstSum2 = sol.spanningTree(V2, edges2);
        System.out.println("MST Total Weight: " + mstSum2); // Expected: 5
    }
}
