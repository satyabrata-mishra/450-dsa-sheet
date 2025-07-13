#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    int helper(vector<int> &arr, int x, bool toogle)
    {
        int low = 0, high = arr.size() - 1, ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x)
            {
                ans = mid;
                if (toogle)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else if (arr[mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }

public:
    vector<int> find(vector<int> &arr, int x)
    {
        return {helper(arr, x, true), helper(arr, x, false)};
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    vector<int> ans = sol.find(arr, 5);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
