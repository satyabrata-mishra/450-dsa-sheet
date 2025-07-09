
class Solution {

    public int editDistance(String s1, String s2) {
        int n1 = s1.length(), n2 = s2.length();
        int dp[][] = new int[n1 + 1][n2 + 1];
        for (int i = 0; i <= n1; i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n2; i++) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1.charAt(i - 1) != s2.charAt(j - 1)) {
                    dp[i][j] = 1 + Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1]));
                } else {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[n1][n2];
    }
}

public class Thirteen {

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.editDistance("geek", "gesek"));
        System.out.println(sol.editDistance("gfg", "gfg"));
        System.out.println(sol.editDistance("abcd", "bcfe"));
    }
}
