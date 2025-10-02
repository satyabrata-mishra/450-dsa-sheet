#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    long long findMinSum(vector<int> &a, vector<int> &b, int n)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += abs(a[i] - b[i]);
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<int> a = {4, 1, 8, 7}, b = {2, 3, 6, 5};
    cout << sol.findMinSum(a, b, a.size()) << "\n";
    a = {4, 1, 2}, b = {2, 4, 1};
    cout << sol.findMinSum(a, b, a.size()) << "\n";
    return 0;
}
