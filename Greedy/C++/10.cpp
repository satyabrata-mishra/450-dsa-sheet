#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> minCashFlow(vector<vector<int>> transaction, int n)
    {
        vector<int> net(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                net[i] -= transaction[i][j];
                net[j] += transaction[i][j];
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < n; i++)
        {
            if (net[i] > 0)
            {
                maxHeap.push({net[i], i});
            }
            else
            {
                minHeap.push({net[i], i});
            }
        }
        vector<vector<int>> ans(n, vector<int>(n, 0));
        while (minHeap.empty() == false && maxHeap.empty() == false)
        {
            pair<int, int> debitor = minHeap.top();
            minHeap.pop();
            pair<int, int> creditor = maxHeap.top();
            maxHeap.pop();
            int netflow = min(creditor.first, -debitor.first);
            ans[debitor.second][creditor.second] = netflow;
            debitor.first += netflow;
            creditor.first -= netflow;

            if (debitor.first < 0)
                minHeap.push(debitor);

            if (creditor.first > 0)
                maxHeap.push(creditor);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> arr = {{0, 100, 0}, {0, 0, 100}, {100, 0, 0}};
    arr = sol.minCashFlow(arr, arr.size()); // {{0,0,0},{0,0,0},{0,0,0}}
    for (vector<int> i : arr)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    arr = {{0, 100, 0}, {0, 0, 200}, {0, 0, 0}};
    arr = sol.minCashFlow(arr, arr.size()); // {0,0,100},{0,0,100},{0,0,0}
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
