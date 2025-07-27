import java.util.Arrays;

class Solution {
    int[][] sortedMatrix(int N, int Mat[][]) {
        int r = Mat.length, c = Mat[0].length, index = 0;
        int arr[] = new int[r * c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                arr[index++] = Mat[i][j];
            }
        }
        Arrays.sort(arr);
        index = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                Mat[i][j] = arr[index++];
            }
        }
        return Mat;

    }
};

public class Four {
    public static void main(String[] args) {
        int arr[][] = { { 10, 20, 30, 40 },
                { 15, 25, 35, 45 },
                { 27, 29, 37, 48 },
                { 32, 33, 39, 50 } };
        Solution sol = new Solution();
        arr = sol.sortedMatrix(arr.length, arr);
        for (int[] i : arr) {
            for (int j : i) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}
