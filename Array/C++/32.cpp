#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSwap(vector<int> arr, int k)
    {
        int count = 0, n = arr.size();
        for (int i : arr)
        {
            if (i <= k)
            {
                ++count;
            }
        }
        int ans = 0;
        for (int i = 0; i < count; i++)
        {
            if (arr[i] > k)
            {
                ++ans;
            }
        }
        int right = 0, left = count;
        while (left < n)
        {
            int temp = ans;
            if (arr[right] > k)
            {
                --temp;
            }
            if (arr[left] > k)
            {
                ++temp;
            }
            ++right;
            ++left;
            ans = min(ans, temp);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.minSwap({2, 1, 5, 6, 3}, 3) << "\n";       // 1
    cout << sol.minSwap({2, 7, 9, 5, 8, 7, 4}, 6) << "\n"; // 2
    cout << sol.minSwap({2, 4, 5, 3, 6, 1, 8}, 6) << "\n"; // 0
    return 0;
}
