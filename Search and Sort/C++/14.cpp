#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findSubarray(vector<int> &arr)
    {
        unordered_map<int, int> map;
        map[0] = 1;
        int ans = 0, sum = 0;
        for (int i : arr)
        {
            sum += i;
            if (map.find(sum) != map.end())
                ans += map[sum];
            map[sum]++;
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {0, 0, 5, 5, 0, 0};
    cout << sol.findSubarray(arr) << "\n";
    arr = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    cout << sol.findSubarray(arr) << "\n";
    arr = {0};
    cout << sol.findSubarray(arr) << "\n";
    return 0;
}
