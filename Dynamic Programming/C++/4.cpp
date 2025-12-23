#include <iostream>
#include <vector>
using namespace std;
class Solution
{

public:
    int prefixStrings(int N)
    {
        int mod = 1000000007;
        vector<long long int> dp(N + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += ((dp[j] % mod) * (dp[i - j - 1] % mod)) % mod;
            }
        }
        return dp[N] % mod;
    }
};

int main()
{
    Solution sol;
    cout << sol.prefixStrings(2) << "\n";  // 2
    cout << sol.prefixStrings(3) << "\n";  // 5
    cout << sol.prefixStrings(19) << "\n"; // 767263183
    cout << sol.prefixStrings(20) << "\n"; // 564120378
    cout << sol.prefixStrings(65) << "\n"; // 887145589
    return 0;
}
