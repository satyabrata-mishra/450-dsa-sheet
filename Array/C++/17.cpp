#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    vector<vector<int>> getPairs(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        set<vector<int>> set;
        int i = 0, j = arr.size() - 1;
        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (sum == 0)
            {
                set.insert({arr[i], arr[j]});
                ++i;
                --j;
            }
            else if (sum < 0)
            {
                ++i;
            }
            else
            {
                --j;
            }
        }
        vector<vector<int>> ans;
        for (vector<int> i : set)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    vector<vector<int>> ans = sol.getPairs(arr);
    for (vector<int> i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    arr = {-8, -10, -10, -10, 10, 6, 1, 10};
    ans = sol.getPairs(arr);
    for (vector<int> i : ans)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
