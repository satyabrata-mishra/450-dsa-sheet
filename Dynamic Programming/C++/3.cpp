#include <iostream>
#include <vector>
using namespace std;
class Solution
{

public:
    int permutationCoeff(int n, int k)
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        int mod = 1000000007;
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                dp[i][j] = (dp[i - 1][j] + (j * dp[i - 1][j - 1]) % mod) % mod;
            }
        }
        return dp[n][k];
    }
};
int main()
{
    Solution sol;
    cout << sol.permutationCoeff(10, 2) << "\n";
    cout << sol.permutationCoeff(10, 3) << "\n";
    cout << sol.permutationCoeff(14, 12) << "\n";        // 589145299
    cout << sol.permutationCoeff(100000, 16348) << "\n"; // 478193331
    return 0;
}
