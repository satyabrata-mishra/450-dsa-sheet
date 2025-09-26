#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int lcsOf3(string &s1, string &s2, string &s3)
    {
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
};
int main()
{
    Solution sol;
    string s1 = "geeks", s2 = "geeksfor", s3 = "geeksforgeeks";
    cout << sol.lcsOf3(s1, s2, s3) << "\n";
    s1 = "abcd1e2";
    s2 = "bc12ea";
    s3 = "bd1ea";
    cout << sol.lcsOf3(s1, s2, s3) << "\n";
    return 0;
}
