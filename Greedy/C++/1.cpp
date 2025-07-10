#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Job
{
    int profit, deadline;
    Job(int profit, int deadline)
    {
        this->profit = profit;
        this->deadline = deadline;
    }
};
class Solution
{
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
    {
        vector<Job> jobs;
        int n = deadline.size(), maxDeadline = 0;
        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, deadline[i]);
            jobs.emplace_back(profit[i], deadline[i]);
        }
        sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
             { return a.profit > b.profit; });
        vector<int> hash(maxDeadline, 0);
        int maxJob = 0, maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = jobs[i].deadline - 1; j >= 0; j--)
            {
                if (hash[j] == 0)
                {
                    ++maxJob;
                    maxProfit += jobs[i].profit;
                    hash[j] = -1;
                    break;
                }
            }
        }
        return {maxJob, maxProfit};
    }
};
int main()
{
    vector<int> deadline = {4, 1, 1, 1}, profit = {20, 10, 40, 30};
    Solution sol;
    vector<int> ans = sol.jobSequencing(deadline, profit);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
