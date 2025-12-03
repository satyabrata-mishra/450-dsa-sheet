import java.util.*;

class Solution {

    private List<List<int[]>> createAdjacencyList(int[][] edges, int v) {
        List<List<int[]>> adjacencyList = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adjacencyList.add(new ArrayList<>());
        }

        for (int[] e : edges) {
            adjacencyList.get(e[0]).add(new int[] { e[1], e[2] });
            adjacencyList.get(e[1]).add(new int[] { e[0], e[2] });
        }
        return adjacencyList;
    }

    public int[] dijkstra(int V, int[][] edges, int src) {
        List<List<int[]>> adjacencyList = createAdjacencyList(edges, V);

        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        minHeap.add(new int[] { 0, src });

        while (!minHeap.isEmpty()) {
            int[] minEle = minHeap.poll();

            for (int[] neighbour : adjacencyList.get(minEle[1])) {
                if (minEle[0] + neighbour[1] < dist[neighbour[0]]) {
                    dist[neighbour[0]] = minEle[0] + neighbour[1];
                    minHeap.add(new int[] { dist[neighbour[0]], neighbour[0] });
                }
            }
        }

        return dist;
    }
}

public class Twelve {
    public static void main(String[] args) {
        Solution sol = new Solution();

        // First test - same as your C++ code
        int[][] edges1 = {
                { 0, 1, 1 },
                { 1, 2, 3 },
                { 0, 2, 6 }
        };
        int src1 = 2, v1 = 3;

        int[] ans1 = sol.dijkstra(v1, edges1, src1);
        for (int d : ans1) {
            System.out.print(d + " ");
        }
        System.out.println();

        // Second test - same as your C++ code
        int[][] edges2 = {
                { 0, 1, 4 },
                { 0, 2, 8 },
                { 1, 4, 6 },
                { 2, 3, 2 },
                { 3, 4, 10 }
        };
        int src2 = 0, v2 = 5;

        int[] ans2 = sol.dijkstra(v2, edges2, src2);
        for (int d : ans2) {
            System.out.print(d + " ");
        }
        System.out.println();
    }
}
