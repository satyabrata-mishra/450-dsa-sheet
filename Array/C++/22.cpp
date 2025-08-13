#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &arr)
    {
        int n = arr.size(), maxProd = arr[0], minProd = arr[0], ans = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < 0)
                swap(maxProd, minProd);
            maxProd = max(arr[i], (maxProd * arr[i]));
            minProd = min(arr[i], (minProd * arr[i]));
            ans = max(maxProd, ans);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> arr = {-2, 6, -3, -10, 0, 2};
    cout << sol.maxProduct(arr) << "\n";
    arr = {-1, -3, -10, 0, 6};
    cout << sol.maxProduct(arr) << "\n";
    arr = {2, 3, 4};
    cout << sol.maxProduct(arr) << "\n";
    return 0;
}
