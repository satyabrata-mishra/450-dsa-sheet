#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0, n = prices.size();
        for (int i = 1; i < n; i++)
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        return profit;
    }
};
int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << "\n";
    prices = {1, 2, 3, 4, 5};
    cout << sol.maxProfit(prices) << "\n";
    prices = {7, 6, 4, 3, 1};
    cout << sol.maxProfit(prices) << "\n";
    return 0;
}
