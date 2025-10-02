#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        map<int, int> times;
        unordered_map<int, vector<pair<int, int>>> jobs;
        for (auto i = 0; i < startTime.size(); ++i)
        {
            times[startTime[i]] = 0;
            jobs[startTime[i]].push_back({endTime[i], profit[i]});
        }
        int max_profit = 0;
        for (auto it = rbegin(times); it != rend(times); ++it)
        {
            for (auto job : jobs[it->first])
            {
                auto it = times.lower_bound(job.first);
                max_profit = max(max_profit, (it == end(times) ? 0 : it->second) + job.second);
            }
            it->second = max_profit;
        }
        return max_profit;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> startTime = {1, 2, 3, 3}, endTime = {3, 4, 5, 6}, profit = {50, 10, 40, 70};
    cout << sol.jobScheduling(startTime, endTime, profit) << "\n"; // 120
    startTime = {1, 2, 3, 4, 6}, endTime = {3, 5, 10, 6, 9}, profit = {20, 20, 100, 70, 60};
    cout << sol.jobScheduling(startTime, endTime, profit) << "\n"; // 150
    startTime = {1, 1, 1}, endTime = {2, 3, 4}, profit = {5, 6, 4};
    cout << sol.jobScheduling(startTime, endTime, profit) << "\n"; // 6
    return 0;
}
