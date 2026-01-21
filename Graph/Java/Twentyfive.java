import java.util.*;

class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        int[] arr = new int[n * n + 1];
        Arrays.fill(arr, -1);

        // Convert 2D board to 1D
        int idx = 1;
        boolean leftToRight = true;

        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++)
                    arr[idx++] = board[i][j];
            } else {
                for (int j = n - 1; j >= 0; j--)
                    arr[idx++] = board[i][j];
            }
            leftToRight = !leftToRight;
        }

        Queue<int[]> q = new LinkedList<>(); // {position, steps}
        boolean[] visited = new boolean[n * n + 1];

        q.offer(new int[] { 1, 0 });
        visited[1] = true;

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int pos = curr[0];
            int steps = curr[1];

            if (pos == n * n)
                return steps;

            for (int dice = 1; dice <= 6; dice++) {
                int next = pos + dice;
                if (next > n * n)
                    break;

                if (arr[next] != -1)
                    next = arr[next];

                if (!visited[next]) {
                    visited[next] = true;
                    q.offer(new int[] { next, steps + 1 });
                }
            }
        }
        return -1;
    }
}

public class Twentyfive {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[][] board1 = {
                { -1, -1, -1, -1, -1, -1 },
                { -1, -1, -1, -1, -1, -1 },
                { -1, -1, -1, -1, -1, -1 },
                { -1, 35, -1, -1, 13, -1 },
                { -1, -1, -1, -1, -1, -1 },
                { -1, 15, -1, -1, -1, -1 }
        };

        System.out.println(sol.snakesAndLadders(board1)); // 4

        int[][] board2 = {
                { -1, -1 },
                { -1, 3 }
        };

        System.out.println(sol.snakesAndLadders(board2)); // 1
    }
}
