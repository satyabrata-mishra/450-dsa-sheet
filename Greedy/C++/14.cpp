#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    long long int findMaxProduct(vector<int> arr)
    {
        int n = arr.size(), mod = 1000000007;
        if (n == 1)
        {
            return arr[0];
        }
        int product = 1, countNeg = 0, countZeros = 0, maxNeg = INT32_MIN;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] == 0)
            {
                ++countZeros;
                continue;
            }
            if (arr[i] < 0)
            {
                ++countNeg;
                maxNeg = max(maxNeg, arr[i]);
            }
            product = (product * arr[i]) % mod;
        }
        if (countZeros == n)
            return 0;
        if (countNeg % 2 == 1)
        {
            if (countNeg == 1 && countZeros + countNeg == n)
                return 0;
            product /= maxNeg;
        }
        return product % mod;
    }
};
int main()
{
    Solution sol;
    cout << sol.findMaxProduct({-1, 0, -2, 4, 3}) << "\n"; // 24
    cout << sol.findMaxProduct({-1, 0}) << "\n";           // 0
    cout << sol.findMaxProduct({5}) << "\n";               // 5
    cout << sol.findMaxProduct({-1}) << "\n";              // -1
    return 0;
}
