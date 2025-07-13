
class Solution {

    public int permutationCoeff(int n, int k) {
        int dp[][] = new int[n + 1][k + 1];
        int mod = 1000000007;
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k && j <= i; ++j) {
                dp[i][j] = (dp[i - 1][j] + j * dp[i - 1][j - 1] % mod) % mod;
            }
        }
        return dp[n][k];
    }
}

public class Three {

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.permutationCoeff(10, 2));
        System.out.println(sol.permutationCoeff(10, 3));
        System.out.println(sol.permutationCoeff(14, 12));// 589145299
        System.out.println(sol.permutationCoeff(100000, 16348));// 478193331
    }
}
