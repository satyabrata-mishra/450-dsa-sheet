#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int countPS(string &s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j] + dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }
            }
        }
        return dp[0][n - 1];
    }
};
int main()
{
    Solution sol;
    string s = "abcd";
    cout << sol.countPS(s) << "\n";
    s = "aab";
    cout << sol.countPS(s) << "\n";
    s = "b";
    cout << sol.countPS(s) << "\n";
    s = "zvquhctuvpdcumqtvdjvzbodockbic";
    cout << sol.countPS(s) << "\n";
    return 0;
}
