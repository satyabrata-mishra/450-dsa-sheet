#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> map;
        for (int i : arr)
        {
            map[i]++;
        }
        int ans = -1;
        for (pair<int, int> i : map)
        {
            if (i.second > n / 2)
            {
                ans = i.first;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {1, 1, 2, 1, 3, 5, 1};
    cout << sol.majorityElement(arr) << "\n";
    arr = {7};
    cout << sol.majorityElement(arr) << "\n";
    arr = {2, 13};
    cout << sol.majorityElement(arr) << "\n";
}
