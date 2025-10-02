<<<<<<< HEAD

class Solution {

    int lcsOf3(String s1, String s2, String s3) {
int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        vector<vector<vector<int>>> dp(l1 + 1, vector<vector<int>>(l2 + 1, vector<int>(l3 + 1, 0)));
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                for (int k = 1; k <= l3; k++)
                {
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                        dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                    else
                        dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
=======
class Solution {
    int lcsOf3(String s1, String s2, String s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        int dp[][][] = new int[l1 + 1][l2 + 1][l3 + 1];
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                for (int k = 1; k <= l3; k++) {
                    if (s1.charAt(i - 1) == s2.charAt(j - 1) && s2.charAt(j - 1) == s3.charAt(k - 1))
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    else
                        dp[i][j][k] = Math.max(dp[i - 1][j][k], Math.max(dp[i][j - 1][k], dp[i][j][k - 1]));
>>>>>>> cfe98d4487746c97708b1cdeaa97da533cdf6e3d
                }
            }
        }
        return dp[l1][l2][l3];
    }
}

public class Seventeen {
<<<<<<< HEAD

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.lcsOf3("geeks", "geeksfor", "geeksforgeeks"));
        System.out.println(sol.lcsOf3("abcd1e2", "bc12ea", "bd1ea"));
=======
    public static void main(String[] args) {
        Solution sol = new Solution();
        String s1 = "geeks", s2 = "geeksfor", s3 = "geeksforgeeks";
        System.out.println(sol.lcsOf3(s1, s2, s3));
        s1 = "abcd1e2";
        s2 = "bc12ea";
        s3 = "bd1ea";
        System.out.println(sol.lcsOf3(s1, s2, s3));
>>>>>>> cfe98d4487746c97708b1cdeaa97da533cdf6e3d
    }
}
