
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
                }
            }
        }
        return dp[l1][l2][l3];
    }
}

public class Seventeen {

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.lcsOf3("geeks", "geeksfor", "geeksforgeeks"));
        System.out.println(sol.lcsOf3("abcd1e2", "bc12ea", "bd1ea"));
    }
}
