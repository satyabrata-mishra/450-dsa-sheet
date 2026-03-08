#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    long long maxSum(vector<int> a)
    {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<long> permutation(n, 0);
        int i = 0, left = 0, right = n - 1;
        while (left < right)
        {
            permutation[i] = a[left];
            permutation[i + 1] = a[right];
            ++left;
            --right;
            i += 2;
        }
        if (n % 2 != 0)
        {
            permutation[n - 1] = a[n / 2];
        }
        long long ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans += abs(permutation[i + 1] - permutation[i]);
        }
        ans += abs(permutation[n - 1] - permutation[0]);
        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.maxSum({1, 2, 4, 8}) << "\n"; // 40
    return 0;
}
