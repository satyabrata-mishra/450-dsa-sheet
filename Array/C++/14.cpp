#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // next_permutation(nums.begin(), nums.end());//Already avaliable STL library
        int n = nums.size();
        int breakPoint = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                breakPoint = i;
                break;
            }
        }
        if (breakPoint == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > breakPoint; i--)
        {
            if (nums[i] > nums[breakPoint])
            {
                swap(nums[i], nums[breakPoint]);
                break;
            }
        }
        reverse(nums.begin() + breakPoint + 1, nums.end());
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1, 1, 5};
    sol.nextPermutation(nums);
    for (int i : nums)
        cout << i << " ";
    return 0;
}
