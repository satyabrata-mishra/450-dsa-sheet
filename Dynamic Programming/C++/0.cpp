#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int count(vector<int> coins, int sum)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= sum; i++)
        {
            dp[0][i] = (i % coins[0] == 0 ? 1 : 0);
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (coins[i] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
                }
            }
        }
        return dp[n - 1][sum];
    }
};
int main()
{
    Solution sol;
    cout << sol.count({1, 2, 3}, 4) << "\n";     // 4
    cout << sol.count({2, 5, 3, 6}, 10) << "\n"; // 5
    cout << sol.count({5, 10}, 3) << "\n";       // 0
    return 0;
}
