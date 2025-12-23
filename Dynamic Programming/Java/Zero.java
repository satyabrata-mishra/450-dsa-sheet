class Solution {
    public int count(int coins[], int sum) {
        int n = coins.length;
        int dp[][] = new int[n][sum + 1];
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= sum; i++) {
            dp[0][i] = (i % coins[0] == 0 ? 1 : 0);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (coins[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
                }
            }
        }
        return dp[n - 1][sum];
    }
}

public class Zero {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.count(new int[] { 1, 2, 3 }, 4));// 4
        System.out.println(sol.count(new int[] { 2, 5, 3, 6 }, 10));// 5
        System.out.println(sol.count(new int[] { 5, 10 }, 3));// 0
    }
}
