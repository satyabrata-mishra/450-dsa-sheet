class Solution {
    private void dfs(int row, int col, int image[][], int ans[][], int newColor, int iniColor, int delRows[],
            int delCols[]) {
        ans[row][col] = newColor;
        int rSize = image.length, cSize = image[0].length;
        for (int i = 0; i < 4; i++) {
            int nRow = row + delRows[i];
            int nCol = col + delCols[i];
            if (nRow >= 0 && nRow < rSize && nCol >= 0 && nCol < cSize && image[nRow][nCol] == iniColor
                    && ans[nRow][nCol] != newColor) {
                dfs(nRow, nCol, image, ans, newColor, iniColor, delRows, delCols);
            }
        }
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int ans[][] = image;
        int iniColor = image[sr][sc];
        int delRows[] = { -1, 0, 1, 0 };
        int delCols[] = { 0, 1, 0, -1 };
        dfs(sr, sc, image, ans, newColor, iniColor, delRows, delCols);
        return ans;
    }
}

public class Eight {
public static void main(String[] args) {
    image[][] = [[1, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]], sr = 1, sc = 2, newColor = 2
}
}
