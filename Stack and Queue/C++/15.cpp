#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> &arr)
    {
        sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });
        vector<vector<int>> ans;
        int startTime = arr[0][0], finishTime = arr[0][1], n = arr.size();
        for (int i = 1; i < n; i++)
        {
            if (arr[i][0] <= finishTime)
                finishTime = max(finishTime, arr[i][1]);
            else
            {
                ans.push_back({startTime, finishTime});
                startTime = arr[i][0];
                finishTime = arr[i][1];
            }
        }

        ans.push_back({startTime, finishTime});
        return ans;
    }
};
int main()
{
    vector<vector<int>> arr = {{1, 2}, {2, 13}};
    Solution sol;
    arr = sol.mergeOverlap(arr);
    for (vector<int> i : arr)
    {
        for (int j : i)
            cout << j << " ";
        cout << "\n";
    }
    return 0;
}
