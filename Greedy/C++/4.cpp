#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Knapsack
{
    int val, wt;
    double profit;
    Knapsack(int val, int wt, double profit)
    {
        this->val = val;
        this->wt = wt;
        this->profit = profit;
    }
};
class Solution
{
public:
    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        vector<Knapsack> list;
        int n = val.size();
        for (int i = 0; i < n; i++)
        {
            list.emplace_back(val[i], wt[i], (double)val[i] / wt[i]);
        }
        sort(list.begin(), list.end(), [](Knapsack &a, Knapsack &b)
             { return a.profit > b.profit; });
        double ans = 0;
        for (Knapsack i : list)
        {
            if (capacity > i.wt)
            {
                capacity -= i.wt;
                ans += i.val;
            }
            else
            {
                ans += i.profit * capacity;
                capacity = 0;
                break;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> val = {60, 100, 120}, wt = {10, 20, 30};
    int capacity = 50;
    cout << sol.fractionalKnapsack(val, wt, capacity) << "\n"; // 240
    val = {60, 100};
    wt = {10, 20};
    capacity = 50;
    cout << sol.fractionalKnapsack(val, wt, capacity) << "\n"; // 160
    val = {10, 20, 30};
    wt = {5, 10, 15};
    capacity = 100;
    cout << sol.fractionalKnapsack(val, wt, capacity) << "\n"; // 60
    return 0;
}
