#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left(n, 0), right(n, 0);
        left[0] = arr[0];
        for (int i = 1; i < n; i++)
            left[i] = max(left[i - 1], arr[i]);
        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1], arr[i]);
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int temp = min(left[i - 1], right[i + 1]);
            if (temp > arr[i])
                ans += temp - arr[i];
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {3, 0, 1, 0, 4, 0, 2};
    cout << sol.maxWater(arr) << "\n";
    arr = {3, 0, 2, 0, 4};
    cout << sol.maxWater(arr) << "\n";
    arr = {1, 2, 3, 4};
    cout << sol.maxWater(arr) << "\n";
    arr = {2, 1, 5, 3, 1, 0, 4};
    cout << sol.maxWater(arr) << "\n";
    return 0;
}
