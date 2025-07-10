#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int activitySelection(vector<int> &start, vector<int> &finish)
    {
        int n = start.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++)
        {
            jobs.push_back({start[i], finish[i]});
        }
        sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int ans = 1, deadline = jobs[0][1];
        for (int i = 1; i < n; i++)
        {
            if (deadline < jobs[i][0])
            {
                ++ans;
                deadline = jobs[i][1];
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5}, finish = {2, 4, 6, 7, 9, 9};
    Solution sol;
    cout << sol.activitySelection(start, finish);
    return 0;
}
