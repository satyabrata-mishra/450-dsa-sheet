#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int binarySearch(vector<int> arr, int k, bool toogle)
    {
        int ans = -1, left = 0, right = arr.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == k)
            {
                ans = mid;
                if (toogle)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else if (arr[mid] < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }

public:
    vector<int> find(vector<int> &arr, int k)
    {
        vector<int> ans;
        ans.push_back(binarySearch(arr, k, true));
        ans.push_back(binarySearch(arr, k, false));
        return ans;
    }
};
int main()
{
    vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    Solution sol;
    arr = sol.find(arr, 5);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    arr = {1, 3, 5, 5, 5, 5, 7, 123, 125};
    arr = sol.find(arr, 7);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
