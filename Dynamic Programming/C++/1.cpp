#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                if (wt[i - 1] <= w)
                {
                    // Option to take or not take the item
                    dp[i][w] = max(dp[i - 1][w],
                                   val[i - 1] + dp[i - 1][w - wt[i - 1]]);
                }
                else
                {
                    // Can't take the item
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        return dp[n][W];
    }
};
int main()
{
    Solution sol;
    vector<int> val = {1, 2, 3}, wt = {4, 5, 1};
    cout << sol.knapsack(4, val, wt) << "\n"; // 3
    val = {1, 2, 3};
    wt = {4, 5, 6};
    cout << sol.knapsack(3, val, wt) << "\n"; // 0
    val = {10, 40, 30, 50};
    wt = {5, 4, 2, 3};
    cout << sol.knapsack(5, val, wt) << "\n"; // 80
    return 0;
}
