#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int lcs(string &s1, string &s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n1][n2];
    }
};
int main()
{
    Solution sol;
    string s1 = "ABCDGH", s2 = "AEDFHR";
    cout << sol.lcs(s1, s2) << "\n";
    s1 = "ABC", s2 = "AC";
    cout << sol.lcs(s1, s2) << "\n";
    s1 = "XYZW", s2 = "XYWZ";
    cout << sol.lcs(s1, s2) << "\n";
    return 0;
}
