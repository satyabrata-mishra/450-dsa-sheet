import java.util.*;

class Solution {

    private void bfs(int row, int col, int[][] visited, char[][] grid) {
        visited[row][col] = 1;

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] { row, col });

        int n = grid.length;
        int m = grid[0].length;

        while (!q.isEmpty()) {
            int[] p = q.poll();
            int r = p[0];
            int c = p[1];

            for (int delRow = -1; delRow <= 1; delRow++) {
                for (int delCol = -1; delCol <= 1; delCol++) {
                    int newRow = r + delRow;
                    int newCol = c + delCol;

                    if (newRow >= 0 && newRow < n &&
                            newCol >= 0 && newCol < m &&
                            grid[newRow][newCol] == 'L' &&
                            visited[newRow][newCol] == 0) {

                        visited[newRow][newCol] = 1;
                        q.add(new int[] { newRow, newCol });
                    }
                }
            }
        }
    }

    public int countIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[][] visited = new int[n][m];
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0 && grid[i][j] == 'L') {
                    count++;
                    bfs(i, j, visited, grid);
                }
            }
        }
        return count;
    }
}

public class Sixteen {
    public static void main(String[] args) {

        Solution sol = new Solution();

        char[][] grid = {
                { 'L', 'L', 'W', 'W', 'W' },
                { 'W', 'L', 'W', 'W', 'L' },
                { 'L', 'W', 'W', 'L', 'L' },
                { 'W', 'W', 'W', 'W', 'W' },
                { 'L', 'W', 'L', 'L', 'W' }
        };

        System.out.println(sol.countIslands(grid));
    }
}
