#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxStop(int plat, vector<vector<int>> &trains)
    {
        vector<vector<pair<int, int>>> platforms(plat + 1);
        for (vector<int> i : trains)
        {
            platforms[i[2]].push_back({i[0], i[1]});
        }
        int ans = 0;
        for (int i = 1; i <= plat; i++)
        {
            vector<pair<int, int>> currPlatform = platforms[i];
            sort(currPlatform.begin(), currPlatform.end(), [](pair<int, int> a, pair<int, int> b)
                 { return a.second < b.second; });
            int lastDept = -1;
            for (pair<int, int> i : currPlatform)
            {
                if (lastDept <= i.first)
                {
                    lastDept = i.second;
                    ++ans;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> trains = {{1000, 1030, 1}, {1010, 1030, 1}, {1000, 1020, 2}, {1030, 1230, 2}, {1200, 1230, 3}, {900, 1005, 1}};
    cout << sol.maxStop(3, trains) << "\n";
    return 0;
}
