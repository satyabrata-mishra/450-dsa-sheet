#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool hasTripletSum(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum == target)
                    return true;
                else if (sum < target)
                    ++left;
                else
                    --right;
            }
        }
        return false;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 4, 45, 6, 10, 8};
    int target = 13;
    cout << sol.hasTripletSum(nums, target) << "\n";
    nums = {1, 2, 4, 3, 6, 7};
    target = 10;
    cout << sol.hasTripletSum(nums, target) << "\n";
    nums = {40, 20, 10, 3, 6, 7};
    target = 24;
    cout << sol.hasTripletSum(nums, target) << "\n";
    return 0;
}
