#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    int findPages(vector<int> arr, int k)
    {
        int n = arr.size();
        if (k > n)
            return -1;
        int left = *max_element(arr.begin(), arr.end());
        int right = accumulate(arr.begin(), arr.end(), 0);
        int ans = right;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int currSum = 0, requiredStudent = 1;
            for (int i = 0; i < n; i++)
            {
                if (currSum + arr[i] > mid)
                {
                    ++requiredStudent;
                    currSum = arr[i];
                }
                else
                {
                    currSum += arr[i];
                }
            }
            if (requiredStudent <= k)
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.findPages({12, 34, 67, 90}, 2) << "\n"; // 113
    cout << sol.findPages({15, 17, 20}, 5) << "\n";     // -1
    return 0;
}
