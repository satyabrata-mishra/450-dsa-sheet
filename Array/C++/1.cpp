#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    pair<int, int> getMinMax(vector<int> arr)
    {
        int minVal = INT32_MAX, maxVal = INT32_MIN;
        for (int i : arr)
        {
            minVal = min(minVal, i);
            maxVal = max(maxVal, i);
        }
        return {minVal, maxVal};
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {1, 345, 234, 21, 56789};
    pair<int, int> ans = sol.getMinMax(arr);
    cout << ans.first << " " << ans.second;
    return 0;
}
