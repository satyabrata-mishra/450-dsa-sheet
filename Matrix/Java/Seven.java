
class GFG {

    static void rotate(int mat[][]) {
        for (int i = 0; i < mat.length; i++) {
            for (int j = i + 1; j < mat[0].length; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }
        for (int[] mat1 : mat) {
            int left = 0, right = mat[0].length - 1;
            while (left < right) {
                int temp = mat1[left];
                mat1[left] = mat1[right];
                mat1[right] = temp;
                ++left;
                --right;
            }
        }
    }
}

public class Seven {

    public static void main(String[] args) {
        int mat[][] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        GFG.rotate(mat);
        for (int i[] : mat) {
            for (int j : i) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}
