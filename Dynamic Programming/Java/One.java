
class Solution {

    public static int knapsack(int W, int[] val, int[] wt) {
        int n = val.length;
        int[][] dp = new int[n + 1][W + 1];
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (wt[i - 1] <= w) {
                    dp[i][w] = Math.max(dp[i - 1][w],
                            val[i - 1] + dp[i - 1][w - wt[i - 1]]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        return dp[n][W];
    }
}

public class One {

    public static void main(String[] args) {
        System.out.println(Solution.knapsack(4, new int[]{1, 2, 3}, new int[]{4, 5, 1}));
        System.out.println(Solution.knapsack(3, new int[]{1, 2, 3}, new int[]{4, 5, 6}));
        System.out.println(Solution.knapsack(5, new int[]{10, 40, 30, 50}, new int[]{5, 4, 2, 3}));
    }
}
