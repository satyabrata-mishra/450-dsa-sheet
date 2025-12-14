class Solution {
    public int isNegativeWeightCycle(int n, int[][] edges) {

        int[] distance = new int[n + 1];
        for (int i = 1; i < n; i++) {
            for (int[] j : edges) {
                int u = j[0], v = j[1], wt = j[2];

                if (distance[u] + wt < distance[v]) {
                    distance[v] = distance[u] + wt;
                }
            }
        }
        for (int[] j : edges) {
            int u = j[0], v = j[1], wt = j[2];

            if (distance[u] + wt < distance[v]) {
                return 1;
            }
        }
        return 0;
    }
}

public class Twentynine {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int n = 3;
        int[][] edges1 = {
                { 0, 1, -1 },
                { 1, 2, -2 },
                { 2, 0, -3 }
        };
        System.out.println(sol.isNegativeWeightCycle(n, edges1)); // 1

        n = 3;
        int[][] edges2 = {
                { 0, 1, -1 },
                { 1, 2, -2 },
                { 2, 0, 3 }
        };
        System.out.println(sol.isNegativeWeightCycle(n, edges2)); // 0
    }
}
