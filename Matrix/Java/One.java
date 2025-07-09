import java.util.ArrayList;

class Solution {
    public ArrayList<Integer> spirallyTraverse(int[][] mat) {
        ArrayList<Integer> ans = new ArrayList<>();
        int startRow = 0, endRow = mat.length - 1, startCol = 0, endCol = mat[0].length - 1;
        while (startRow <= endRow && startCol <= endCol) {
            for (int i = startCol; i <= endCol; i++) {
                ans.add(mat[startRow][i]);
            }
            for (int i = startRow + 1; i <= endRow; i++) {
                ans.add(mat[i][endCol]);
            }
            for (int i = endCol - 1; i >= startCol; i--) {
                if (startRow == endRow) {
                    break;
                }
                ans.add(mat[endRow][i]);
            }
            for (int i = endRow - 1; i >= startRow + 1; i--) {
                if (startCol == endCol) {
                    break;
                }
                ans.add(mat[i][startCol]);
            }
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        return ans;
    }
}

public class One {
    public static void main(String[] args) {
        int mat[][] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
        Solution sol = new Solution();
        System.out.println(sol.spirallyTraverse(mat));
    }
}
