#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    bool subsetSumToK(int n, int target, vector<int> &arr)
    {
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (arr[i] <= j)
                {
                    take = dp[i - 1][j - arr[i]];
                }
                dp[i][j] = take | notTake;
            }
        }
        return dp[n - 1][target];
    }

public:
    bool equalPartition(vector<int> arr)
    {
        int n = arr.size(), target = 0;
        for (int i : arr)
        {
            target += i;
        }
        if (target % 2 != 0)
        {
            return false;
        }
        target /= 2;
        return subsetSumToK(n, target, arr);
    }
};
int main()
{
    Solution sol;
    cout << sol.equalPartition({1, 5, 11, 5}) << "\n";
    cout << sol.equalPartition({1, 3, 5}) << "\n";
    return 0;
}
