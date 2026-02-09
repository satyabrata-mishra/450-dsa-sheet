import java.util.*;

class Solution {

    public static int minimumEdgeReversal(int[][] edges, int n, int m, int src, int dst) {

        // convert to 0-based indexing
        src--;
        dst--;

        // adjacency list: node -> {neighbor, weight}
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;

            adj.get(u).add(new int[] { v, 0 }); // original direction
            adj.get(v).add(new int[] { u, 1 }); // reversed direction
        }

        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        // Min-heap: {distance, node}
        PriorityQueue<int[]> pq = new PriorityQueue<>(
                (a, b) -> Integer.compare(a[0], b[0]));

        pq.offer(new int[] { 0, src });

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int currDist = curr[0];
            int u = curr[1];

            if (currDist > dist[u])
                continue;

            for (int[] nbr : adj.get(u)) {
                int v = nbr[0];
                int wt = nbr[1];

                if (dist[v] > currDist + wt) {
                    dist[v] = currDist + wt;
                    pq.offer(new int[] { dist[v], v });
                }
            }
        }

        return dist[dst] == Integer.MAX_VALUE ? -1 : dist[dst];
    }
}

public class Thirtyseven {
    public static void main(String[] args) {
        int[][] edges1 = { { 1, 2 }, { 3, 2 } };
        System.out.println(Solution.minimumEdgeReversal(edges1, 3, 2, 1, 3)); // Expected: 1
        int[][] edges2 = { { 1, 2 }, { 2, 3 }, { 3, 4 } };
        System.out.println(Solution.minimumEdgeReversal(edges2, 4, 3, 1, 4)); // Expected: 0
    }
}
