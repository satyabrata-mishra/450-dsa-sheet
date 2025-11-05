#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    bool helper(vector<int> arr, int n, int k, int maxPages)
    {
        int sum = 0, studentsRequired = 1;
        for (int i : arr)
        {
            if (sum + i > maxPages)
            {
                ++studentsRequired;
                sum = i;
                if (studentsRequired > k)
                {
                    return false;
                }
            }
            else
            {
                sum += i;
            }
        }
        return true;
    }

public:
    int findPages(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k > n)
        {
            return -1;
        }
        int low = INT32_MIN, high = 0, result = -1;
        for (int i : arr)
        {
            low = max(low, i);
            high += i;
        }
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (helper(arr, n, k, mid) == true)
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return result;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << sol.findPages(arr, k) << "\n";
    arr = {15, 17, 20};
    k = 5;
    cout << sol.findPages(arr, k) << "\n";
    return 0;
}
