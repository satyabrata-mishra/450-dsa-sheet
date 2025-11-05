#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int startStation(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int totalGas = 0, totalCost = 0;
        int startPoint = 0, netGas = 0;
        for (int i = 0; i < n; i++)
        {
            totalGas += gas[i];
            totalCost += cost[i];
            netGas += (gas[i] - cost[i]);
            if (netGas < 0)
            {
                startPoint = i + 1;
                netGas = 0;
            }
        }
        if (totalCost > totalGas)
        {
            return -1;
        }
        return startPoint;
    }
};
int main()
{
    Solution sol;
    vector<int> gas = {4, 5, 7, 4}, cost = {6, 6, 3, 5};
    cout << sol.startStation(gas, cost) << "\n";
    gas = {3, 9};
    cost = {7, 6};
    cout << sol.startStation(gas, cost) << "\n";
    return 0;
}
