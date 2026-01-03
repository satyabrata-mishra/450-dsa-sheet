import java.util.*;

class Solution {
    private int[][] movement = {
            { -1, 0 }, // U
            { 0, 1 }, // R
            { 1, 0 }, // D
            { 0, -1 } // L
    };

    private void markUnsafe(int[][] mat) {
        int r = mat.length;
        int c = mat[0].length;

        int[][] temp = new int[r][c];
        for (int i = 0; i < r; i++)
            temp[i] = mat[i].clone();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (temp[i][j] == 0) {
                    mat[i][j] = 0;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + movement[k][0];
                        int nj = j + movement[k][1];
                        if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                            mat[ni][nj] = 0;
                        }
                    }
                }
            }
        }
    }

    public int findShortestPath(int[][] mat) {
        int r = mat.length;
        int c = mat[0].length;

        markUnsafe(mat);

        Queue<int[]> q = new LinkedList<>();
        int[][] dist = new int[r][c];
        for (int[] row : dist)
            Arrays.fill(row, -1);

        // Multi-source BFS from first column
        for (int i = 0; i < r; i++) {
            if (mat[i][0] == 1) {
                q.offer(new int[] { i, 0 });
                dist[i][0] = 0;
            }
        }

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int row = cur[0], col = cur[1];

            if (col == c - 1)
                return dist[row][col] + 1;

            for (int k = 0; k < 4; k++) {
                int nr = row + movement[k][0];
                int nc = col + movement[k][1];

                if (nr >= 0 && nr < r &&
                        nc >= 0 && nc < c &&
                        mat[nr][nc] == 1 &&
                        dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[row][col] + 1;
                    q.offer(new int[] { nr, nc });
                }
            }
        }

        return -1;
    }
}

public class Ten {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[][] mat1 = {
                { 1, 0, 1, 1, 1 },
                { 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1 },
                { 1, 1, 1, 0, 1 },
                { 1, 1, 1, 1, 0 }
        };

        int[][] mat2 = {
                { 1, 1, 1, 1, 1 },
                { 1, 1, 0, 1, 1 },
                { 1, 1, 1, 1, 1 }
        };

        System.out.println(sol.findShortestPath(mat1)); // Output: 6
        System.out.println(sol.findShortestPath(mat2)); // Output: -1
    }
}
