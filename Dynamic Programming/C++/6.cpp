#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    // Function to compute the edit distance between two strings
    int editDistance(string &s1, string &s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        int dp[n1 + 1][n2 + 1];
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n2; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] != s2[j - 1])
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[n1][n2];
    }
};
int main()
{
    Solution sol;
    string str1 = "geek", str2 = "gesek";
    cout << sol.editDistance(str1, str2) << "\n";
    return 0;
}
