#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSubset(vector<int> arr)
    {
        sort(arr.begin(), arr.end(), greater<int>());
        int n = arr.size(), totalsum = 0;
        for (int i : arr)
        {
            totalsum += i;
        }
        int currSum = 0;
        for (int i = 0; i < n; i++)
        {
            currSum += arr[i];
            if (currSum > totalsum / 2)
            {
                return i + 1;
            }
        }
        return -1;
    }
};
int main()
{
    Solution sol;
    cout << sol.minSubset({2, 17, 7, 3}) << "\n";    // 1
    cout << sol.minSubset({20, 12, 18, 4}) << "\n";  // 2
    cout << sol.minSubset({1, 1, 1, 1, 10}) << "\n"; // 1
    return 0;
}
