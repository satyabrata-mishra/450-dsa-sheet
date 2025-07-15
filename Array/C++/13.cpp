#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });
        vector<vector<int>> ans;
        int start = intervals[0][0], finish = intervals[0][1], n = intervals.size();
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= finish)
            {
                finish = max(finish, intervals[i][1]);
            }
            else
            {
                ans.push_back({start, finish});
                start = intervals[i][0];
                finish = intervals[i][1];
            }
        }
        ans.push_back({start, finish});
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    vector<vector<int>> arr = {{1, 4}, {2, 3}};
    Solution sol;
    arr = sol.merge(arr);
    for (vector<int> i : arr)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
