#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubarraySum(vector<int> &arr)
    {
        int ans = INT32_MIN, sum = 0;
        for (int i : arr)
        {
            sum += i;
            ans = max(ans, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> list = {2, 3, -8, 7, -1, 2, 3};
    cout << sol.maxSubarraySum(list) << "\n";
    list = {-2, -4};
    cout << sol.maxSubarraySum(list) << "\n";
    list = {5, 4, 1, 7, 8};
    cout << sol.maxSubarraySum(list) << "\n";
    return 0;
}
