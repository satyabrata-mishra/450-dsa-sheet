#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findMinDiff(vector<int> a, int m)
    {
        sort(a.begin(), a.end());
        int n = a.size(), ans = INT32_MAX;
        int left = 0, right = m - 1;
        while (right < n)
        {
            ans = min(ans, a[right] - a[left]);
            ++left;
            ++right;
        }

        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.findMinDiff({3, 4, 1, 9, 56, 7, 9, 12}, 5) << "\n"; // 6
    cout << sol.findMinDiff({7, 3, 2, 4, 9, 12, 56}, 3) << "\n";    // 2
    cout << sol.findMinDiff({3, 4, 1, 9, 56}, 5) << "\n";           // 55
    return 0;
}
