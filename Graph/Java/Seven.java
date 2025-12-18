import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int minStepToReachTarget(int knightPos[], int targetPos[], int n) {
        int tx = targetPos[0] - 1, ty = targetPos[1] - 1;
        if (knightPos[0] - 1 == tx && knightPos[1] - 1 == ty) {
            return 0;
        }
        int dRow[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
        int dCOl[] = { 2, 2, 1, -1, -2, -2, -1, 1 };
        boolean visited[][] = new boolean[n][n];
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] { knightPos[0] - 1, knightPos[1] - 1 });
        visited[knightPos[0] - 1][knightPos[1] - 1] = true;
        int ans = 0;
        while (!q.isEmpty()) {
            ++ans;
            int size = q.size();
            for (int j = 0; j < size; j++) {
                int index[] = q.poll();
                for (int i = 0; i < 8; i++) {
                    int nx = index[0] + dRow[i];
                    int ny = index[1] + dCOl[i];
                    if (nx == tx && ny == ty) {
                        return ans;
                    }
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                        q.add(new int[] { nx, ny });
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        return ans;
    }
}

public class Seven {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.minStepToReachTarget(new int[] { 3, 3 }, new int[] { 1, 2 }, 3));
        System.out.println(sol.minStepToReachTarget(new int[] { 4, 5 }, new int[] { 1, 1 }, 6));
    }
}
