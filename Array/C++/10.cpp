#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0], fast = nums[0], n = nums.size();
        while (fast <= n + 1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
            {
                break;
            }
        }
        int slow1 = nums[0];
        while (slow != slow1)
        {
            slow = nums[slow];
            slow1 = nums[slow1];
        }
        return slow;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {1, 3, 4, 2, 2};
    cout << sol.findDuplicate(arr) << "\n";
    arr = {3, 1, 3, 4, 2};
    cout << sol.findDuplicate(arr) << "\n";
    arr = {3, 3, 3, 3, 3};
    cout << sol.findDuplicate(arr) << "\n";
    return 0;
}
