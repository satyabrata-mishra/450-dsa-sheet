class Solution {

    // Function to get cofactor of matrix[r][c]
    private static void cofactor(int[][] matrix, int[][] temp, int r, int c, int n) {
        int i = 0, j = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (row != r && col != c) {
                    temp[i][j++] = matrix[row][col];
                    if (j == n - 1) {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }

    // Recursive function to find determinant
    private static int determinantOfMatrix(int[][] matrix, int n) {
        if (n == 1) {
            return matrix[0][0];
        }

        int ans = 0;
        int sign = 1;

        int[][] temp = new int[n][n];

        for (int i = 0; i < n; i++) {
            cofactor(matrix, temp, 0, i, n);
            ans += sign * matrix[0][i] * determinantOfMatrix(temp, n - 1);
            sign = -sign;
        }

        return ans;
    }

    // Main function
    public static int countSpanningTrees(int[][] graph, int n, int m) {

        // Build adjacency matrix
        int[][] adjacencyMatrix = new int[n][n];
        for (int i = 0; i < m; i++) {
            int u = graph[i][0];
            int v = graph[i][1];
            adjacencyMatrix[u][v] = 1;
            adjacencyMatrix[v][u] = 1;
        }

        // Build Laplacian matrix
        int[][] lap = new int[n][n];
        for (int i = 0; i < n; i++) {
            int degree = 0;
            for (int j = 0; j < n; j++) {
                if (adjacencyMatrix[i][j] == 1) {
                    degree++;
                    lap[i][j] = -1;
                }
            }
            lap[i][i] = degree;
        }

        // Remove last row and column (cofactor matrix)
        int[][] cofactor = new int[n - 1][n - 1];
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                cofactor[i][j] = lap[i][j];
            }
        }

        return determinantOfMatrix(cofactor, n - 1);
    }
}

public class Twenty {
    public static void main(String[] args) {
        System.out.println(
                Solution.countSpanningTrees(new int[][] { { 0, 3 }, { 0, 1 }, { 1, 2 }, { 1, 5 }, { 3, 4 } }, 6, 5)); // 1
    }
}
