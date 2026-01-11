#include <vector>
#include <iostream>
using namespace std;
class Solution
{
private:
    int medianOfTwo(vector<int> nums1, vector<int> nums2, bool toogle)
    {
        int size1 = nums1.size(), size2 = nums2.size();
        int low = min(nums1[0], nums2[0]), high = max(nums1[size1 - 1], nums2[size2 - 1]), target = (size1 + size2) / 2;
        while (low < high)
        {
            int mid = low + (high - low) / 2, count = 0;
            for (int i : nums1)
            {
                if (i <= mid)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            for (int i : nums2)
            {
                if (i <= mid)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            if (toogle && count < target)
            {
                low = mid + 1;
            }
            else if (!toogle && count <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
    double median(vector<int> &nums)
    {
        int n = nums.size();
        if (n % 2 == 0)
        {
            return ((double)nums[n / 2] + (double)nums[(n / 2 - 1)]) / 2;
        }
        return nums[n / 2];
    }

public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2)
    {
        int size1 = nums1.size(), size2 = nums2.size();
        if (size1 == 0)
        {
            return median(nums2);
        }
        if (size2 == 0)
        {
            return median(nums1);
        }
        if ((size1 + size2) % 2 != 0)
        {
            return (double)medianOfTwo(nums1, nums2, false);
        }
        return (((double)medianOfTwo(nums1, nums2, true) + (double)medianOfTwo(nums1, nums2, false)) / 2);
    }
};
int main()
{
    Solution sol;
    cout << sol.findMedianSortedArrays({1, 3}, {2}) << "\n";      // 2.00000
    cout << sol.findMedianSortedArrays({1, 2}, {3, 4}) << "\n";   // 2.50000
    cout << sol.findMedianSortedArrays({1, 2, 3, 4}, {}) << "\n"; // 1
    cout << sol.findMedianSortedArrays({}, {1, 2, 3, 4}) << "\n"; // 1
    return 0;
}
