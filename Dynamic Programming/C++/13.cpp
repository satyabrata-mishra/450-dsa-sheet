#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int lcs(string &s1, string &s2)
    {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] != s2[j - 1])
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                else
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
            }
        }
        return dp[n1][n2];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string str1 = "ABCDGH", str2 = "AEDFHR";
    cout << sol.lcs(str1, str2) << "\n"; // 3
    str1 = "ABC";
    str2 = "AC";
    cout << sol.lcs(str1, str2) << "\n"; // 2
    str1 = "XYZW";
    str2 = "XYWZ";
    cout << sol.lcs(str1, str2) << "\n"; // 3
    return 0;
}
