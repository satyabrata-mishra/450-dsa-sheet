#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int nCr(int n, int r)
    {
        vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= r; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        return dp[n][r];
    }
};
int main()
{
    Solution sol;
    cout << sol.nCr(5, 2) << "\n";
    cout << sol.nCr(2, 4) << "\n";
    cout << sol.nCr(5, 0) << "\n";
    return 0;
}
