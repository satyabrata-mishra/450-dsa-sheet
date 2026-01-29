#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> nums)
    {
        int n = nums.size(), ans = INT32_MAX, left = 0, right = 0;
        long sum = 0;
        while (right < n)
        {
            sum += nums[right];
            while (sum >= target)
            {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                ++left;
            }
            ++right;
        }
        return (ans == INT32_MAX ? 0 : ans);
    }
};
int main()
{
    Solution sol;
    cout << sol.minSubArrayLen(7, {2, 3, 1, 2, 4, 3}) << "\n";        // 2
    cout << sol.minSubArrayLen(4, {1, 4, 4}) << "\n";                 // 1
    cout << sol.minSubArrayLen(11, {1, 1, 1, 1, 1, 1, 1, 1}) << "\n"; // 0
    return 0;
}
