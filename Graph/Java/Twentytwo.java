class Solution {
    public void floydWarshall(int[][] dist) {
        int n = dist.length;
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] == 100000000 || dist[via][j] == 100000000)
                        continue;
                    dist[i][j] = Math.min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }
}

public class Twentytwo {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int dist[][] = { { 0, 4, 100000000, 5, 100000000 }, { 100000000, 0, 1, 100000000, 6 },
                { 2, 100000000, 0, 3, 100000000 }, { 100000000, 100000000, 1, 0, 2 },
                { 1, 100000000, 100000000, 4, 0 } };
        sol.floydWarshall(dist);
        for (int i[] : dist) {
            for (int j : i) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}
