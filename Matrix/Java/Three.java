class Solution {
    public int rowWithMax1s(int arr[][]) {
        int maxOnes = 0, index = -1, row = arr.length, col = arr[0].length;
        for (int i = 0; i < row; i++) {
            int sum = 0;
            for (int j = 0; j < col; j++) {
                sum += arr[i][j];
            }
            if (sum > maxOnes) {
                maxOnes = sum;
                index = i;
            }
        }
        return index;
    }
}

public class Three {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int arr[][] = { { 0, 1, 1, 1 }, { 0, 0, 1, 1 }, { 1, 1, 1, 1 }, { 0, 0, 0, 0 } };
        System.out.println(sol.rowWithMax1s(arr));
        arr = new int[][] { { 0, 0 }, { 0, 0 } };
        System.out.println(sol.rowWithMax1s(arr));
    }
}
