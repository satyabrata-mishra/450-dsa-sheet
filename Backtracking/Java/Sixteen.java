import java.util.ArrayList;

class Solution {
    private static final int[][] movement = {
            { 1, 0 }, // Down
            { 0, 1 } // Right
    };

    private static void dfs(int cRow, int cCol, int dRow, int dCol, ArrayList<ArrayList<Integer>> ans,
            ArrayList<Integer> travelled, int[][] grid) {
        if (cRow == dRow && cCol == dCol) {
            ans.add(new ArrayList<>(travelled));
            return;
        }
        int temp = grid[cRow][cCol];
        grid[cRow][cCol] = -1;
        for (int i = 0; i < movement.length; i++) {
            int nRow = cRow + movement[i][0];
            int nCol = cCol + movement[i][1];

            if (nRow >= 0 && nRow <= dRow &&
                    nCol >= 0 && nCol <= dCol &&
                    grid[nRow][nCol] != -1) {

                travelled.add(grid[nRow][nCol]);
                dfs(nRow, nCol, dRow, dCol, ans, travelled, grid);
                travelled.remove(travelled.size() - 1);
            }
        }
        grid[cRow][cCol] = temp;
    }

    public static ArrayList<ArrayList<Integer>> findAllPossiblePaths(int n, int m, int[][] grid) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        ArrayList<Integer> travelled = new ArrayList<>();
        travelled.add(grid[0][0]);
        dfs(0, 0, n - 1, m - 1, ans, travelled, grid);
        return ans;
    }
}

public class Sixteen {
    public static void main(String[] args) {
        int[][] grid1 = { { 1, 2, 3 }, { 4, 5, 6 } };
        ArrayList<ArrayList<Integer>> result1 = Solution.findAllPossiblePaths(grid1.length, grid1[0].length, grid1);
        for (ArrayList<Integer> path : result1) {
            for (int val : path) {
                System.out.print(val + " ");
            }
            System.out.println();
        }

        System.out.println();
        int[][] grid2 = { { 1, 2 }, { 3, 4 } };
        ArrayList<ArrayList<Integer>> result2 = Solution.findAllPossiblePaths(grid2.length, grid2[0].length, grid2);
        for (ArrayList<Integer> path : result2) {
            for (int val : path) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

}