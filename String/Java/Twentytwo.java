// User function Template for Java

class Solution {

    private int[] delRow = { -1, 0, 1, 0 };
    private int[] delCol = { 0, 1, 0, -1 };

    private void dfs(char[][] mat, String target, int targetSize, int cRow, int cCol, int rSize, int cSize, int index,
            int[] ans) {

        if (index == targetSize) {
            ans[0]++;
            return;
        }

        char temp = mat[cRow][cCol];
        mat[cRow][cCol] = '#'; // mark visited

        for (int i = 0; i < 4; i++) {
            int nRow = cRow + delRow[i];
            int nCol = cCol + delCol[i];

            if (nRow >= 0 && nRow < rSize &&
                    nCol >= 0 && nCol < cSize &&
                    mat[nRow][nCol] == target.charAt(index)) {

                dfs(mat, target, targetSize,
                        nRow, nCol, rSize, cSize,
                        index + 1, ans);
            }
        }
        mat[cRow][cCol] = temp; // backtrack
    }

    public int findOccurrence(char[][] mat, String target) {
        int rSize = mat.length;
        int cSize = mat[0].length;
        int targetSize = target.length();

        int[] ans = new int[1]; // to simulate pass-by-reference

        for (int i = 0; i < rSize; i++) {
            for (int j = 0; j < cSize; j++) {
                if (mat[i][j] == target.charAt(0)) {
                    dfs(mat, target, targetSize, i, j, rSize, cSize, 1, ans);
                }
            }
        }
        return ans[0];
    }
}

public class Twentytwo {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.err.println(sol.findOccurrence(new char[][] { { 'S', 'N', 'B', 'S', 'N' }, { 'B', 'A', 'K', 'E', 'A' },
                { 'B', 'K', 'B', 'B', 'K' }, { 'S', 'E', 'B', 'S', 'E' } }, "SNAKES")); // 3
        System.err.println(
                sol.findOccurrence(new char[][] { { 'c', 'a', 't' }, { 'a', 't', 'c' }, { 'c', 't', 'a' } }, "cat")); // 5
    }
}
