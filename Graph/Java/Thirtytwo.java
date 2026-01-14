import java.util.*;

class Solution {
    static class Pair {
        int first; // destination node
        int second; // cost

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class Tuple {
        int stops;
        int node;
        int distance;

        Tuple(int stops, int node, int distance) {
            this.stops = stops;
            this.node = node;
            this.distance = distance;
        }
    }

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        List<List<Pair>> adjacencyList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjacencyList.add(new ArrayList<>());
        }
        for (int[] flight : flights) {
            adjacencyList.get(flight[0]).add(new Pair(flight[1], flight[2]));
        }
        Queue<Tuple> q = new LinkedList<>();
        int[] distance = new int[n];
        Arrays.fill(distance, Integer.MAX_VALUE);
        q.offer(new Tuple(0, src, 0));
        distance[src] = 0;
        while (!q.isEmpty()) {
            Tuple cur = q.poll();
            int stops = cur.stops;
            int curNode = cur.node;
            int curDistance = cur.distance;
            if (stops > k) {
                break;
            }
            for (Pair neighbour : adjacencyList.get(curNode)) {
                if (curDistance + neighbour.second < distance[neighbour.first]) {
                    distance[neighbour.first] = curDistance + neighbour.second;
                    q.offer(new Tuple(stops + 1, neighbour.first, distance[neighbour.first]));
                }
            }
        }
        return distance[dst] == Integer.MAX_VALUE ? -1 : distance[dst];
    }
}

public class Thirtytwo {
    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println(sol.findCheapestPrice(
                4,
                new int[][] { { 0, 1, 100 }, { 1, 2, 100 }, { 2, 0, 100 }, { 1, 3, 600 }, { 2, 3, 200 } },
                0, 3, 1)); // 700

        System.out.println(sol.findCheapestPrice(
                3,
                new int[][] { { 0, 1, 100 }, { 1, 2, 100 }, { 0, 2, 500 } },
                0, 2, 1)); // 200

        System.out.println(sol.findCheapestPrice(
                3,
                new int[][] { { 0, 1, 100 }, { 1, 2, 100 }, { 0, 2, 500 } },
                0, 2, 0)); // 500
    }
}
