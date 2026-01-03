import java.util.ArrayList;

class Solution {
    public int[][] searchWord(char[][] grid, String word) {

        int n = grid.length;
        int m = grid[0].length;
        int len = word.length();

        int[] delRow = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int[] delCol = { -1, 0, 1, -1, 1, -1, 0, 1 };

        ArrayListt<int[]> list = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] != word.charAt(0))
                    continue;

                for (int dir = 0; dir < 8; dir++) {
                    int r = i, c = j, k = 0;

                    while (k < len) {
                        if (r >= 0 && r < n && c >= 0 && c < m &&
                                grid[r][c] == word.charAt(k)) {

                            r += delRow[dir];
                            c += delCol[dir];
                            k++;
                        } else {
                            break;
                        }
                    }

                    if (k == len) {
                        list.add(new int[] { i, j });
                    }
                }
            }
        }
        int ans[][] = new int[list.size()][2];
        for (int i = 0; i < list.size(); i++) {
            ans[i][0] = list.get(i)[0];
            ans[i][1] = list.get(i)[1];
        }
        return ans;
    }
}

public class Twentythree {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(
                sol.searchWord(new char[][] { { 'a', 'b', 'a', 'b' }, { 'a', 'b', 'e', 'b' }, { 'e', 'b', 'e', 'b' } },
                        "abe"));// {{0,0},{0,2},{1,0}}
        System.out.println(
                sol.searchWord(new char[][] { { 'a', 'b', 'c' }, { 'd', 'r', 'f' }, { 'g', 'h', 'i' } }, "abc"));// {{0,0}}
    }
}
