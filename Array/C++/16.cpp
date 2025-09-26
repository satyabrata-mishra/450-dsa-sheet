#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = prices[0], profit = 0, n = prices.size();
        for (int i = 1; i < n; i++)
        {
            if (prices[i] < buy)
                buy = prices[i];
            else if (prices[i] - buy > profit)
                profit = prices[i] - buy;
        }
        return profit;
    }
};
int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << "\n";
    prices = {7, 6, 4, 3, 1};
    cout << sol.maxProfit(prices) << "\n";
    return 0;
}
