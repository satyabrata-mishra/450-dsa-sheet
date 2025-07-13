
class Solution {

    public int nCr(int n, int r) {
        int dp[][] = new int[n + 1][r + 1];
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= r; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        return dp[n][r];
    }
}

public class Two {

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.nCr(5, 2));
    }
}
