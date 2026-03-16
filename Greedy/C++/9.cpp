#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> minMaxCandy(vector<int> prices, int k)
    {
        sort(prices.begin(), prices.end());
        int minCost = 0, maxCost = 0, n = prices.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            minCost += prices[left];
            ++left;
            right -= k;
        }
        left = 0;
        right = n - 1;
        while (left <= right)
        {
            maxCost += prices[right];
            right--;
            left += k;
        }
        return {minCost, maxCost};
    }
};
int main()
{
    Solution sol;
    vector<int> ans = sol.minMaxCandy({3, 2, 1, 4}, 2);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    ans = sol.minMaxCandy({3, 2, 1, 4, 5}, 4);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
