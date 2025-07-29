#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int getMinDiff(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int ans = arr[n - 1] - arr[0], small = arr[0] + k, large = arr[n - 1] - k;
        for (int i = 0; i < n - 1; i++)
        {
            int mini = min(small, arr[i + 1] - k);
            int maxi = max(large, arr[i] + k);
            if (mini < 0)
                continue;
            ans = min(ans, maxi - mini);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {1, 5, 8, 10};
    cout << sol.getMinDiff(arr, 2) << "\n";
    arr = {3, 9, 12, 16, 20};
    cout << sol.getMinDiff(arr, 3) << "\n";
    return 0;
}
