#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int findMaxSum(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for (int i = 2; i < n; i++)
        {
            int pick = arr[i] + dp[i - 2];
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[n - 1];
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {5, 3, 4, 11, 2}; // 16
    cout << sol.findMaxSum(arr) << "\n";
    arr = {6, 7, 1, 3, 8, 2, 4}; // 19
    cout << sol.findMaxSum(arr) << "\n";
    return 0;
}
