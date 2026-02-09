import java.util.*;

class Solution {
    public int celebrity(int[][] mat) {
        int n = mat.length;
        int top = 0, down = n - 1;
        // Step 1: Find potential celebrity
        while (top < down) {
            if (mat[top][down] == 1) {
                top++;
            } else {
                down--;
            }
        }
        // Step 2: Verify the candidate
        for (int i = 0; i < n; i++) {
            if (i != top && (mat[top][i] == 1 || mat[i][top] == 0)) {
                return -1;
            }
        }
        return top;
    }
}

public class Nine {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.celebrity(new int[][] { { 1, 1, 0 }, { 0, 1, 0 }, { 0, 1, 1 } }));// 1
        System.out.println(sol.celebrity(new int[][] { { 1, 1 }, { 1, 1 } }));// -1
        System.out.println(sol.celebrity(new int[][] { { 1 } }));// 0
    }
}
