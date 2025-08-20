/*You are required to complete below method */

class Solution {
    int countPS(String s) {
        int n = s.length();
        int dp[][] = new int[n][n];
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }
            }
        }
        return dp[0][n - 1];
    }
}

public class TwentyOne {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.countPS("aab"));
        System.out.println(sol.countPS("zvquhctuvpdcumqtvdjvzbodockbic"));
    }
}
