import java.util.*;

class Solution {
    public ArrayList<ArrayList<Integer>> nearest(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;

        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < row; i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int j = 0; j < col; j++) {
                temp.add(-1);
            }
            ans.add(temp);
        }

        Queue<int[]> q = new LinkedList<>();

        // Push all cells with value 1 into queue
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    q.offer(new int[] { i, j });
                    ans.get(i).set(j, 0);
                }
            }
        }

        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, -1, 0, 1 };

        // BFS traversal
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int x = curr[0];
            int y = curr[1];

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < row &&
                        newY >= 0 && newY < col &&
                        ans.get(newX).get(newY) == -1) {

                    ans.get(newX).set(newY, ans.get(x).get(y) + 1);
                    q.offer(new int[] { newX, newY });
                }
            }
        }

        return ans;
    }
}

public class Thirtyone {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.nearest(new int[][] { { 0, 1, 1, 0 }, { 1, 1, 0, 0 }, { 0, 0, 1, 1 } }));
    }
}
