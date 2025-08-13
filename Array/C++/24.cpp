#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int candidate1 = -1, candidate2 = -1, count1 = 0, count2 = 0;
        for (int i : nums)
        {
            if (i == candidate1)
            {
                count1++;
            }
            else if (i == candidate2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                candidate1 = i;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                candidate2 = i;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i : nums)
        {
            if (i == candidate1)
            {
                count1++;
            }
            else if (i == candidate2)
            {
                count2++;
            }
        }
        int target = floor(nums.size() / 3.0);
        vector<int> ans;
        if (count1 > target)
            ans.push_back(candidate1);
        if (count2 > target)
            ans.push_back(candidate2);
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {3, 2, 3};
    nums = sol.majorityElement(nums);
    for (int i : nums)
        cout << i << " ";
    cout << "\n";
    nums = {1};
    nums = sol.majorityElement(nums);
    for (int i : nums)
        cout << i << " ";
    cout << "\n";
    nums = {2, 1, 1, 3, 1, 4, 5, 6};
    nums = sol.majorityElement(nums);
    for (int i : nums)
        cout << i << " ";
    cout << "\n";
    return 0;
}
